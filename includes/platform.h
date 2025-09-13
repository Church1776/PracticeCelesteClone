#ifndef PLATFORM_H
#define PLATFORM_H

//##################################################################################################################################
//                                                   Platform Defines & Includes
//##################################################################################################################################

//##### ---Windows Platform--- #####
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#define DEBUG_BREAK() DebugBreak()
#endif//_WIN32

//##### ---Linux Platform--- #####
#ifdef  __linux__
#define DEBUG_BREAK() __builtin_debugtrap()
#endif//__linux__

//##### ---Macintosh Platform--- #####
#ifdef  __APPLE__
#define DEBUG_BREAK() __builtin_trap()
#endif//__APPLE__

#define BIT(x) 1 << (x)
#define KB(x) ((unsigned long long)1024 * x)
#define MB(x) ((unsigned long long)1024 * KB(x))
#define GB(x) ((unsigned long long)1024 * MB(x))


//##################################################################################################################################
//                                                         Global Variables
//##################################################################################################################################

inline bool running = true;

//##################################################################################################################################
//                                                         Global Functions
//##################################################################################################################################

bool create_window(int width, int height, const char* wndw_name);
bool enable_virtual_terminal_processing();
void update_window();
void* platform_load_gl_function(const char* funcName);
void swap_buffers();

#endif//PLATFORM_H