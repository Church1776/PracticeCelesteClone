#!/bin/sh

CLEAN_BUILD=0
DEBUG_FLAGS=""
DEBUG_MODE=0
ARCHIVE_BUILD=0

echo "Building..."

for arg in "$@"; do
    case "$arg" in
        clean)
            CLEAN_BUILD=1
            ;;
        archive)
            ARCHIVE_BUILD=1
            ;;
        *)
            DEBUG_FLAGS="$DEBUG_FLAGS $arg"
            DEBUG_MODE=1
            ;;
    esac
done

if [ $DEBUG_MODE -ne 0 ]; then
    echo "Grabbing debug info..."
fi

FAILURES=0

#echo "Finding compiler"
GXX=$(which g++)
LD_PATTERN=$(g++ -print-prog-name=ld | sed 's|/|\\/|g')

SOURCE_DIR="%USERPROFILE%/PracticeCelesteClone/source"    # relative to script/ folder
BUILD_DIR="%USERPROFILE%/PracticeCelesteClone/build"
BIN_DIR="%USERPROFILE%/PracticeCelesteClone/bin"
EXECUTABLE="CelesteClone.exe"

#echo "Clearing Build Directory"
if [ "$CLEAN_BUILD" -eq 1 ]; then
    echo "Build Directory CLeaned."
    rm -rf "$BUILD_DIR"/*
    rm -rf "$BIN_DIR"/*
    exit 0
fi

if [ "$ARCHIVE_BUILD" -eq 1 ]; then
    if [ -d "$BUILD_DIR" ] || [ -d "$BIN_DIR" ]; then
        TIMESTAMP=$(date +%Y-%m-%d_%H.%M.%S)
        ARCHIVE_DIR="../old_build_$TIMESTAMP"
        echo "Archiving current build to $ARCHIVE_DIR..."
        mkdir -p "$ARCHIVE_DIR"
        [ -d "$BUILD_DIR" ] && mv "$BUILD_DIR" "$ARCHIVE_DIR/"
        [ -d "$BIN_DIR" ] && mv "$BIN_DIR" "$ARCHIVE_DIR/"
    fi
fi

#echo "Resetting build directory"
rm -rf "$BUILD_DIR"/*
rm -rf "$BIN_DIR"/*

#echo "Grabbing Sub Directories"
INCLUDE_DIRS=$(find "$SOURCE_DIR" -type d)
INCLUDE_FLAGS=""
for dir in $INCLUDE_DIRS; do
    INCLUDE_FLAGS="$INCLUDE_FLAGS -I$dir"
done

#echo "Finding Source Files"
SRC_FILES=$(find "$SOURCE_DIR" -name '*.cpp')

#echo "Mirroring Object Directories"
mkdir -p "$BIN_DIR"
LINK_CMD="$GXX -o "$BIN_DIR/$EXECUTABLE""

#echo "Compiling source..."
for src in $SRC_FILES; do
    # Path relative to SOURCE_DIR (e.g. "game/player.cpp")
    rel_path="${src#$SOURCE_DIR/}"
    # Matching object file path inside build/ (e.g. "build/game/player.o")
    obj="$BUILD_DIR/${rel_path%.cpp}.o"

    # Ensure subdir exists in build/
    mkdir -p "$(dirname "$obj")"

    # Compile
    "$GXX" -std=c++23 $INCLUDE_FLAGS -c $DEBUG_FLAGS "$src" -o "$obj" 2>&1 | sed -E \
        -e 's|C:/[^[:space:]]*[/]||g' \
        -e 's/candidate:/\
        candidate:/g' \
        -e 's|^[[:space:]]*||'
    
    if [ ${PIPESTATUS[0]} -ne 0 ]; then
        FAILURES=$((FAILURES + 1))
    fi

    #echo "Preparing objects for linker"
    LINK_CMD="$LINK_CMD \"$obj\""
done

if [ $FAILURES -ne 0 ]; then
    echo "Build finished with $FAILURES errors."
    exit 1
fi

#echo "Linking objects..."
eval "$LINK_CMD" 2>&1 | sed -E \
    -e "s|$LD_PATTERN:||g" \
    -e "s|[^[:space:]]*\.o:||g" \
    -e "s|$SOURCE_DIR/||g" \
    -e 's|^[[:space:]]*||'

if [ ${PIPESTATUS[0]} -eq 0 ]; then
    echo "Successful!"
else
    echo "Failed."
    exit 1
fi
