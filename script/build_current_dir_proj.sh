#!/bin/bash

### ---Prep Variables--- ###
PROJECT_DIR="$1"
shift
ARCHIVE_BUILD=0
CLEAN_BUILD=0
COMP_ERRORS=0
DEBUG_FLAGS=""
DEBUG_MODE=0
EXPERIMENTAL=1
NO_CLEAN=0
SOURCE_DIR="$PROJECT_DIR/source"    ## <-- for the human code.
BUILD_DIR="$PROJECT_DIR/build"    ## <-- for the compiled objects.
BIN_DIR="$PROJECT_DIR/bin"    ## <-- for the executables.
EXECUTABLE="CelesteClone.exe"
INCLUDE_DIRS=$(find "$SOURCE_DIR" -type d)
INCLUDE_FLAGS=""
SRC_FILES=$(find "$SOURCE_DIR" -name '*.cpp')
for dir in $INCLUDE_DIRS; do
    INCLUDE_FLAGS="$INCLUDE_FLAGS -I$dir"       ## <-- so I don't have to manually tell the compiler where to search for my files.
done

GXX=$(which g++)
LD_PATTERN=$(g++ -print-prog-name=ld | sed 's|/|\\/|g')     ## <-- finding compiler and linker.
LINK_CMD="$GXX -o "$BIN_DIR/$EXECUTABLE""

for arg in "$@"; do  ## <-- evaluates all args passed. any case matched has it's respective code executed.
    case "$arg" in
        noexp)
            EXPERIMENTAL=0
            ;;
        clean)
            CLEAN_BUILD=1
            ;;
        archive)
            ARCHIVE_BUILD=1
            CLEAN_BUILD=1
            ;;
        noclean)
            NO_CLEAN=1
            ;;
         *)
            echo "Grabbing debug info... \"$arg\""
            DEBUG_FLAGS="$DEBUG_FLAGS $arg" ## <-- for manual debug input
            DEBUG_MODE=1
            ;;
    esac
done

if [ "$ARCHIVE_BUILD" -eq 1 ]; then
    if [ -d "$BUILD_DIR" ] || [ -d "$BIN_DIR" ]; then
        TIMESTAMP=$(date +%Y-%m-%d_%H.%M.%S)
        ARCHIVE_DIR="$BUILD_DIR/../archive/old_build_$TIMESTAMP"
        echo "Archiving current build to $ARCHIVE_DIR..."
        mkdir -p "$ARCHIVE_DIR"
        [ -d "$BUILD_DIR" ] && cp -r "$BUILD_DIR" "$ARCHIVE_DIR/"
        [ -d "$BIN_DIR" ] && cp -r  "$BIN_DIR" "$ARCHIVE_DIR/"
    fi
fi

if [ "$NO_CLEAN" -eq 1 ]; then
    echo "Old Directory Preserved"
    exit 0
fi

if [ "$CLEAN_BUILD" -eq 1 ]; then  ## <-- difference between this and the later 'rm' is this exits without building.
    rm -rf "$BUILD_DIR"/*
    rm -rf "$BIN_DIR"/*
    echo "Previous Build Cleaned"
    exit 0
fi

### ---Build Initialized--- ###
echo "Building..."

rm -rf "$BUILD_DIR"/*      ## <-- resetting build directory for new build.
rm -rf "$BIN_DIR"/*

echo "Compiling..."
for src in $SRC_FILES; do    
    rel_path="${src#$SOURCE_DIR/}"
    obj="$BUILD_DIR/${rel_path%.cpp}.o"      ## <-- this top section preps the build directory.
    mkdir -p "$(dirname "$obj")"
    "$GXX" -std=c++23 $INCLUDE_FLAGS -c $DEBUG_FLAGS "$src" -o "$obj" 2>&1 | sed -E \
        -e 's|C:/[^[:space:]]*[/]||g' \
        -e 's/candidate:/\
        candidate:/g' \
        -e 's|^[[:space:]]*||'    
    if [ ${PIPESTATUS[0]} -ne 0 ]; then
        COMP_ERRORS=$((COMP_ERRORS + 1))       ## <-- records compile errors.
    fi    
    LINK_CMD="$LINK_CMD \"$obj\""   ## <-- needed for prepping link command.
done

if [ $COMP_ERRORS -ne 0 ]; then
    echo "Build finished with $COMP_ERRORS errors."
    exit 1
fi

if [ $EXPERIMENTAL -eq 1 ]; then            ## <---This is the default. I want it so I can use the C++23 stuff that hasn't made it to the standard linker library.
    LINK_CMD="$LINK_CMD \"-lstdc++exp\""
fi

mkdir -p "$BIN_DIR"
echo "Linking..."
eval "$LINK_CMD" 2>&1 | sed -E \
    -e "s|$LD_PATTERN:||g" \
    -e "s|[^[:space:]]*\.o:||g" \
    -e 's|C:/[^[:space:]]*[/]||g' \
    -e "s|$SOURCE_DIR/||g" \
    -e 's|\(.[^[:space:]]*[]]|(|'

if [ ${PIPESTATUS[0]} -ne 0 ]; then
    echo "Failed."
    exit 1
fi

echo "Successful!"
exit 0