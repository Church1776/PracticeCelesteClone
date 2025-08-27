#!/bin/bash

### --- This file is meant to be used when in the terminal to call the local project whose directory you're currently working in/opened to.

### --- Add this file to an already existing default $PATH environment directory or create your own folder
### --- and add that folder as a $PATH in your environment variables yourself. Your only limitation is that
### --- your terminal must call this script from within the project directory you wish to use it. With this
### --- script you'll be able to call to the local script from within any project directory you work in.
### --- Just remember that you must have your terminal open to the project directory root folder. If you are
### --- in any sub folders the script will not work.

# ---Start from the current working directory---

PROJECT_NAME=$(pwd)
DEBUG_ARGS=""
QUALIFIERS=""

# ---Grabs arguments to send to local build script---
for arg in "$@"; do
    case "$arg" in
        noexp)
            QUALIFIERS="$QUALIFIERS $arg"
            ;;
        clean)
            QUALIFIERS="$QUALIFIERS $arg"
            ;;
        archive)
            QUALIFIERS="$QUALIFIERS $arg"
            ;;
        noclean)
            QUALIFIERS="$QUALIFIERS $arg"
            ;;
        *)
            DEBUG_ARGS="$DEBUG_ARGS $arg"
            ;;
    esac
done

# ---Assigns for build script in the projects directory---
SCRIPT=$(find "$PROJECT_NAME" -maxdepth 2 -type f -name "build_current_dir_proj.sh" -print -quit)

# ---Checks if the script was found and executable---
if [ -z "$SCRIPT" ]; then
    echo "Build script not found in $PROJECT_NAME"
    exit 1
fi
if [ ! -x "$SCRIPT" ]; then
    echo "Build script found but not executable: $SCRIPT"
    exit 1
fi

"$SCRIPT" "$PROJECT_NAME" $QUALIFIERS $DEBUG_ARGS
exit 0