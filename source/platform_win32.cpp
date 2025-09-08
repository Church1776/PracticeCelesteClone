#include "input.h"
#include "platform.h"
#include "main_game_lib.h"
#include "gl_renderer.h"

//##################################################################################################################################
//                                                         Platform Globals
//##################################################################################################################################

static HWND window;
static HDC dc;

//##################################################################################################################################
//                                                            Functions
//##################################################################################################################################

LRESULT CALLBACK callback_to_window(HWND window, UINT msg, WPARAM w, LPARAM l){
    LRESULT result = 0;
    RECT rect = {};
    switch(msg){        
        case WM_CLOSE:
            running = false;
            break;
        case WM_SIZE:            
            GetClientRect(window, &rect);
            input.screenSizeX = rect.right - rect.left;
            input.screenSizeY = rect.bottom - rect.top;
            break;
        default:
            result = DefWindowProcA(window, msg, w, l);
    }
    
    return result;
}

bool create_window(int width, int height, const char* wndw_name){
    
    HINSTANCE instance = GetModuleHandle(NULL);
    
    WNDCLASSA wc = {};
        wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
        wc.hInstance = instance;
        wc.hCursor = LoadCursor(instance, IDC_ARROW);
        wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
        wc.lpszClassName = "This is the Class Name for wc";
        wc.lpfnWndProc = callback_to_window;
    
    if(!(RegisterClassA(&wc))){return false;}
    
    int dwStyle = WS_OVERLAPPEDWINDOW;
    
    // Fake Window Initialization for OpenGl
    {
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
        
        if(window == NULL){
            SM_ASSERT(false, "Failed to open Windows window.");
            return false;
        }
        
        HDC fakeDC = GetDC(window);        
        if(!fakeDC){
            SM_ASSERT(false, "Failed to get HDC.");
            return false;
        }
        
        PIXELFORMATDESCRIPTOR pfd = {0};
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cAlphaBits = 8;
        pfd.cDepthBits = 24;
        
        int pixelFormat = ChoosePixelFormat(fakeDC, &pfd);        
        if(!pixelFormat){
            SM_ASSERT(false, "Failed to choose pixel format.");
            return false;
        }
        
        if(!SetPixelFormat(fakeDC, pixelFormat, &pfd)){
            SM_ASSERT(false, "Failed to set the pixel format.");
            return false;
        }
        
        //### --Create a handle to a fake OpenGL rendering context-- ###
        HGLRC fakeRC = wglCreateContext(fakeDC);
        if(!fakeRC){
            SM_ASSERT(false, "Failed to create Render Context.");
            return false;
        }
        
        if(!wglMakeCurrent(fakeDC, fakeRC)){
            SM_ASSERT(false, "Failed to make current");
            return false;
        }
        
        //##### ---This is to grab the windows extensions for creating the true window context for our game--- #####
        gl_load_platform_extensions(); 
        
        if(!wglCreateContextAttribsARB_ptr || !wglChoosePixelFormatARB_ptr){
            SM_ASSERT(false, "Failed to load Windows OpenGL Extension functions");
            return false;
        }
        
        // Cleaning up the fake window/device context
        wglMakeCurrent(fakeDC, 0);
        wglDeleteContext(fakeRC);
        ReleaseDC(window, fakeDC);
        DestroyWindow(window);      
        
        
        //##### ---Actual OpenGL Initialized Window--- #####
    
        {
            RECT borderRect = {};
            AdjustWindowRectEx(&borderRect, dwStyle, 0, 0);
            
            width += borderRect.right - borderRect.left;
            height += borderRect.bottom - borderRect.top;
        }
        
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
        
        if(window == NULL){
            SM_ASSERT(false, "Failed to open Windows window.");
            return false;
        }
        
        dc = GetDC(window);        
        if(!dc){
            SM_ASSERT(false, "Failed to get HDC.");
            return false;
        }
        
        const int pixelAttribs[]{
                                WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
                                WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
                                WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
                                WGL_SWAP_METHOD_ARB,    WGL_SWAP_COPY_ARB,
                                WGL_PIXEL_TYPE_ARB,     WGL_TYPE_RGBA_ARB,
                                WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
                                WGL_COLOR_BITS_ARB,     32,
                                WGL_ALPHA_BITS_ARB,     8,
                                WGL_DEPTH_BITS_ARB,     24,
                                0
        };
        
        UINT numPixelFormats;
        pixelFormat = 0;
        if(!wglChoosePixelFormatARB_ptr(dc, pixelAttribs,
                                    0,
                                    1,
                                    &pixelFormat,
                                    &numPixelFormats)){
            SM_ASSERT(false, "Failed: wglChoosePixelFormatARB");
            return false;
        }
        
        pfd = {0};
        DescribePixelFormat(dc, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
        if(!SetPixelFormat(dc, pixelFormat, &pfd)){
            SM_ASSERT(false, "Failed: SetPixelFormat");
            return false;
        }
        
        const int contextAttribs[]{
                                WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
                                WGL_CONTEXT_MINOR_VERSION_ARB, 3,
                                WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
                                WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
                                0  
        };
        
        HGLRC rc = wglCreateContextAttribsARB(dc, 0, contextAttribs);
        if(!rc){
            SM_ASSERT(0, "failed to create Render Context for OpenGL");
            return false;
        }
        
        if(!wglMakeCurrent(dc, rc)){
            SM_ASSERT(0, "Failed: wglMakeCurrent");
            return false;
        }
    }
    
    //gl_load_functions();
    
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

void* platform_load_gl_function(const char* funcName){
    PROC proc = wglGetProcAddress(funcName);
    if(!proc){
        static HMODULE openglDLL = LoadLibraryA("opengl32.dll");
        proc = GetProcAddress(openglDLL, funcName);
        if(!proc){
            SM_ASSERT(false, "Failed to load gl function %s", funcName);
            return nullptr;
        }
    }
    return (void*)proc;
}

void swap_buffers(){
    
    SwapBuffers(dc);
}