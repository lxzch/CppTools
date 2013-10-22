#pragma once
#ifndef CTGLWND_H
#define CTGLWND_H

#include <CTGLEW>
#include <exception\CTGLException.h>
#include <exception\CTFileException.h>
#include <CTMemory>

namespace CppTools
{
	namespace CTGL
	{
		class CPPTOOLS_API CTWndBase
		{
		public:
			//显示窗口
			virtual int show(MSG& msg) = 0;

		protected:
			//窗口事件响应函数 可以在子类中覆盖
			static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			//窗口初始化函数
			virtual void initWindow() = 0;
			//消息循环函数 重写此函数以适应需要
			virtual int messageFunc(MSG& msg) = 0;

			//openGL实现 用于重绘窗口 可以在子类中覆盖
			static GLvoid reshape(GLsizei width, GLsizei height);
			//OpenGL实现 必须被重写
			virtual void init() = 0;
			virtual void display() = 0;
		};

		class CPPTOOLS_API CTGLWnd
			: public CTWndBase
		{
		public:
			CTGLWnd(const std::string& wndClass = "OpenGL", const std::string& wndTitle = NO_DEFAULT, const GLint& position_x = 0, const GLint& position_y = 0, const GLint& width = 640, const GLint& height = 480, const GLint& bits = 16);
			~CTGLWnd();

			virtual int show(MSG& msg);

			bool isFullScreen() const;
			void setFullScreen(bool flag);
			std::string getTitle() const;
			void setTitle(std::string& new_title);

			static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			
		protected:
			
			virtual void initWindow();
			virtual void createGLWindow();
			virtual int messageFunc(MSG& msg);
			//用于删除窗口
			GLvoid killGLWindow();

			static GLvoid reshape(GLsizei width, GLsizei height);
			virtual void init();
			virtual void display();

			//永久着色描述表
			HGLRC hRC;

			//私有GDI设备描述表
			HDC hDC;

			//窗口句柄
			HWND hWnd;

			//程序的实例
			HINSTANCE hInstance;

			//窗口类结构
			WNDCLASS wc;

			//用于键盘例程的数组
			static bool* keys;

			//窗口的活动标志，缺省为TRUE
			static bool active;

			//全屏标志缺省设定成全屏模式
			static bool fullScreen;

			//是否退出消息循环
			static bool done;

			//注册类名 窗口标题
			std::string wndClass, wndTitle;

			//窗口位置
			cgPos wndPos;

			//窗口尺寸
			cgSize wndSize;

			//颜色位数
			GLint bits;		
		};

		class CPPTOOLS_API CTGLEWWnd
			: public CTGLWnd
		{
		public:
			CTGLEWWnd(const std::string& wndClass = "OpenGL", const std::string& wndTitle = NO_DEFAULT, const GLint& position_x = 0, const GLint& position_y = 0, const GLint& width = 640, const GLint& height = 480, const GLint& bits = 16);
			~CTGLEWWnd();
		protected:
			virtual void createGLWindow();
		};
	}
}

#endif