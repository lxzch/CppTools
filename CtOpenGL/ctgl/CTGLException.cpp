#include "stdafx.h"
#include <exception\CTGLException.h>

//CTGLExceptionBase

//CTGLInitFail

const char* CppTools::CTException::CTGLException::CTGLInitFail::what() const throw()
{
	return "Error: while initializing OpenGL";
}

const std::string CppTools::CTException::CTGLException::CTGLInitFail::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL初始化失败";
	return msg;
}

//CTGLTextureExceptionBase

CppTools::CTException::CTGLException::CTGLTextureExceptionBase::CTGLTextureExceptionBase(const int& texture_id)
					: id(texture_id)
{
}

void CppTools::CTException::CTGLException::CTGLTextureExceptionBase::setId(const int& texture_id)
{
	id = texture_id;
}

int CppTools::CTException::CTGLException::CTGLTextureExceptionBase::getId() const
{
	return id.getData();
}

const char* CppTools::CTException::CTGLException::CTGLTextureExceptionBase::what() const throw()
{
	return "Error: while operating texture in OpenGL";
}

const std::string CppTools::CTException::CTGLException::CTGLTextureExceptionBase::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL操作纹理时失败\n纹理号: ";
	msg = msg + id.toString();
	return msg;
}

//CTGLTextureNULL

CppTools::CTException::CTGLException::CTGLTextureNULL::CTGLTextureNULL(const int& texture_id)
					: CTGLTextureExceptionBase(texture_id)
{
}

const char* CppTools::CTException::CTGLException::CTGLTextureNULL::what() const throw()
{
	return "Error: invalid texture";
}

const std::string CppTools::CTException::CTGLException::CTGLTextureNULL::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: 无效的纹理\n纹理号: " + id.toString();
	return msg;
}

//CTGLTextureNoBind

CppTools::CTException::CTGLException::CTGLTextureNoBind::CTGLTextureNoBind(const int& texture_id)
					: CTGLTextureExceptionBase(texture_id)
{
}

const char* CppTools::CTException::CTGLException::CTGLTextureNoBind::what() const throw()
{
	return "Error: inactive texture";
}

const std::string CppTools::CTException::CTGLException::CTGLTextureNoBind::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: 纹理还没有被绑定\n纹理号: " + id.toString();
	return msg;
}

//CTGLTextureFail

CppTools::CTException::CTGLException::CTGLTextureFail::CTGLTextureFail(const int& texture_id)
					: CTGLTextureExceptionBase(texture_id)
{
}

const char* CppTools::CTException::CTGLException::CTGLTextureFail::what() const throw()
{
	return "Error: while operating texture in OpenGL";
}

const std::string CppTools::CTException::CTGLException::CTGLTextureFail::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL操作纹理时失败\n纹理号: " + id.toString();
	return msg;
}

//CTGLMipmapFail

CppTools::CTException::CTGLException::CTGLMipmapFail::CTGLMipmapFail(const int& mipmap_id)
					: CTGLTextureExceptionBase(mipmap_id)
{
}

const char* CppTools::CTException::CTGLException::CTGLMipmapFail::what() const throw()
{
	return "Error: there are one or more surfaces uninitializational or incorrespond in the cube";
}

const std::string CppTools::CTException::CTGLException::CTGLMipmapFail::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL操作多层次纹理Mipmap时失败,确认所有的立方体表面都已初始化并保持一致\n纹理号: " + id.toString();
	return msg;
}

//CTGLEWInitFail

CppTools::CTException::CTGLException::CTGLEWInitFail::CTGLEWInitFail(const GLubyte* gl_version)
					:gl_version(gl_version)
{
}

const char* CppTools::CTException::CTGLException::CTGLEWInitFail::what() const throw()
{
	return "Error: while initializing GLEW";
}

const std::string CppTools::CTException::CTGLException::CTGLEWInitFail::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL扩展库 - GLEW 初始化失败 , 当前OpenGL库版本是:";
	msg += (const char*)gl_version;
	return msg;
}

//CTGLSLComplieException

CppTools::CTException::CTGLException::CTGLSLComplieException::CTGLSLComplieException(const GLuint& error_device)
					:error_device(error_device)
{
	glGetShaderiv(error_device, GL_INFO_LOG_LENGTH, &length);
	log = (GLchar*)malloc(length);
	glGetShaderInfoLog(error_device, length, &length, log);
}

const char* CppTools::CTException::CTGLException::CTGLSLComplieException::what() const throw()
{
	return (char*)log;
}

const std::string CppTools::CTException::CTGLException::CTGLSLComplieException::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL着色器编译失败\n提示信息: ";
	msg += (char*)log;
	return msg;
}

//CTGLSLLinkException

CppTools::CTException::CTGLException::CTGLSLLinkException::CTGLSLLinkException(const GLuint& error_device)
					:error_device(error_device)
{
	glGetProgramiv(error_device, GL_INFO_LOG_LENGTH, &length);
	log = (GLchar*)malloc(length);
	glGetProgramInfoLog(error_device, length, &length, log);
}

const char* CppTools::CTException::CTGLException::CTGLSLLinkException::what() const throw()
{
	return (char*)log;
}

const std::string CppTools::CTException::CTGLException::CTGLSLLinkException::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: OpenGL着色器链接失败\n提示信息: ";
	msg += (char*)log;
	return msg;
}

//CTGLWindowsExceptionBase

CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::CTGLWindowsExceptionBase(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: context(context), title(title), wnd_type(wnd_type)
{
}

void CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::setContext(const std::string& new_context)
{
	context = new_context;
}

std::string CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::getContext() const
{
	return context;
}

void CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::setWndTitle(const std::string& new_title)
{
	title = new_title;
}

std::string CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::getWndTitle() const
{
	return title;
}

void CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::setWndType(unsigned int new_type)
{
	wnd_type = new_type;
}

unsigned int CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::getWndType() const
{
	return wnd_type;
}

const char* CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::what() const throw()
{
	return "Error: when run a window for OpenGL";
}

const std::string CppTools::CTException::CTGLException::CTGLWindowsExceptionBase::c_what() const throw()
{
	std::string msg;
	msg = "发生错误: 为OpenGL生成窗口时失败\n: " + context;
	return msg;
}

//CTGLWndNotRegister

CppTools::CTException::CTGLException::CTGLWndNotRegister::CTGLWndNotRegister(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndClose

CppTools::CTException::CTGLException::CTGLWndClose::CTGLWndClose(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndNotCreate

CppTools::CTException::CTGLException::CTGLWndNotCreate::CTGLWndNotCreate(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrHDC

CppTools::CTException::CTGLException::CTGLWndErrHDC::CTGLWndErrHDC(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrPFD

CppTools::CTException::CTGLException::CTGLWndErrPFD::CTGLWndErrPFD(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrSetPFD

CppTools::CTException::CTGLException::CTGLWndErrSetPFD::CTGLWndErrSetPFD(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrHRC

CppTools::CTException::CTGLException::CTGLWndErrHRC::CTGLWndErrHRC(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrCurrentHRC

CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC::CTGLWndErrCurrentHRC(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrInit

CppTools::CTException::CTGLException::CTGLWndErrInit::CTGLWndErrInit(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrRelease

CppTools::CTException::CTGLException::CTGLWndErrRelease::CTGLWndErrRelease(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrReleaseHRC

CppTools::CTException::CTGLException::CTGLWndErrReleaseHRC::CTGLWndErrReleaseHRC(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrReleaseHDC

CppTools::CTException::CTGLException::CTGLWndErrReleaseHDC::CTGLWndErrReleaseHDC(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrDestroy

CppTools::CTException::CTGLException::CTGLWndErrDestroy::CTGLWndErrDestroy(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}

//CTGLWndErrUnreg

CppTools::CTException::CTGLException::CTGLWndErrUnreg::CTGLWndErrUnreg(const std::string& context, const std::string& title, const unsigned int wnd_type)
					: CTGLWindowsExceptionBase(context, title, wnd_type)
{
}