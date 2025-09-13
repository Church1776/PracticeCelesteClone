#!/bin/bash

##### ---NON-POSIX Mode Enforced--- #####
if [ -z "$BASH_VERSION" ]; then
    exec bash "$0" "$@"
fi

##### ---Build Initialized--- #####
echo "Initializing..."

### --Prep Variables-- ###
AUTO=0; ARCHIVE_BUILD=0; CLEAN_BUILD=0; COMP_ERRORS=0
DLL_MODE=0; LIB_MODE=0; PCH_MODE=0; NOLINK=0

### --Source files/flags for the build-- ###
DEBUG_FLAGS=""
CPP_VERSION="-std=c++23"
CPPEXP="-lstdc++exp"             
SRC_CORE="main.cpp base_lib.cpp platform_win32.cpp input.cpp gl_renderer.cpp"
SRC_DLLS=""
SRC_LIBS=""
SRC_PCHS=""
FILE_EXT=""
DLL_FILE_NAME="shared_lib.dll"
LIB_FILE_NAME="static_lib.a"
LINKER_LIBS="-lgdi32 -lopengl32"
EXE_FILE_NAME="CelesteClone.exe"
TIMESTAMP=$(date +%Y-%m-%d_%H.%M.%S)

### --Preparing directory paths for processing-- ###
PROJECT_DIR="$1"; shift
ARCHIVE_DIR="$PROJECT_DIR/archive"
SOURCE_DIR="$PROJECT_DIR/source"    ## <-- For the human-readable code
BUILD_DIR="$PROJECT_DIR/build"      ## <-- For the compiled object files
BIN_DIR="$PROJECT_DIR/bin"          ## <-- For exe, dll, lib, pch output

### --Locate Source Files and Include Directories for Building-- ###
echo "Sourcing..."
CORE_BUILD=$(find "$PROJECT_DIR" $(printf -- '-name %s -o ' $SRC_CORE) -false)
SHRD_BUILD=$(find "$PROJECT_DIR" $(printf -- '-name %s -o ' $SRC_DLLS) -false)
STTC_BUILD=$(find "$PROJECT_DIR" $(printf -- '-name %s -o ' $SRC_LIBS) -false)
PCHD_BUILD=$(find "$PROJECT_DIR" $(printf -- '-name %s -o ' $SRC_PCHS) -false)
INCLUDE_FLAGS=$(find "$PROJECT_DIR" -type d -exec printf ' -I%s' {} +)

### --Locate Compiler & Linker-- ###
GXX=$(which g++)
LD_PATTERN=$(g++ -print-prog-name=ld | sed 's|/|\\/|g')   

##### ---Helper: Compile step--- #####
compile_file() {
    local src="$1" mode="$2" outdir="$3"
    rel_path="${src#$SOURCE_DIR/}"
    obj="$BUILD_DIR/$outdir/${rel_path%.cpp}.o"
    mkdir -p "$(dirname "$obj")"
    "$GXX" $CPP_VERSION $INCLUDE_FLAGS -c $DEBUG_FLAGS "$src" -o "$obj" 2>&1 | sed -E \
        -e 's|C:/[^[:space:]]*[/]||g' \
        -e 's/candidate:/\n candidate:/g' \
        -e 's|^[[:space:]]*||'
    if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
        COMP_ERRORS=$((COMP_ERRORS + 1))
    fi
    echo "$obj"
}

##### ---Helper: Link step--- #####
link_target() {
    local mode="$1" target="$2" objs="$3"
    case "$mode" in
        exe)
            echo "Creating EXE_FILE_NAME $target..."
            eval "$GXX -o \"$BIN_DIR/$target\" $objs $LINKER_LIBS $CPPEXP" 2>&1 | sed -E \
                -e "s|$LD_PATTERN:||g" \
                -e "s|[^[:space:]]*\.o:||g" \
                -e 's|C:/[^[:space:]]*[/]||g' \
                -e "s|$SOURCE_DIR/||g" \
                -e 's|\(.[^[:space:]]*[]]|(|'
            ;;
        dll)
            echo "Creating Dynamic Library $target..."
            eval "$GXX -shared -o \"$BIN_DIR/$target\" $objs $LINKER_LIBS $CPPEXP" 2>&1 | sed -E \
                -e "s|$LD_PATTERN:||g" \
                -e "s|[^[:space:]]*\.o:||g" \
                -e 's|C:/[^[:space:]]*[/]||g' \
                -e "s|$SOURCE_DIR/||g" \
                -e 's|\(.[^[:space:]]*[]]|(|'
            ;;
        lib)
            echo "Archiving Static Library $target..."
            ar rcs "$BIN_DIR/$target" $objs
            ;;
        pch)
            echo "Building Pre-Compiled Header $target..."
            "$GXX" $CPP_VERSION $INCLUDE_FLAGS -c $DEBUG_FLAGS "$objs" -o "$BIN_DIR/$target.gch"
            ;;
    esac
    if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
        echo "Failed linking $target."
        exit 1
    fi
}

##### ---Evaluating options specified--- #####
for arg in "$@"; do
    case "$arg" in
        auto | noauto) if [[ "$arg" == "noauto" ]]; then continue; else AUTO=1; fi ;;
        clean | noclean) if [[ "$arg" == "noclean" ]]; then continue; else CLEAN_BUILD=1; fi ;;
        archive | noarchive) if [[ "$arg" == "noarchive" ]]; then continue; else ARCHIVE_BUILD=1; CLEAN_BUILD=1; fi ;;
        link | nolink) if [[ "$arg" == "link" ]]; then continue; else NOLINK=1; fi ;;
        help | nohelp) if [[ "$arg" == "nohelp" ]]; then
                echo "I'm happy to not assist you! Have a great day!"
            else
            echo "Available arguments:"
            echo "1. auto:    <-- Autofills all files in the source directory."
            echo "2. clean:   <-- Resets build directory. Use only when you want to start from scratch."
            echo "3. archive: <-- Archives current build. Archive is not set true as default."
            echo "4. link     <-- Explicitly tells the linker to link files. Default value is true"
            echo "5. help:    <-- Displays commands for assistance."
            echo "6. dll      <-- Specifies the incoming files to be added for the creation of a dynamic link library."
            echo "7. lib      <-- Specifies the incoming files to be added for the creation of a static link library."
            echo "8. pch      <-- Specifies the incoming files to be added for the creation of a pre-compiled header."
            echo "9. no       <-- Prepend this to any commands to reverse the setting. Ex: ( nodll, noarchive )"
            exit 0
            fi
            ;;
        dll | nodll)
            if [[ "$arg" == "nodll" ]]; then
                DLL_MODE=0
            else
                if [[ $LIB_MODE -eq 1 ]]; then
                    echo "LIB mode must be false before '$arg' is called. Use the command 'nolib' to specify"
                    exit 0
                elif [[ $PCH_MODE -eq 1 ]]; then
                    echo "PCH mode must be false before '$arg' is called. Use the command 'nopch' to specify"
                    exit 0
                fi
                DLL_MODE=1
            fi
            ;;
        lib | nolib)
            if [[ "$arg" == "nolib" ]]; then
                LIB_MODE=0
            else
                if [[ $DLL_MODE -eq 1 ]]; then
                    echo "DLL mode must be false before '$arg' is called. Use the command 'nodll' to specify"
                    exit 0
                elif [[ $PCH_MODE -eq 1 ]]; then
                    echo "PCH mode must be false before '$arg' is called. Use the command 'nopch' to specify"
                    exit 0
                fi
                LIB_MODE=1
            fi
            ;;
        pch | nopch)
            if [[ "$arg" == "nopch" ]]; then
                PCH_MODE=0
            else
                if [[ $LIB_MODE -eq 1 ]]; then
                    echo "LIB mode must be false before '$arg' is called. Use the command 'nolib' to specify"
                    exit 0
                elif [[ $DLL_MODE -eq 1 ]]; then
                    echo "DLL mode must be false before '$arg' is called. Use the command 'nodll' to specify"
                    exit 0
                fi
                PCH_MODE=1
            fi
            ;;
        no)
            echo "Argument 'no' is ignored. Must be prepended. Example: nodll, nolib, nopch."
            ;;
        *=*.dll | *=*.a | *=*.exe)
            mode="${arg%%=*}"
            name="${arg#*=}"
            case "$mode" in
                exe) EXE_FILE_NAME="$name" ;;
                dll) DLL_FILE_NAME="$name" ;;
                lib) LIB_FILE_NAME="$name" ;;
            esac
            ;;
        *=*.cpp)
            mode="${arg%%=*}"    ## prefix before '='
            file="${arg#*=}"     ## file after '='
            case "$mode" in
                dll) SHRD_BUILD+=" $(find "$SOURCE_DIR" -name "$file")" ;;
                lib) STTC_BUILD+=" $(find "$SOURCE_DIR" -name "$file")" ;;
                pch) PCHD_BUILD+=" $(find "$SOURCE_DIR" -name "$file")" ;;
                exe) CORE_BUILD+=" $(find "$SOURCE_DIR" -name "$file")" ;;
            esac
            ;;
        *.cpp)
            CORE_BUILD+=" $(find "$SOURCE_DIR" -name "$arg")"
            ;;
        -*)
            echo "Grabbing debug info... \"$arg\""
            DEBUG_FLAGS+=" $arg"
            ;;
        *)
            echo "'$arg' not recognized. Argument ignored."
            ;;
    esac
done

##### ---Archive Implementation--- #####
if [[ $ARCHIVE_BUILD -eq 1 ]]; then
    if [[ ( -d $BUILD_DIR && $(ls -A "$BUILD_DIR") ) || ( -d $BIN_DIR && $(ls -A "$BIN_DIR") ) ]]; then
        ARCHIVE_DIR+="/old_build_$TIMESTAMP"
        echo "Archiving current build to $ARCHIVE_DIR..."
        mkdir -p "$ARCHIVE_DIR"
        [ -d "$BUILD_DIR" ] && cp -r "$BUILD_DIR" "$ARCHIVE_DIR/"
        [ -d "$BIN_DIR" ] && cp -r "$BIN_DIR" "$ARCHIVE_DIR/"
    else
        mkdir -p "$ARCHIVE_DIR"
        echo "Build and bin directories are empty. Nothing to archive."
        exit 0
    fi
fi

##### ---Clean Implementation--- #####
if [[ $CLEAN_BUILD -eq 1 ]]; then
    rm -rf "$BUILD_DIR"/*
    rm -rf "$BIN_DIR"/*
    echo "Previous Build Cleaned"
    exit 0
fi

##### ---Auto Fallback--- #####
if [[ $AUTO -eq 1 ]]; then
    echo "Auto mode: locating source files..."
    CORE_BUILD=$(find "$SOURCE_DIR" -name '*.cpp')
fi

##### ---Compiling and Linking--- #####
mkdir -p "$BIN_DIR"

echo "Compiling..."
EXE_OBJS=()
DLL_OBJS=()
LIB_OBJS=()
PCH_HDRS=()

for src in $CORE_BUILD; do
    obj=$(compile_file "$src" "exe" "source")
    EXE_OBJS+=("$obj")
done
for src in $SHRD_BUILD; do
    obj=$(compile_file "$src" "dll" "shared")
    DLL_OBJS+=("$obj")
done
for src in $STTC_BUILD; do
    obj=$(compile_file "$src" "lib" "static")
    LIB_OBJS+=("$obj")
done
for src in $PCHD_BUILD; do
    PCH_HDRS+=("$src")
done

if [[ $COMP_ERRORS -ne 0 ]]; then
    echo "Build finished with $COMP_ERRORS errors."
    exit 1
fi

if [[ $NOLINK -eq 1 ]]; then
    echo "Argument 'nolink' specified. Linking aborted."
    exit 0
fi

echo "Linking..."
[[ ${#EXE_OBJS[@]} -gt 0 ]] && link_target exe "$EXE_FILE_NAME" "${EXE_OBJS[*]}"
[[ ${#DLL_OBJS[@]} -gt 0 ]] && link_target dll "$DLL_FILE_NAME" "${DLL_OBJS[*]}"
[[ ${#LIB_OBJS[@]} -gt 0 ]] && link_target lib "$LIB_FILE_NAME" "${LIB_OBJS[*]}"
for hdr in "${PCH_HDRS[@]}"; do
    link_target pch "$(basename "${hdr%.h}")" "$hdr"
done

echo "Successful!"
exit 0