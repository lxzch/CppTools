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
			//��ʾ����
			virtual int show(MSG& msg) = 0;

		protected:
			//�����¼���Ӧ���� �����������и���
			static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			//���ڳ�ʼ������
			virtual void initWindow() = 0;
			//��Ϣѭ������ ��д�˺�������Ӧ��Ҫ
			virtual int messageFunc(MSG& msg) = 0;

			//openGLʵ�� �����ػ洰�� �����������и���
			static GLvoid reshape(GLsizei width, GLsizei height);
			//OpenGLʵ�� ���뱻��д
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
			//����ɾ������
			GLvoid killGLWindow();

			static GLvoid reshape(GLsizei width, GLsizei height);
			virtual void init();
			virtual void display();

			//������ɫ������
			HGLRC hRC;

			//˽��GDI�豸������
			HDC hDC;

			//���ھ��
			HWND hWnd;

			//�����ʵ��
			HINSTANCE hInstance;

			//������ṹ
			WNDCLASS wc;

			//���ڼ������̵�����
			static bool* keys;

			//���ڵĻ��־��ȱʡΪTRUE
			static bool active;

			//ȫ����־ȱʡ�趨��ȫ��ģʽ
			static bool fullScreen;

			//�Ƿ��˳���Ϣѭ��
			static bool done;

			//ע������ ���ڱ���
			std::string wndClass, wndTitle;

			//����λ��
			cgPos wndPos;

			//���ڳߴ�
			cgSize wndSize;

			//��ɫλ��
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