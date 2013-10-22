#pragma once
#ifndef CTGLEXCEPTION_H
#define CTGLEXCEPTION_H

#include <CTData>
#include <CTGLEW>

namespace CppTools
{
	namespace CTException
	{
		namespace CTGLException
		{
			class CPPTOOLS_API CTGLExceptionBase
				: public CTExceptionBase
			{
			};

			class CPPTOOLS_API CTGLInitFail
				: public CTGLExceptionBase
			{
			public:
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();
			};

			class CPPTOOLS_API CTGLTextureExceptionBase
				: public CTGLExceptionBase
			{
			public:
				CTGLTextureExceptionBase(const int& texture_id = 0);
				void setId(const int& texture_id = 0);
				int getId() const;
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				CTInt id;
			};

			class CPPTOOLS_API CTGLTextureNULL
				: public CTGLTextureExceptionBase
			{
			public:
				CTGLTextureNULL(const int& texture_id = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();
			};

			class CPPTOOLS_API CTGLTextureNoBind
				: public CTGLTextureExceptionBase
			{
			public:
				CTGLTextureNoBind(const int& texture_id = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();
			};

			class CPPTOOLS_API CTGLTextureFail
				: public CTGLTextureExceptionBase
			{
			public:
				CTGLTextureFail(const int& texture_id = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();
			};

			class CPPTOOLS_API CTGLMipmapFail
				: public CTGLTextureExceptionBase
			{
			public:
				CTGLMipmapFail(const int& mipmap_id = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();
			};

			class CPPTOOLS_API CTGLEWInitFail
				: public CTGLExceptionBase
			{
			public:
				CTGLEWInitFail(const GLubyte* gl_version = NULL);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				const GLubyte* gl_version;
			};

			class CPPTOOLS_API CTGLSLComplieException
				:public CTGLExceptionBase
			{
			public:
				CTGLSLComplieException(const GLuint& error_device = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				GLuint error_device;
				GLint length;
				GLchar* log;
			};

			class CPPTOOLS_API CTGLSLLinkException
				:public CTGLExceptionBase
			{
			public:
				CTGLSLLinkException(const GLuint& error_device = 0);
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				GLuint error_device;
				GLint length;
				GLchar* log;
			};

			class CPPTOOLS_API CTGLWindowsExceptionBase
				: public CTGLExceptionBase
			{
			public:
				CTGLWindowsExceptionBase(const std::string& context = NO_DEFAULT, const std::string& title = NO_DEFAULT, const unsigned int wnd_type = MB_OK|MB_ICONSTOP);
				void setContext(const std::string& new_context);
				std::string getContext() const;
				void setWndTitle(const std::string& new_title);
				std::string getWndTitle() const;
				void setWndType(unsigned int new_type);
				unsigned int getWndType() const;
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				std::string context, title;
				unsigned int wnd_type;
			};

			class CPPTOOLS_API CTGLWndNotRegister
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndNotRegister(const std::string& context = "无法注册Windows窗口类", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndClose
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndClose(const std::string& context = "程序即将关闭", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONSTOP);
			};

			class CPPTOOLS_API CTGLWndNotCreate
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndNotCreate(const std::string& context = "窗口创建失败", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrHDC
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrHDC(const std::string& context = "无法创建openGL设备上下文", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrPFD
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrPFD(const std::string& context = "无法找到合适的像素格式", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrSetPFD
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrSetPFD(const std::string& context = "无法设置像素格式", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrHRC
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrHRC(const std::string& context = "无法创建openGL着色描述表", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrCurrentHRC
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrCurrentHRC(const std::string& context = "无法激活openGL着色描述表", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrInit
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrInit(const std::string& context = "初始化失败", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrRelease
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrRelease(const std::string& context = "无法释放设备上下文(DC)和着色描述表(RC)", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrReleaseHRC
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrReleaseHRC(const std::string& context = "无法释放着色描述表(RC)", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrReleaseHDC
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrReleaseHDC(const std::string& context = "无法释放设备上下文(DC)", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrDestroy
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrDestroy(const std::string& context = "无法销毁窗口类", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};

			class CPPTOOLS_API CTGLWndErrUnreg
				: public CTGLWindowsExceptionBase
			{
			public:
				CTGLWndErrUnreg(const std::string& context = "无法注销窗口类", const std::string& title = "错误", const unsigned int wnd_type = MB_OK|MB_ICONEXCLAMATION);
			};
		}
	}
}

#ifndef NO_SIMPLE

typedef CppTools::CTException::CTGLException::CTGLExceptionBase			CTGLExceptionBase;
typedef CppTools::CTException::CTGLException::CTGLInitFail				CTGLInitFail;

typedef CppTools::CTException::CTGLException::CTGLTextureExceptionBase	CTGLTextureExceptionBase;
typedef CppTools::CTException::CTGLException::CTGLTextureNULL			CTGLTextureNULL;
typedef CppTools::CTException::CTGLException::CTGLTextureFail			CTGLTextureFail;
typedef CppTools::CTException::CTGLException::CTGLTextureNoBind			CTGLTextureNoBind;
typedef CppTools::CTException::CTGLException::CTGLMipmapFail			CTGLMipmapFail;
typedef CppTools::CTException::CTGLException::CTGLEWInitFail			CTGLEWInitFail;

typedef CppTools::CTException::CTGLException::CTGLSLComplieException	CTGLSLComplieException;
typedef CppTools::CTException::CTGLException::CTGLSLLinkException		CTGLSLLinkException;

typedef CppTools::CTException::CTGLException::CTGLWindowsExceptionBase	CTGLWindowsExceptionBase;

typedef CppTools::CTException::CTGLException::CTGLWndClose				CTGLWndClose;
typedef CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC		CTGLWndErrCurrentHRC;
typedef CppTools::CTException::CTGLException::CTGLWndErrDestroy			CTGLWndErrDestroy;
typedef CppTools::CTException::CTGLException::CTGLWndErrHDC				CTGLWndErrHDC;
typedef CppTools::CTException::CTGLException::CTGLWndErrHRC				CTGLWndErrHRC;
typedef CppTools::CTException::CTGLException::CTGLWndErrInit			CTGLWndErrInit;
typedef CppTools::CTException::CTGLException::CTGLWndErrPFD				CTGLWndErrPFD;
typedef CppTools::CTException::CTGLException::CTGLWndErrRelease			CTGLWndErrRelease;
typedef CppTools::CTException::CTGLException::CTGLWndErrReleaseHDC		CTGLWndErrReleaseHDC;
typedef CppTools::CTException::CTGLException::CTGLWndErrReleaseHRC		CTGLWndErrReleaseHRC;
typedef CppTools::CTException::CTGLException::CTGLWndErrSetPFD			CTGLWndErrSetPFD;
typedef CppTools::CTException::CTGLException::CTGLWndErrUnreg			CTGLWndErrUnreg;
typedef CppTools::CTException::CTGLException::CTGLWndNotCreate			CTGLWndNotCreate;
typedef CppTools::CTException::CTGLException::CTGLWndNotRegister		CTGLWndNotRegister;

#endif

#endif