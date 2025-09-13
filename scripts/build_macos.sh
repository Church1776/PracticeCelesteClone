#!/bin/bash

##### ---NON-POSIX Mode Enforced--- #####
if [ -z "$BASH_VERSION" ]; then
    exec bash "$0" "$@"
fi

##### ---Build Initialized--- #####
echo "Initializing..."

### --Prep Variables-- ###
AUTO=0; ARCHIVE_BUILD=0; CLEAN_BUILD=0; COMP_ERRORS=0; DLL_MODE=0;

### --Source files/flags for the build-- ###
DEBUG_FLAGS=""
CPP_VERSION="-std=c++23"
CPPEXP="-lstdc++exp"             ## <--For visibility of the C++ experimental library
SRC_FILES="main.cpp main_game_lib.cpp platform_mac.mm input.cpp gl_renderer.cpp"
SRC_DLLS=""
LINKER_LIBS="-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo"
EXECUTABLE="CelesteClone"        ## <-- macOS binaries have no .exe
DLL_FILE_NAME=""
TIMESTAMP=$(date +%Y-%m-%d_%H.%M.%S)

### --Preparing directory paths for processing-- ###
PROJECT_DIR="$1"; shift
ARCHIVE_DIR="$PROJECT_DIR/archive"
SOURCE_DIR="$PROJECT_DIR/source"    ## <-- For the human-readable code
BUILD_DIR="$PROJECT_DIR/build"      ## <-- For the compiled object files
BIN_DIR="$PROJECT_DIR/bin"          ## <-- For executable and dynamic libraries

### --Locate Source Files and Include Directories for Building-- ###
echo "Sourcing..."
SRC_BUILD=$(find "$SOURCE_DIR" $(printf -- '-name %s -o ' $SRC_FILES) -false)
SHRD_BUILD=$(find "$SOURCE_DIR" $(printf -- '-name %s -o ' $SRC_DLLS) -false)
INCLUDE_FLAGS=$(find "$SOURCE_DIR" -type d -exec printf ' -I%s' {} +)

GXX=$(which g++)
LD_PATTERN=$(g++ -print-prog-name=ld | sed 's|/|\\/|g')   ## <-- Finding compiler and linker
LINK_DLL="$GXX -o \"$BIN_DIR\""
LINK_CMD="$GXX -o \"$BIN_DIR/$EXECUTABLE\""

##### ---Evaluating options specified--- #####
for arg in "$@"; do
    case "$arg" in
        auto) 
            AUTO=1
            SRC_FILES=""
            SRC_DLLS=""
            ;;
        clean)
            CLEAN_BUILD=1 
            ;;
        archive)
            ARCHIVE_BUILD=1
            CLEAN_BUILD=1
            ;;
        dll)
            DLL_MODE=1
            if [[ $AUTO -eq 0 ]]; then
                echo "Must specify file or 'auto' for 'dll' to be valid."
                DLL_MODE=0
            fi            
            ;;
        dll=*.cpp)
            DLL_MODE=1
            SHRD_BUILD+=" $(find "$SOURCE_DIR" -name "${arg#dll=}")"
            ;;
        *.cpp)
            if [[ $DLL_MODE -eq 1 ]]; then
                SHRD_BUILD+=" $(find "$SOURCE_DIR" -name "$arg")"
            else
                SRC_BUILD+=" $(find "$SOURCE_DIR" -name "$arg")"
            fi
            ;;
        -*)
            echo "Grabbing debug info... \"$arg\""
            DEBUG_FLAGS+=" $arg"
            ;;
        *)
            echo "'$*' not recognized. Argument ignored."
            ;;
    esac
done

##### ---Validating source files for the compiler--- #####
if [[ -z $SRC_BUILD && -z $SHRD_BUILD ]]; then
    echo "No files provided. Auto detecting input files..."
    AUTO=1
fi
if [[ $AUTO -eq 1 ]]; then
    echo "Option 'auto' specified. Locating source files."
    if [[ DLL_MODE -eq 1 ]]; then
        SHRD_BUILD=""
        SHRD_BUILD=$(find "$SOURCE_DIR" -name '*.cpp' -o -name '*.mm')
    else
        SRC_BUILD=""
        SRC_BUILD=$(find "$SOURCE_DIR" -name '*.cpp' -o -name '*.mm')
    fi
fi
if [[ -z $SRC_BUILD && -z $SHRD_BUILD ]]; then
    echo "No files found. Build aborted."
    exit 1
fi

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

if [[ $CLEAN_BUILD -eq 1 ]]; then   ## <-- Difference from later 'rm' is this exits without building
    rm -rf "$BUILD_DIR"/*           ##
    rm -rf "$BIN_DIR"/*             ##
    echo "Previous Build Cleaned"   ##
    exit 0
fi

rm -rf "$BUILD_DIR"/*      ## <-- Resets build directory for new build
rm -rf "$BIN_DIR"/*        ##

##### ---Compiling to objects--- #####
echo "Compiling..."
for src in $SRC_BUILD; do    
    rel_path="${src#$SOURCE_DIR/}"                  
    obj="$BUILD_DIR/source/${rel_path%.*}.o"        ## handles .cpp and .mm
    mkdir -p "$(dirname "$obj")"                    
    "$GXX" $CPP_VERSION $INCLUDE_FLAGS -c $DEBUG_FLAGS "$src" -o "$obj" 2>&1 | sed -E \
        -e 's|/[^[:space:]]*[/]||g'     \
        -e 's/candidate:/\n candidate:/g' \
        -e 's|^[[:space:]]*||'               
    if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
        COMP_ERRORS=$((COMP_ERRORS + 1))  
    fi    
    LINK_CMD="$LINK_CMD \"$obj\""
done

##### ---Compiling dynamic libraries--- #####
for dll in $SHRD_BUILD; do    
    rel_path="${dll#$SOURCE_DIR/}"                  
    obj="$BUILD_DIR/shared/${rel_path%.*}.o"        ## handles .cpp and .mm
    mkdir -p "$(dirname "$obj")"                    
    "$GXX" $CPP_VERSION $INCLUDE_FLAGS -c $DEBUG_FLAGS -fPIC "$dll" -o "$obj" 2>&1 | sed -E \
        -e 's|/[^[:space:]]*[/]||g'     \
        -e 's/candidate:/\n candidate:/g' \
        -e 's|^[[:space:]]*||'               
    if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
        COMP_ERRORS=$((COMP_ERRORS + 1))  
    fi    
done
if [[ $COMP_ERRORS -ne 0 ]]; then
    echo "Build finished with $COMP_ERRORS errors."
    exit 1
fi

mkdir -p "$BIN_DIR"                      

##### ---Linking to create executable--- #####
echo "Linking..."
eval "$LINK_CMD $LINKER_LIBS $CPPEXP" 2>&1 | sed -E \
    -e "s|$LD_PATTERN:||g" \
    -e "s|[^[:space:]]*\.o:||g" \
    -e "s|$SOURCE_DIR/||g" \
    -e 's|\(.[^[:space:]]*[]]|(|'

if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
    echo "Failed."
    exit 1
fi

##### ---Linking dynamic libraries--- #####
if [[ $DLL_MODE -eq 1 ]]; then
    echo "Sharing..."
    for subdir in "$BUILD_DIR"/shared/*/; do
        [[ -d "$subdir" ]] || continue   

        DLL_NAME="lib$(basename "$subdir").dylib"   ## macOS shared libs: libNAME.dylib
        OBJ_FILES=("$subdir"/*.o)                  

        mkdir -p "$BIN_DIR"
        LINK_DLL="$GXX -dynamiclib -fPIC -o \"$BIN_DIR/$DLL_NAME\" ${OBJ_FILES[*]} $LINKER_LIBS $CPPEXP"

        echo "Linking $DLL_NAME..."
        eval "$LINK_DLL" 2>&1 | sed -E \
            -e "s|$LD_PATTERN:||g" \
            -e "s|[^[:space:]]*\.o:||g" \
            -e "s|$SOURCE_DIR/||g" \
            -e 's|\(.[^[:space:]]*[]]|(|'
    done
    if [[ ${PIPESTATUS[0]} -ne 0 ]]; then
        echo "Failed linking $DLL_NAME."
        exit 1
    fi
fi

echo "Successful!"
exit 0