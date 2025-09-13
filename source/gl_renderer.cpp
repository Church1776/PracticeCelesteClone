#include "input.h"
#include "platform.h"
#include "base_lib.h"
#include "gl_renderer.h"

//##################################################################################################################################
//                                                    Pointer Assigning Function
//##################################################################################################################################

void gl_load_functions(){
    glCreateProgram_ptr = (PFNGLCREATEPROGRAMPROC)platform_load_gl_function("glCreateProgram");
    glDeleteTextures_ptr = (PFNGLDELETETEXTURESPROC)platform_load_gl_function("glDeleteTextures");
    glGenTextures_ptr = (PFNGLGENTEXTURESPROC)platform_load_gl_function("glGenTextures");
    glBindTexture_ptr = (PFNGLBINDTEXTUREPROC)platform_load_gl_function("glBindTexture");
    glDrawArrays_ptr = (PFNGLDRAWARRAYSPROC)platform_load_gl_function("glDrawArrays");
    glCreateShader_ptr = (PFNGLCREATESHADERPROC) platform_load_gl_function("glCreateShader");
    glGetUniformLocation_ptr = (PFNGLGETUNIFORMLOCATIONPROC) platform_load_gl_function("glGetUniformLocation");
    glUniform1f_ptr = (PFNGLUNIFORM1FPROC) platform_load_gl_function("glUniform1f");
    glUniform2fv_ptr = (PFNGLUNIFORM2FVPROC) platform_load_gl_function("glUniform2fv");
    glUniform3fv_ptr = (PFNGLUNIFORM3FVPROC) platform_load_gl_function("glUniform3fv");
    glUniform1i_ptr = (PFNGLUNIFORM1IPROC) platform_load_gl_function("glUniform1i");
    glUniformMatrix4fv_ptr = (PFNGLUNIFORMMATRIX4FVPROC) platform_load_gl_function("glUniformMatrix4fv");
    glVertexAttribDivisor_ptr = (PFNGLVERTEXATTRIBDIVISORPROC) platform_load_gl_function("glVertexAttribDivisor");
    glActiveTexture_ptr = (PFNGLACTIVETEXTUREPROC) platform_load_gl_function("glActiveTexture");
    glBufferSubData_ptr = (PFNGLBUFFERSUBDATAPROC) platform_load_gl_function("glBufferSubData");
    glDrawArraysInstanced_ptr = (PFNGLDRAWARRAYSINSTANCEDPROC) platform_load_gl_function("glDrawArraysInstanced");
    glBindFramebuffer_ptr = (PFNGLBINDFRAMEBUFFERPROC) platform_load_gl_function("glBindFramebuffer");
    glCheckFramebufferStatus_ptr = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) platform_load_gl_function("glCheckFramebufferStatus");
    glGenFramebuffers_ptr = (PFNGLGENFRAMEBUFFERSPROC) platform_load_gl_function("glGenFramebuffers");
    glFramebufferTexture2D_ptr = (PFNGLFRAMEBUFFERTEXTURE2DPROC) platform_load_gl_function("glFramebufferTexture2D");
    glDrawBuffers_ptr = (PFNGLDRAWBUFFERSPROC) platform_load_gl_function("glDrawBuffers");
    glDeleteFramebuffers_ptr = (PFNGLDELETEFRAMEBUFFERSPROC) platform_load_gl_function("glDeleteFramebuffers");
    glBlendFunci_ptr = (PFNGLBLENDFUNCIPROC) platform_load_gl_function("glBlendFunci");
    glBlendEquation_ptr = (PFNGLBLENDEQUATIONPROC) platform_load_gl_function("glBlendEquation");
    glClearBufferfv_ptr = (PFNGLCLEARBUFFERFVPROC) platform_load_gl_function("glClearBufferfv");
    glShaderSource_ptr = (PFNGLSHADERSOURCEPROC) platform_load_gl_function("glShaderSource");
    glCompileShader_ptr = (PFNGLCOMPILESHADERPROC) platform_load_gl_function("glCompileShader");
    glGetShaderiv_ptr = (PFNGLGETSHADERIVPROC) platform_load_gl_function("glGetShaderiv");
    glGetShaderInfoLog_ptr = (PFNGLGETSHADERINFOLOGPROC) platform_load_gl_function("glGetShaderInfoLog");
    glAttachShader_ptr = (PFNGLATTACHSHADERPROC) platform_load_gl_function("glAttachShader");
    glLinkProgram_ptr = (PFNGLLINKPROGRAMPROC) platform_load_gl_function("glLinkProgram");
    glValidateProgram_ptr = (PFNGLVALIDATEPROGRAMPROC) platform_load_gl_function("glValidateProgram");
    glGetProgramiv_ptr = (PFNGLGETPROGRAMIVPROC) platform_load_gl_function("glGetProgramiv");
    glGetProgramInfoLog_ptr = (PFNGLGETPROGRAMINFOLOGPROC) platform_load_gl_function("glGetProgramInfoLog");
    glGenBuffers_ptr = (PFNGLGENBUFFERSPROC) platform_load_gl_function("glGenBuffers");
    glGenVertexArrays_ptr = (PFNGLGENVERTEXARRAYSPROC) platform_load_gl_function("glGenVertexArrays");
    glGetAttribLocation_ptr = (PFNGLGETATTRIBLOCATIONPROC) platform_load_gl_function("glGetAttribLocation");
    glBindVertexArray_ptr = (PFNGLBINDVERTEXARRAYPROC) platform_load_gl_function("glBindVertexArray");
    glEnableVertexAttribArray_ptr = (PFNGLENABLEVERTEXATTRIBARRAYPROC) platform_load_gl_function("glEnableVertexAttribArray");
    glVertexAttribPointer_ptr = (PFNGLVERTEXATTRIBPOINTERPROC) platform_load_gl_function("glVertexAttribPointer");
    glBindBuffer_ptr = (PFNGLBINDBUFFERPROC) platform_load_gl_function("glBindBuffer");
    glBindBufferBase_ptr = (PFNGLBINDBUFFERBASEPROC) platform_load_gl_function("glBindBufferBase");
    glBufferData_ptr = (PFNGLBUFFERDATAPROC) platform_load_gl_function("glBufferData");
    glGetVertexAttribPointerv_ptr = (PFNGLGETVERTEXATTRIBPOINTERVPROC) platform_load_gl_function("glGetVertexAttribPointerv");
    glUseProgram_ptr = (PFNGLUSEPROGRAMPROC) platform_load_gl_function("glUseProgram");
    glDeleteVertexArrays_ptr = (PFNGLDELETEVERTEXARRAYSPROC) platform_load_gl_function("glDeleteVertexArrays");
    glDeleteBuffers_ptr = (PFNGLDELETEBUFFERSPROC) platform_load_gl_function("glDeleteBuffers");
    glDeleteProgram_ptr = (PFNGLDELETEPROGRAMPROC) platform_load_gl_function("glDeleteProgram");
    glDetachShader_ptr = (PFNGLDETACHSHADERPROC) platform_load_gl_function("glDetachShader");
    glDeleteShader_ptr = (PFNGLDELETESHADERPROC) platform_load_gl_function("glDeleteShader");
    glDrawElementsInstanced_ptr = (PFNGLDRAWELEMENTSINSTANCEDPROC) platform_load_gl_function("glDrawElementsInstanced");
    glGenerateMipmap_ptr = (PFNGLGENERATEMIPMAPPROC) platform_load_gl_function("glGenerateMipmap");
    glDebugMessageCallback_ptr = (PFNGLDEBUGMESSAGECALLBACKPROC)platform_load_gl_function("glDebugMessageCallback");
    
    //##### ---Pointers I Personally included seperate from above--- #####
    glCullFace_ptr = (PFNGLCULLFACEPROC)platform_load_gl_function("glCullFace");
    glFrontFace_ptr = (PFNGLFRONTFACEPROC)platform_load_gl_function("glFrontFace");
    glHint_ptr = (PFNGLHINTPROC)platform_load_gl_function("glHint");
    glLineWidth_ptr = (PFNGLLINEWIDTHPROC)platform_load_gl_function("glLineWidth");
    glPointSize_ptr = (PFNGLPOINTSIZEPROC)platform_load_gl_function("glPointSize");
    glPolygonMode_ptr = (PFNGLPOLYGONMODEPROC)platform_load_gl_function("glPolygonMode");
    glScissor_ptr = (PFNGLSCISSORPROC)platform_load_gl_function("glScissor");
    glTexParameterf_ptr = (PFNGLTEXPARAMETERFPROC)platform_load_gl_function("glTexParameterf");
    glTexParameterfv_ptr = (PFNGLTEXPARAMETERFVPROC)platform_load_gl_function("glTexParameterfv");
    glTexParameteri_ptr = (PFNGLTEXPARAMETERIPROC)platform_load_gl_function("glTexParameteri");
    glTexParameteriv_ptr = (PFNGLTEXPARAMETERIVPROC)platform_load_gl_function("glTexParameteriv");
    glTexImage1D_ptr = (PFNGLTEXIMAGE1DPROC)platform_load_gl_function("glTexImage1D");
    glTexImage2D_ptr = (PFNGLTEXIMAGE2DPROC)platform_load_gl_function("glTexImage2D");
    glClear_ptr = (PFNGLCLEARPROC)platform_load_gl_function("glClear");
    glClearColor_ptr = (PFNGLCLEARCOLORPROC)platform_load_gl_function("glClearColor");
    glClearStencil_ptr = (PFNGLCLEARSTENCILPROC)platform_load_gl_function("glClearStencil");
    glClearDepth_ptr = (PFNGLCLEARDEPTHPROC)platform_load_gl_function("glClearDepth");
    glStencilMask_ptr = (PFNGLSTENCILMASKPROC)platform_load_gl_function("glStencilMask");
    glColorMask_ptr = (PFNGLCOLORMASKPROC)platform_load_gl_function("glColorMask");
    glDepthMask_ptr = (PFNGLDEPTHMASKPROC)platform_load_gl_function("glDepthMask");
    glDisable_ptr = (PFNGLDISABLEPROC)platform_load_gl_function("glDisable");
    glEnable_ptr = (PFNGLENABLEPROC)platform_load_gl_function("glEnable");
    glFinish_ptr = (PFNGLFINISHPROC)platform_load_gl_function("glFinish");
    glFlush_ptr = (PFNGLFLUSHPROC)platform_load_gl_function("glFlush");
    glBlendFunc_ptr = (PFNGLBLENDFUNCPROC)platform_load_gl_function("glBlendFunc");
    glLogicOp_ptr = (PFNGLLOGICOPPROC)platform_load_gl_function("glLogicOp");
    glStencilFunc_ptr = (PFNGLSTENCILFUNCPROC)platform_load_gl_function("glStencilFunc");
    glStencilOp_ptr = (PFNGLSTENCILOPPROC)platform_load_gl_function("glStencilOp");
    glDepthFunc_ptr = (PFNGLDEPTHFUNCPROC)platform_load_gl_function("glDepthFunc");
    glPixelStoref_ptr = (PFNGLPIXELSTOREFPROC)platform_load_gl_function("glPixelStoref");
    glPixelStorei_ptr = (PFNGLPIXELSTOREIPROC)platform_load_gl_function("glPixelStorei");
    glReadBuffer_ptr = (PFNGLREADBUFFERPROC)platform_load_gl_function("glReadBuffer");
    glReadPixels_ptr = (PFNGLREADPIXELSPROC)platform_load_gl_function("glReadPixels");
    glGetBooleanv_ptr = (PFNGLGETBOOLEANVPROC)platform_load_gl_function("glGetBooleanv");
    glGetDoublev_ptr = (PFNGLGETDOUBLEVPROC)platform_load_gl_function("glGetDoublev");
    glGetError_ptr = (PFNGLGETERRORPROC)platform_load_gl_function("glGetError");
    glGetFloatv_ptr = (PFNGLGETFLOATVPROC)platform_load_gl_function("glGetFloatv");
    glGetIntegerv_ptr = (PFNGLGETINTEGERVPROC)platform_load_gl_function("glGetIntegerv");
    glGetString_ptr = (PFNGLGETSTRINGPROC)platform_load_gl_function("glGetString");
    glGetTexImage_ptr = (PFNGLGETTEXIMAGEPROC)platform_load_gl_function("glGetTexImage");
    glGetTexParameterfv_ptr = (PFNGLGETTEXPARAMETERFVPROC)platform_load_gl_function("glGetTexParameterfv");
    glGetTexParameteriv_ptr = (PFNGLGETTEXPARAMETERIVPROC)platform_load_gl_function("glGetTexParameteriv");
    glGetTexLevelParameterfv_ptr = (PFNGLGETTEXLEVELPARAMETERFVPROC)platform_load_gl_function("glGetTexLevelParameterfv");
    glGetTexLevelParameteriv_ptr = (PFNGLGETTEXLEVELPARAMETERIVPROC)platform_load_gl_function("glGetTexLevelParameteriv");
    glIsEnabled_ptr = (PFNGLISENABLEDPROC)platform_load_gl_function("glIsEnabled");
    glDepthRange_ptr = (PFNGLDEPTHRANGEPROC)platform_load_gl_function("glDepthRange");
    glViewport_ptr = (PFNGLVIEWPORTPROC)platform_load_gl_function("glViewport");
}

void gl_load_extensions(){
    
    //##### ---Windows Extension Functions--- #####
    #ifdef  _WIN32    
    wglChoosePixelFormatARB_ptr = (PFNWGLCHOOSEPIXELFORMATARBPROC)platform_load_gl_function("wglChoosePixelFormatARB");
    wglCreateContextAttribsARB_ptr = (PFNWGLCREATECONTEXTATTRIBSARBPROC)platform_load_gl_function("wglCreateContextAttribsARB");
    #endif//_WIN32
    
    //##### ---Linux Extension Functions--- #####
    #ifdef  __linux__
    #endif//__linux__
    
    //##### ---Macintosh Extension Functions--- #####
    #ifdef  __APPLE__
    #endif//__APPLE__
}

//##################################################################################################################################
//                                                        Pointer Wrappers
//##################################################################################################################################

GLuint glCreateProgram() { return glCreateProgram_ptr(); }
void glDeleteTextures(GLsizei n, const GLuint *textures) { glDeleteTextures_ptr(n, textures); }
void glGenTextures(GLsizei n, GLuint *textures) { glGenTextures_ptr(n, textures); }
void glBindTexture(GLenum target, GLuint texture) { glBindTexture_ptr(target, texture); }
void glDrawArrays(GLenum mode, GLint first, GLsizei count) { glDrawArrays_ptr(mode, first, count); }
GLuint glCreateShader(GLenum shaderType) { return glCreateShader_ptr(shaderType); }
GLint glGetUniformLocation(GLuint program, const GLchar* name) { return glGetUniformLocation_ptr(program, name); }
void glUniform1f(GLint location, GLfloat v0) { glUniform1f_ptr(location, v0); }
void glUniform2fv(GLint location, GLsizei count, const GLfloat* value) { glUniform2fv_ptr(location, count, value); }
void glUniform3fv(GLint location, GLsizei count, const GLfloat* value) { glUniform3fv_ptr(location, count, value); }
void glUniform1i(GLint location, GLint v0) { glUniform1i_ptr(location, v0); }
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) { glUniformMatrix4fv_ptr(location, count, transpose, value); }
void glVertexAttribDivisor(GLuint index, GLuint divisor) { glVertexAttribDivisor_ptr(index, divisor); }
void glActiveTexture(GLenum texture) { glActiveTexture_ptr(texture); }
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) { glBufferSubData_ptr(target, offset, size, data); }
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount) { glDrawArraysInstanced_ptr(mode, first, count, instanceCount); }
void glBindFramebuffer(GLenum target, GLuint framebuffer) { glBindFramebuffer_ptr(target, framebuffer); }
GLenum glCheckFramebufferStatus(GLenum target) { return glCheckFramebufferStatus_ptr(target); }
void glGenFramebuffers(GLsizei n, GLuint* framebuffers) { glGenFramebuffers_ptr(n, framebuffers); }
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glFramebufferTexture2D_ptr(target, attachment, textarget, texture, level); }
void glDrawBuffers(GLsizei n, const GLenum* bufs) { glDrawBuffers_ptr(n, bufs); }
void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) { glDeleteFramebuffers_ptr(n, framebuffers); }
void glBlendFunci(GLuint buf, GLenum src, GLenum dst) { glBlendFunci_ptr(buf, src, dst); }
void glBlendEquation(GLenum mode) { glBlendEquation_ptr(mode); }
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) { glClearBufferfv_ptr(buffer, drawbuffer, value); }
void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* strings, const GLint* lengths) { glShaderSource_ptr(shader, count, strings, lengths); }
void glCompileShader(GLuint shader) { glCompileShader_ptr(shader); }
void glGetShaderiv(GLuint shader, GLenum pname, GLint* params) { glGetShaderiv_ptr(shader, pname, params); }
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glGetShaderInfoLog_ptr(shader, bufSize, length, infoLog); }
void glAttachShader(GLuint program, GLuint shader) { glAttachShader_ptr(program, shader); }
void glLinkProgram(GLuint program) { glLinkProgram_ptr(program); }
void glValidateProgram(GLuint program) { glValidateProgram_ptr(program); }
void glGetProgramiv(GLuint program, GLenum pname, GLint* params) { glGetProgramiv_ptr(program, pname, params); }
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) { glGetProgramInfoLog_ptr(program, bufSize, length, infoLog); }
void glGenBuffers(GLsizei n, GLuint* buffers) { glGenBuffers_ptr(n, buffers); }
void glGenVertexArrays(GLsizei n, GLuint* arrays) { glGenVertexArrays_ptr(n, arrays); }
GLint glGetAttribLocation(GLuint program, const GLchar* name) { return glGetAttribLocation_ptr(program, name); }
void glBindVertexArray(GLuint array) { glBindVertexArray_ptr(array); }
void glEnableVertexAttribArray(GLuint index) { glEnableVertexAttribArray_ptr(index); }
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) { glVertexAttribPointer_ptr(index, size, type, normalized, stride, pointer); }
void glBindBuffer(GLenum target, GLuint buffer) { glBindBuffer_ptr(target, buffer); }
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { glBindBufferBase_ptr(target, index, buffer); }
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) { glBufferData_ptr(target, size, data, usage); }
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer) { glGetVertexAttribPointerv_ptr(index, pname, pointer); }
void glUseProgram(GLuint program) { glUseProgram_ptr(program); }
void glDeleteVertexArrays(GLsizei n, const GLuint* arrays) { glDeleteVertexArrays_ptr(n, arrays); }
void glDeleteBuffers(GLsizei n, const GLuint* buffers) { glDeleteBuffers_ptr(n, buffers); }
void glDeleteProgram(GLuint program) { glDeleteProgram_ptr(program); }
void glDetachShader(GLuint program, GLuint shader) { glDetachShader_ptr(program, shader); }
void glDeleteShader(GLuint shader) { glDeleteShader_ptr(shader); }
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) { glDrawElementsInstanced_ptr(mode, count, type, indices, instancecount); }
void glGenerateMipmap(GLenum target) { glGenerateMipmap_ptr(target); }
void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) { glDebugMessageCallback_ptr(callback, userParam); }

//##### ---Wrappers for personally included pointers--- #####
void glCullFace(GLenum mode) { glCullFace_ptr(mode); }
void glFrontFace(GLenum mode) { glFrontFace_ptr(mode); }
void glHint(GLenum target, GLenum mode) { glHint_ptr(target, mode); }
void glLineWidth(GLfloat width) { glLineWidth_ptr(width); }
void glPointSize(GLfloat size) { glPointSize_ptr(size); }
void glPolygonMode(GLenum face, GLenum mode) { glPolygonMode_ptr(face, mode); }
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { glScissor_ptr(x, y, width, height); }
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) { glTexParameterf_ptr(target, pname, param); }
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { glTexParameterfv_ptr(target, pname, params); }
void glTexParameteri(GLenum target, GLenum pname, GLint param) { glTexParameteri_ptr(target, pname, param); }
void glTexParameteriv(GLenum target, GLenum pname, const GLint *params) { glTexParameteriv_ptr(target, pname, params); }
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) { glTexImage1D_ptr(target, level, internalformat, width, border, format, type, pixels); }
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) { glTexImage2D_ptr(target, level, internalformat, width, height, border, format, type, pixels); }
void glClear(GLbitfield mask) { glClear_ptr(mask); }
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glClearColor_ptr(red, green, blue, alpha); }
void glClearStencil(GLint s) { glClearStencil_ptr(s); }
void glClearDepth(GLdouble depth) { glClearDepth_ptr(depth); }
void glStencilMask(GLuint mask) { glStencilMask_ptr(mask); }
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glColorMask_ptr(red, green, blue, alpha); }
void glDepthMask(GLboolean flag) { glDepthMask_ptr(flag); }
void glDisable(GLenum cap) { glDisable_ptr(cap); }
void glEnable(GLenum cap) { glEnable_ptr(cap); }
void glFinish(void) { glFinish_ptr(); }
void glFlush(void) { glFlush_ptr(); }
void glBlendFunc(GLenum sfactor, GLenum dfactor) { glBlendFunc_ptr(sfactor, dfactor); }
void glLogicOp(GLenum opcode) { glLogicOp_ptr(opcode); }
void glStencilFunc(GLenum func, GLint ref, GLuint mask) { glStencilFunc_ptr(func, ref, mask); }
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glStencilOp_ptr(fail, zfail, zpass); }
void glDepthFunc(GLenum func) { glDepthFunc_ptr(func); }
void glPixelStoref(GLenum pname, GLfloat param) { glPixelStoref_ptr(pname, param); }
void glPixelStorei(GLenum pname, GLint param) { glPixelStorei_ptr(pname, param); }
void glReadBuffer(GLenum src) { glReadBuffer_ptr(src); }
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) { glReadPixels_ptr(x, y, width, height, format, type, pixels); }
void glGetBooleanv(GLenum pname, GLboolean *data) { glGetBooleanv_ptr(pname, data); }
void glGetDoublev(GLenum pname, GLdouble *data) { glGetDoublev_ptr(pname, data); }
GLenum glGetError(void) { return glGetError_ptr(); }
void glGetFloatv(GLenum pname, GLfloat *data) { glGetFloatv_ptr(pname, data); }
void glGetIntegerv(GLenum pname, GLint *data) { glGetIntegerv_ptr(pname, data); }
const GLubyte *glGetString(GLenum name) { return glGetString_ptr(name); }
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) { glGetTexImage_ptr(target, level, format, type, pixels); }
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { glGetTexParameterfv_ptr(target, pname, params); }
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) { glGetTexParameteriv_ptr(target, pname, params); }
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { glGetTexLevelParameterfv_ptr(target, level, pname, params); }
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { glGetTexLevelParameteriv_ptr(target, level, pname, params); }
GLboolean glIsEnabled(GLenum cap) { return glIsEnabled_ptr(cap); }
void glDepthRange(GLdouble n, GLdouble f) { glDepthRange_ptr(n, f); }
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport_ptr(x, y, width, height); }


//##### ---Windows Extension Functions--- #####
#ifdef  _WIN32

BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats){
    return wglChoosePixelFormatARB_ptr(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}
HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList){
    return wglCreateContextAttribsARB_ptr(hDC, hShareContext, attribList);
}

#endif//_WIN32


//##################################################################################################################################
//                                                            Structs
//##################################################################################################################################
//##################################################################################################################################
//                                                            Globals
//##################################################################################################################################
//##################################################################################################################################
//                                                           Functions
//##################################################################################################################################

void APIENTRY gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user){
    
    if(severity == GL_DEBUG_SEVERITY_LOW || severity == GL_DEBUG_SEVERITY_MEDIUM || severity == GL_DEBUG_SEVERITY_HIGH){
        SM_ASSERT(false, "OpenGL Error: %s", message);
    }else{
        SM_TRACE((const char*)message);
    }       
}

bool gl_init(BumpAllocator* transientStorage){
    
    //gl_load_functions();
    glDebugMessageCallback(&gl_debug_callback, nullptr);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glEnable(GL_DEBUG_OUTPUT);
    
    GLuint vertShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    int fileSize = 0;
    char* vertShader = read_file( "assets/shaders/quad.vert", &fileSize, transientStorage);
    char* fragShader = read_file( "assets/shaders/quad.frag", &fileSize, transientStorage);
    
    if(!vertShader || !fragShader){
        SM_ASSERT(false, "Failed to load shaders");
        return false;
    }
    
    glShaderSource(vertShaderID, 1, &vertShader, 0);
    glShaderSource(fragShaderID, 1, &fragShader, 0);
    
    glCompileShader(vertShaderID);
    glCompileShader(fragShaderID);
    
    int success;
    char shaderLog[2048] = {};
    glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertShaderID, 2048, 0, shaderLog);
        SM_ASSERT(false, "Failed to compile Vertex Shaders %s", shaderLog);
    }
    success = 0;
    memset(shaderLog, 0, sizeof(shaderLog));
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragShaderID, 2048, 0, shaderLog);
        SM_ASSERT(false, "Failed to compile Vertex Shaders %s", shaderLog);
    }
    
    glContext.programID = glCreateProgram();
    glAttachShader(glContext.programID, vertShaderID);
    glAttachShader(glContext.programID, fragShaderID);
    glLinkProgram(glContext.programID);
    
    glDetachShader(glContext.programID, vertShaderID);
    glDetachShader(glContext.programID, fragShaderID);
    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);
    
    // This must be done. Without this, OpenGL won't draw anything.
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    
    // Depth Testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_GREATER);
    glUseProgram(glContext.programID);
    return true;
}

void gl_render(){
    glClearColor(119.0f / 255.0f, 33.0f / 255.0f, 111.0f / 255.0f, 1.0f);
    glClearDepth(0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, input.screenSizeX, input.screenSizeY);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}