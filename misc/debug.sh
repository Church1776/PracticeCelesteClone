#!/bin/bash

### --- This file is meant to be used when in the terminal to call the local project whose directory you're currently working in/opened to.

### --- This script is designed to be called in the same circumstances as the respective build.sh file next to it.
### --- Wherever you place the build.sh file on your computer is where you will place this one. The same rules apply
### --- when calling the script. You must be in the project directory folder within the terminal in order for the 
### --- script to work. Read the build.sh file for more clarity.


ARGS=""
FLAGS=""
TEST=0

for arg in "$@"; do
    case "$arg" in
        test)
            echo "No flags given."
            TEST=1
            ;;
        full)
            FLAGS="-g -g3 -O0 -Wall -Wextra -Wpedantic -gsplit-dwarf -fsanitize=address,undefined"
            ;;
        noexp)
            ARGS="$ARGS $arg"
            ;;
        clean)
            ARGS="$ARGS $arg"
            ;;
        archive)
            ARGS="$ARGS $arg"
            ;;
        noclean)
            ARGS="$ARGS $arg"
            ;;
        *)
            FLAGS="$FLAGS $arg"
            ;;
    esac
done

if [ -z "$FLAGS" ]; then
    FLAGS="-g -gsplit-dwarf"
fi

if [ $TEST -eq 1 ]; then
    FLAGS=""
fi

sh build.sh $ARGS $FLAGS
exit 0    


#sh build.sh -g3  -gsplit-dwarf



# Normal debug build with runtime sanitizers
#g++ -g -ggdb -O0 -Wall -Wextra -Wpedantic -fsanitize=address,undefined main.cpp -o main

# Debug build exporting all symbols (useful for gdb & plugins)
#g++ -g -O0 -rdynamic main.cpp -o main

# Debug build with a linker map file for symbol tracing
#g++ -g -O0 -Wl,-Map=main.map,--cref