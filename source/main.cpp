#include "input.h"
#include "platform.h"
#include "base_lib.h"
#include "gl_renderer.h"

int main(){
    
    BumpAllocator transientStorage = make_bump_allocator(MB(50));
    enable_virtual_terminal_processing();
    create_window(1200, 720, "Celeste Clone");
    input.screenSizeX = 1200;
    input.screenSizeY = 720;
    gl_init(&transientStorage);
    
    while(running){
        
        update_window();   // Update game loop
        gl_render();
        swap_buffers();        
    }
    return 0;
}