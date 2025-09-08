#version 460 core

void main(){
    
    //##### ---Generating Vertices on the GPU because we have a 2D Engine--- #####
    
    //### --OpenGL Coordinates-- ###    
    
    //   (-1/ 1)------------------( 1/ 1)      <--Top Left       -        Top Right
    //      |                         |
    //      |                         |
    //      |         ( 0/ 0)         |        <--Center of screen is 0/0.
    //      |                         |
    //      |                         |
    //   (-1/-1)-------------------( 1/-1)     <--Bottom Left    -     Bottom Right
    
    vec2 vertices[6] = {
        // Top    Left
        vec2(-0.5,  0.5),
        // Bottom Left
        vec2(-0.5, -0.5),
        // Top    Right
        vec2( 0.5,  0.5),
        // Top    Right
        vec2( 0.5,  0.5),
        // Bottom Left
        vec2(-0.5, -0.5),
        // Bottom Right
        vec2( 0.5, -0.5)        
    };
    
    gl_Position = vec4(vertices[gl_VertexID], 1.0, 1.0);
};