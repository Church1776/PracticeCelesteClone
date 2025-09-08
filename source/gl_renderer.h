#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#include <GL/glcorearb.h>

//##### ---Forward Declarations--- #####
struct BumpAllocator;

//##################################################################################################################################
//                                                          Function Pointers
//##################################################################################################################################

inline PFNGLCREATEPROGRAMPROC glCreateProgram_ptr;
inline PFNGLDELETETEXTURESPROC glDeleteTextures_ptr;
inline PFNGLGENTEXTURESPROC glGenTextures_ptr;
inline PFNGLBINDTEXTUREPROC glBindTexture_ptr;
inline PFNGLDRAWBUFFERPROC glDrawBuffer_ptr;
inline PFNGLDRAWARRAYSPROC glDrawArrays_ptr;
inline PFNGLCREATESHADERPROC glCreateShader_ptr;
inline PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_ptr;
inline PFNGLUNIFORM1FPROC glUniform1f_ptr;
inline PFNGLUNIFORM2FVPROC glUniform2fv_ptr;
inline PFNGLUNIFORM3FVPROC glUniform3fv_ptr;
inline PFNGLUNIFORM1IPROC glUniform1i_ptr;
inline PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv_ptr;
inline PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor_ptr;
inline PFNGLACTIVETEXTUREPROC glActiveTexture_ptr;
inline PFNGLBUFFERSUBDATAPROC glBufferSubData_ptr;
inline PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced_ptr;
inline PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer_ptr;
inline PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus_ptr;
inline PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers_ptr;
inline PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D_ptr;
inline PFNGLDRAWBUFFERSPROC glDrawBuffers_ptr;
inline PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers_ptr;
inline PFNGLBLENDFUNCIPROC glBlendFunci_ptr;
inline PFNGLBLENDEQUATIONPROC glBlendEquation_ptr;
inline PFNGLCLEARBUFFERFVPROC glClearBufferfv_ptr;
inline PFNGLSHADERSOURCEPROC glShaderSource_ptr;
inline PFNGLCOMPILESHADERPROC glCompileShader_ptr;
inline PFNGLGETSHADERIVPROC glGetShaderiv_ptr;
inline PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_ptr;
inline PFNGLATTACHSHADERPROC glAttachShader_ptr;
inline PFNGLLINKPROGRAMPROC glLinkProgram_ptr;
inline PFNGLVALIDATEPROGRAMPROC glValidateProgram_ptr;
inline PFNGLGETPROGRAMIVPROC glGetProgramiv_ptr;
inline PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_ptr;
inline PFNGLGENBUFFERSPROC glGenBuffers_ptr;
inline PFNGLGENVERTEXARRAYSPROC glGenVertexArrays_ptr;
inline PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation_ptr;
inline PFNGLBINDVERTEXARRAYPROC glBindVertexArray_ptr;
inline PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray_ptr;
inline PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer_ptr;
inline PFNGLBINDBUFFERPROC glBindBuffer_ptr;
inline PFNGLBINDBUFFERBASEPROC glBindBufferBase_ptr;
inline PFNGLBUFFERDATAPROC glBufferData_ptr;
inline PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv_ptr;
inline PFNGLUSEPROGRAMPROC glUseProgram_ptr;
inline PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays_ptr;
inline PFNGLDELETEBUFFERSPROC glDeleteBuffers_ptr;
inline PFNGLDELETEPROGRAMPROC glDeleteProgram_ptr;
inline PFNGLDETACHSHADERPROC glDetachShader_ptr;
inline PFNGLDELETESHADERPROC glDeleteShader_ptr;
inline PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced_ptr;
inline PFNGLGENERATEMIPMAPPROC glGenerateMipmap_ptr;
inline PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback_ptr;

//##### ---Pointers I Personally Included Seperate from above--- #####
inline PFNGLCULLFACEPROC glCullFace_ptr;
inline PFNGLFRONTFACEPROC glFrontFace_ptr;
inline PFNGLHINTPROC glHint_ptr;
inline PFNGLLINEWIDTHPROC glLineWidth_ptr;
inline PFNGLPOINTSIZEPROC glPointSize_ptr;
inline PFNGLPOLYGONMODEPROC glPolygonMode_ptr;
inline PFNGLSCISSORPROC glScissor_ptr;
inline PFNGLTEXPARAMETERFPROC glTexParameterf_ptr;
inline PFNGLTEXPARAMETERFVPROC glTexParameterfv_ptr;
inline PFNGLTEXPARAMETERIPROC glTexParameteri_ptr;
inline PFNGLTEXPARAMETERIVPROC glTexParameteriv_ptr;
inline PFNGLTEXIMAGE1DPROC glTexImage1D_ptr;
inline PFNGLTEXIMAGE2DPROC glTexImage2D_ptr;
inline PFNGLCLEARPROC glClear_ptr;
inline PFNGLCLEARCOLORPROC glClearColor_ptr;
inline PFNGLCLEARSTENCILPROC glClearStencil_ptr;
inline PFNGLCLEARDEPTHPROC glClearDepth_ptr;
inline PFNGLSTENCILMASKPROC glStencilMask_ptr;
inline PFNGLCOLORMASKPROC glColorMask_ptr;
inline PFNGLDEPTHMASKPROC glDepthMask_ptr;
inline PFNGLDISABLEPROC glDisable_ptr;
inline PFNGLENABLEPROC glEnable_ptr;
inline PFNGLFINISHPROC glFinish_ptr;
inline PFNGLFLUSHPROC glFlush_ptr;
inline PFNGLBLENDFUNCPROC glBlendFunc_ptr;
inline PFNGLLOGICOPPROC glLogicOp_ptr;
inline PFNGLSTENCILFUNCPROC glStencilFunc_ptr;
inline PFNGLSTENCILOPPROC glStencilOp_ptr;
inline PFNGLDEPTHFUNCPROC glDepthFunc_ptr;
inline PFNGLPIXELSTOREFPROC glPixelStoref_ptr;
inline PFNGLPIXELSTOREIPROC glPixelStorei_ptr;
inline PFNGLREADBUFFERPROC glReadBuffer_ptr;
inline PFNGLREADPIXELSPROC glReadPixels_ptr;
inline PFNGLGETBOOLEANVPROC glGetBooleanv_ptr;
inline PFNGLGETDOUBLEVPROC glGetDoublev_ptr;
inline PFNGLGETERRORPROC glGetError_ptr;
inline PFNGLGETFLOATVPROC glGetFloatv_ptr;
inline PFNGLGETINTEGERVPROC glGetIntegerv_ptr;
inline PFNGLGETSTRINGPROC glGetString_ptr;
inline PFNGLGETTEXIMAGEPROC glGetTexImage_ptr;
inline PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv_ptr;
inline PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv_ptr;
inline PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv_ptr;
inline PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv_ptr;
inline PFNGLISENABLEDPROC glIsEnabled_ptr;
inline PFNGLDEPTHRANGEPROC glDepthRange_ptr;
inline PFNGLVIEWPORTPROC glViewport_ptr;

//##### ---For Windows Extensions--- #####
#ifdef  _WIN32
#include <GL/wglext.h>
inline PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB_ptr;
inline PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB_ptr;
#endif//_WIN32

//##################################################################################################################################
//                                                   Pointer Assignment Functions
//##################################################################################################################################

void gl_load_functions();  //### <--This will assign the pointers to their respective function.
void gl_load_platform_extensions(); //### <--This is for platform specific extensions.

//##################################################################################################################################
//                                                        Pointer Wrappers
//##################################################################################################################################


//##### --This will allow calling the OpenGL functions using their normal names--#####

GLAPI GLuint APIENTRY glCreateProgram(void);
GLAPI void APIENTRY glDeleteTextures(GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures(GLsizei n, GLuint *textures);
GLAPI void APIENTRY glBindTexture(GLenum target, GLuint texture);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
GLuint glCreateShader(GLenum shaderType);
GLint glGetUniformLocation(GLuint program, const GLchar* name);
void glUniform1f(GLint location, GLfloat v0);
void glUniform2fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform3fv(GLint location, GLsizei count, const GLfloat* value);
void glUniform1i(GLint location, GLint v0);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void glVertexAttribDivisor(GLuint index, GLuint divisor);
void glActiveTexture(GLenum texture);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
GLenum glCheckFramebufferStatus(GLenum target);
void glGenFramebuffers(GLsizei n, GLuint* framebuffers);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glDrawBuffers(GLsizei n, const GLenum* bufs);
void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
void glBlendEquation(GLenum mode);
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value);
void glShaderSource(GLuint shader, GLsizei count, const GLchar* const* strings, const GLint* lengths);
void glCompileShader(GLuint shader);
void glGetShaderiv(GLuint shader, GLenum pname, GLint* params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glAttachShader(GLuint program, GLuint shader);
void glLinkProgram(GLuint program);
void glValidateProgram(GLuint program);
void glGetProgramiv(GLuint program, GLenum pname, GLint* params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
void glGenBuffers(GLsizei n, GLuint* buffers);
void glGenVertexArrays(GLsizei n, GLuint* arrays);
GLint glGetAttribLocation(GLuint program, const GLchar* name);
void glBindVertexArray(GLuint array);
void glEnableVertexAttribArray(GLuint index);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer);
void glUseProgram(GLuint program);
void glDeleteVertexArrays(GLsizei n, const GLuint* arrays);
void glDeleteBuffers(GLsizei n, const GLuint* buffers);
void glDeleteProgram(GLuint program);
void glDetachShader (GLuint program, GLuint shader);
void glDeleteShader(GLuint shader);
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
void glGenerateMipmap(GLenum target);
void glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);

//##### ---Personal added wrappers--- #####
GLAPI void APIENTRY glCullFace(GLenum mode);
GLAPI void APIENTRY glFrontFace(GLenum mode);
GLAPI void APIENTRY glHint(GLenum target, GLenum mode);
GLAPI void APIENTRY glLineWidth(GLfloat width);
GLAPI void APIENTRY glPointSize(GLfloat size);
GLAPI void APIENTRY glPolygonMode(GLenum face, GLenum mode);
GLAPI void APIENTRY glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexParameterf(GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteri(GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexParameteriv(GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glDrawBuffer(GLenum buf);
GLAPI void APIENTRY glClear(GLbitfield mask);
GLAPI void APIENTRY glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glClearStencil(GLint s);
GLAPI void APIENTRY glClearDepth(GLdouble depth);
GLAPI void APIENTRY glStencilMask(GLuint mask);
GLAPI void APIENTRY glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void APIENTRY glDepthMask(GLboolean flag);
GLAPI void APIENTRY glDisable(GLenum cap);
GLAPI void APIENTRY glEnable(GLenum cap);
GLAPI void APIENTRY glFinish(void);
GLAPI void APIENTRY glFlush(void);
GLAPI void APIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor);
GLAPI void APIENTRY glLogicOp(GLenum opcode);
GLAPI void APIENTRY glStencilFunc(GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void APIENTRY glDepthFunc(GLenum func);
GLAPI void APIENTRY glPixelStoref(GLenum pname, GLfloat param);
GLAPI void APIENTRY glPixelStorei(GLenum pname, GLint param);
GLAPI void APIENTRY glReadBuffer(GLenum src);
GLAPI void APIENTRY glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetBooleanv(GLenum pname, GLboolean *data);
GLAPI void APIENTRY glGetDoublev(GLenum pname, GLdouble *data);
GLAPI GLenum APIENTRY glGetError(void);
GLAPI void APIENTRY glGetFloatv(GLenum pname, GLfloat *data);
GLAPI void APIENTRY glGetIntegerv(GLenum pname, GLint *data);
GLAPI const GLubyte *APIENTRY glGetString(GLenum name);
GLAPI void APIENTRY glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsEnabled(GLenum cap);
GLAPI void APIENTRY glDepthRange(GLdouble n, GLdouble f);
GLAPI void APIENTRY glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

//##### ---For Windows Extensions--- #####
#ifdef  _WIN32
BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList);
#endif//_WIN32
//##################################################################################################################################
//                                                          Structs
//##################################################################################################################################

struct GLContext{
    GLuint programID;
};

//##################################################################################################################################
//                                                          Globals
//##################################################################################################################################

inline GLContext glContext;

//##################################################################################################################################
//                                                         Functions
//##################################################################################################################################

void APIENTRY gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user);
bool gl_init(BumpAllocator* transientStorage); 
void gl_render();
#endif//GL_RENDERER_H