#!/bin/sh
ARGS=""

for arg in "$@"; do
    case "$arg" in
        test)
            echo "This was tested with no flags given."
            ;;
        full)
            ARGS="-g -g3 -O0 -Wall -Wextra -Wpedantic -gsplit-dwarf -fsanitize=address,undefined"
            ;;
        *)
            ARGS="$ARGS \"$arg\""
    esac
done

if [ -z "$ARGS" ]; then
    ARGS="-g -gsplit-dwarf"
fi

eval "sh build.sh $ARGS"
exit 0    


#sh build.sh -g3  -gsplit-dwarf



# Normal debug build with runtime sanitizers
#g++ -g -ggdb -O0 -Wall -Wextra -Wpedantic -fsanitize=address,undefined main.cpp -o main

# Debug build exporting all symbols (useful for gdb & plugins)
#g++ -g -O0 -rdynamic main.cpp -o main

# Debug build with a linker map file for symbol tracing
#g++ -g -O0 -Wl,-Map=main.map,--cref
  
  