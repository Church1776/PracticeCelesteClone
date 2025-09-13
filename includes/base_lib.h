#ifndef BASE_LIB_H
#define BASE_LIB_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>

//################################################################################################################################
//                                                            Defines
//################################################################################################################################



//################################################################################################################################
//                                                        Logging Functions
//################################################################################################################################

enum TextColor{
    TEXT_COLOR_BLACK = 0,
    TEXT_COLOR_RED,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_MAGENTA,
    TEXT_COLOR_CYAN,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_BRIGHT_BLACK,
    TEXT_COLOR_BRIGHT_RED,
    TEXT_COLOR_BRIGHT_GREEN,
    TEXT_COLOR_BRIGHT_YELLOW,
    TEXT_COLOR_BRIGHT_BLUE,
    TEXT_COLOR_BRIGHT_MAGENTA,
    TEXT_COLOR_BRIGHT_CYAN,
    TEXT_COLOR_BRIGHT_WHITE,
    TEXT_COLOR_COUNT,
};
template <typename ...Args>
void _log(const char* prefix, const char* msg, TextColor textColor, Args... args){
    static const char* TextColorTable[TEXT_COLOR_COUNT]{
        "\x1b[30m",  // TEXT_COLOR_BLACK = 0,
        "\x1b[31m",  // TEXT_COLOR_RED,
        "\x1b[32m",  // TEXT_COLOR_GREEN,
        "\x1b[33m",  // TEXT_COLOR_YELLOW,
        "\x1b[34m",  // TEXT_COLOR_BLUE,
        "\x1b[35m",  // TEXT_COLOR_MAGENTA,
        "\x1b[36m",  // TEXT_COLOR_CYAN,
        "\x1b[37m",  // TEXT_COLOR_WHITE,
        "\x1b[90m",  // TEXT_COLOR_BRIGHT_BLACK,
        "\x1b[91m",  // TEXT_COLOR_BRIGHT_RED,
        "\x1b[92m",  // TEXT_COLOR_BRIGHT_GREEN,
        "\x1b[93m",  // TEXT_COLOR_BRIGHT_YELLOW,
        "\x1b[94m",  // TEXT_COLOR_BRIGHT_BLUE,
        "\x1b[95m",  // TEXT_COLOR_BRIGHT_MAGENTA,
        "\x1b[96m",  // TEXT_COLOR_BRIGHT_CYAN,
        "\x1b[97m",  // TEXT_COLOR_BRIGHT_WHITE,
    };
        
    char formatBuffer[8192] = {};
    sprintf(formatBuffer, "%s %s %s \033[0m", TextColorTable[textColor], prefix, msg);
    
    char textBuffer[8192] = {};
    sprintf(textBuffer, formatBuffer, args...);
    
    puts(textBuffer);
    
    //"\x1b[31m" + msg + "\033[0m";  // This turns the text back to Black after printing the colored text.
}

//################################################################################################################################
//                                                        Logging Defines
//################################################################################################################################

#define SM_TRACE(msg, ...) _log("TRACE: ", msg, TEXT_COLOR_GREEN, ##__VA_ARGS__)
#define SM_WARN(msg, ...)  _log("WARNING: ", msg, TEXT_COLOR_YELLOW, ##__VA_ARGS__)
#define SM_ERROR(msg, ...) _log("ERROR: ", msg, TEXT_COLOR_RED, ##__VA_ARGS__)



#define DEBUG
#ifndef DEBUG
    // Default: assertions disabled
    #define SM_ASSERT(x, msg, ...) ((void)0)
#else
    // Active only in debug
    #ifndef SM_ASSERT
    #define SM_ASSERT(x, msg, ...)       \
    do {                                 \
        if (!(x)) {                      \
            SM_ERROR(msg, ##__VA_ARGS__);\
            DEBUG_BREAK();               \
            SM_ERROR("Assertion HIT!");  \
        }                                \
        } while (0)
    #endif
#endif

//################################################################################################################################
//                                                         Bump Allocator
//################################################################################################################################

struct BumpAllocator{
    size_t capacity;
    size_t used;
    char* memory;
};

BumpAllocator make_bump_allocator(size_t size);
char* bump_alloc(BumpAllocator* alloc, size_t size);

//################################################################################################################################
//                                                            File I/O
//################################################################################################################################

long long get_timestamp(const char* file);
bool file_exists(const char* filePath);
long get_file_size(const char* filePath);
char* read_file(const char* filePath, int* fileSize, char* buffer);
char* read_file(const char* filePath, int* fileSize, BumpAllocator* alloc);
void write_file(const char* filePath, char* buffer, int size);
bool copy_file(const char* fileName, const char* outputName, char* buffer);
bool copy_file(const char* fileName, const char* outputName, BumpAllocator* alloc);


#endif//BASE_LIB_H