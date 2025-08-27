//##################################################################################################################################
//                                                         Global Variables
//##################################################################################################################################

static bool running = true;

//##################################################################################################################################
//                                                         Global Functions
//##################################################################################################################################

bool create_window(int width, int height, const char* wndw_name);
bool enable_virtual_terminal_processing();
void update_window();

//##################################################################################################################################
//                                                         Platform Defines
//##################################################################################################################################


//##### ---Windows Platform--- #####
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "logger_lib.h"

static HWND window;

LRESULT CALLBACK callback_to_window(HWND window, UINT msg, WPARAM w, LPARAM l){
    LRESULT result;
    
    switch(msg){
        case WM_CLOSE:
            running = false;
            break;
        default:
            result = DefWindowProcA(window, msg, w, l);
    }
    
    return result;
}

bool create_window(int width, int height, const char* wndw_name){
    
    HINSTANCE instance;
    
    WNDCLASSA wc{};
        wc.style = {};
        wc.hInstance = instance;
        wc.hCursor = LoadCursorA(instance, IDC_ARROW);
        wc.hIcon = LoadIconA(instance, IDI_APPLICATION);
        wc.lpszClassName = "My Window";
        wc.lpfnWndProc = callback_to_window;
    
    if(!(RegisterClassA(&wc))){return false;}
    
    int dwStyle = WS_OVERLAPPEDWINDOW;
    
    window = CreateWindowExA(
        0,
        wc.lpszClassName,
        wndw_name,
        dwStyle,
        100, 100, width, height,
        NULL, NULL,
        instance,
        NULL
    );
    
    if(window == NULL){return false;}
    
    ShowWindow(window, SW_SHOW);
    return true;
}

bool enable_virtual_terminal_processing(){
    
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    if(out == INVALID_HANDLE_VALUE){return false;}
    
    DWORD dwMode = 0;
    if(!GetConsoleMode(out, &dwMode)){return false;}
    
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(out, dwMode);
    return true;    
}

void update_window(){
    
    MSG msg;
    while(PeekMessageA(&msg, window, 0, 0, PM_REMOVE)){
    TranslateMessage(&msg);
    DispatchMessageA(&msg);
    }
}

#endif//_WIN32
//##### ---Windows End--- #####


int main(){
    
    create_window(1200, 700, "My Window");
    enable_virtual_terminal_processing();
    
    while(running){
        
        update_window();   // Update game loop
        
        SM_TRACE("Test");
        SM_WARN("Test");
        SM_ERROR("Test");
        
    }
    return 0;
}