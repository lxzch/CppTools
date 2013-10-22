#include "stdafx.h"
#include <gl\CTGLWnd.h>

CppTools::CTGL::CTGLEWWnd::CTGLEWWnd(const std::string &wndClass, const std::string &wndTitle, const GLint &position_x, const GLint &position_y, const GLint &width, const GLint &height, const GLint &bits)
: CTGLWnd(wndClass, wndTitle, position_x, position_y, width, height, bits)
{
	initWindow();
}

CppTools::CTGL::CTGLEWWnd::~CTGLEWWnd()
{
}

void CppTools::CTGL::CTGLEWWnd::createGLWindow()
{
	GlewInit();

	GLuint PixelFormat;                                 // �������ƥ��Ľ��	
	DWORD dwExStyle;                                    // ��չ���ڷ��
	DWORD dwStyle;                                      // ���ڷ��

	RECT WindowRect;                                    // ȡ�þ��ε����ϽǺ����½ǵ�����ֵ
	WindowRect.left = (long)wndPos.x;                          // ��Left ��Ϊ 0
	WindowRect.right = (long)wndSize.width;                     // ��Right ��ΪҪ��Ŀ��
	WindowRect.top = (long)wndPos.y;                           // ��Top ��Ϊ 0
	WindowRect.bottom = (long)wndSize.height;                   // ��Bottom ��ΪҪ��ĸ߶�
	hInstance = GetModuleHandle(NULL);                  // ȡ�����Ǵ��ڵ�ʵ��
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;      // �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
	wc.lpfnWndProc = (WNDPROC) WndProc;                 // WndProc������Ϣ
	wc.cbClsExtra = 0;                                  // �޶��ⴰ������
	wc.cbWndExtra = 0;                                  // �޶��ⴰ������
	wc.hInstance = hInstance;                           // ����ʵ��
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);             // װ��ȱʡͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);           // װ�����ָ��
	wc.hbrBackground = NULL;                            // GL����Ҫ����
	wc.lpszMenuName = NULL;                             // ����Ҫ�˵�
	wc.lpszClassName = wndClass.c_str();                        // �趨������
	if (!RegisterClass(&wc))                            // ����ע�ᴰ����
		throw CppTools::CTException::CTGLException::CTGLWndNotRegister();

	const int PixAttribs[] =
	{
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
		WGL_COLOR_BITS_ARB, 32,
		WGL_ALPHA_BITS_ARB, 8,
		WGL_DEPTH_BITS_ARB, 16,
		WGL_STENCIL_BITS_ARB,
		WGL_PIXEL_TYPE_ARB,
		WGL_TYPE_RGBA_ARB,
		WGL_ACCELERATION_ARB,
		WGL_FULL_ACCELERATION_ARB,
		NULL
	};

	UINT PixelCount;

	GLint attribs[] = 
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_FLAGS_ARB,
		WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0
	};

	if (fullScreen)                                     // Ҫ����ȫ��ģʽ��?
	{
		DEVMODE dmScreenSettings;                       // �豸ģʽ
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
		                                                // ȷ���ڴ����
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);
		                                                // Devmode �ṹ�Ĵ�С
		dmScreenSettings.dmPelsWidth = wndSize.width;           // ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = wndSize.height;         // ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = bits;           // ÿ������ѡ��ɫ�����
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		                                                // ����������ʾģʽ�����ؽ����ע: CDS_FULLSCREEN ��ȥ��״̬����
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
		                                                // ��ģʽʧ�ܣ��ṩ����ѡ��˳����ڴ��������С�
			if (MessageBox(NULL, "�����Կ���֧��ȫ��ģʽ\n�Ƿ�ʹ�ô���ģʽ��", "CTGL", MB_YESNO|MB_ICONEXCLAMATION) == IDYES)
				fullScreen=false;                       // ѡ�񴰿�ģʽ(Fullscreen=FALSE)
			else
				throw CppTools::CTException::CTGLException::CTGLWndClose();
		}
	}
	if (fullScreen)                                    // �Դ���ȫ��ģʽ��?
	{
		dwExStyle = WS_EX_APPWINDOW;                   // ��չ������
		dwStyle = WS_POPUP;                            // ������
		ShowCursor(false);                             // �������ָ��
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;// ��չ������
		dwStyle = WS_OVERLAPPEDWINDOW;                 // ������
	}
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);
	                                                   // �������ڴﵽ����Ҫ��Ĵ�С
	if (!(hWnd = CreateWindowEx( dwExStyle,            // ��չ������
								wndClass.c_str(),      // ������
								wndTitle.c_str(),                 // ���ڱ���
								WS_CLIPSIBLINGS|       // ����Ĵ���������
								WS_CLIPCHILDREN|       // ����Ĵ���������
								dwStyle,               // ѡ��Ĵ�������
								0,0,                   // ����λ��
								WindowRect.right-WindowRect.left,
								                       // ��������õĴ��ڿ��
								WindowRect.bottom-WindowRect.top,
								                       // ��������õĴ��ڸ߶�
								NULL,                  // �޸�����
								NULL,                  // �޲˵�
								hInstance,             // ʵ��
								NULL)))                // ����WM_CREATE�����κζ���
	{
		throw CppTools::CTException::CTGLException::CTGLWndNotCreate();
	}

	static CTPfd pfd=                  //pfd ���ߴ���������ϣ���Ķ���
	{
		sizeof(CTPfd),                 //������ʽ�������Ĵ�С
		1,                                             //�汾��
		PFD_DRAW_TO_WINDOW|                            //��ʽ����֧�ִ���
		PFD_SUPPORT_OPENGL|                            //��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,                              //����֧��˫����
		PFD_TYPE_RGBA,                                 //����RGBA��ʽ
		bits,                                          //ѡ��ɫ�����
		0,0,0,0,0,0,                                   //���Ե�ɫ��λ
		0,                                             //��Alpha����
		0,                                             //����ShiftBit
		0,                                             //�޾ۼ�����
		0,0,0,0,                                       //���Ծۼ�λ
		bits,                                            //16λZ-����(��Ȼ���)
		0,                                             //��ģ�建��
		0,                                             //�޸�������
		PFD_MAIN_PLANE,                                //����ͼ��
		0,                                             //����
		0,0,0                                          //���Բ�����
	};

	if(!(hDC = GetDC(hWnd)))                           //ȡ���豸��������ô?
		throw CppTools::CTException::CTGLException::CTGLWndErrHDC();

	if(!(ChoosePixelFormat(hDC, PixAttribs, NULL, 1, (int*)&PixelFormat, &PixelCount)))   //Windows�ҵ���Ӧ�����ظ�ʽ����?
		throw CppTools::CTException::CTGLException::CTGLWndErrPFD();

	if(!SetPixelFormat(hDC, PixelFormat, &pfd))         //�ܹ��������ظ�ʽô?
		throw CppTools::CTException::CTGLException::CTGLWndErrSetPFD();

	if(!(hRC = wglCreateContextAttribsARB(hDC, 0, attribs)))                //�ܷ�ȡ����ɫ������?
		throw CppTools::CTException::CTGLException::CTGLWndErrHRC();

	if(!wglMakeCurrent(hDC,hRC))                      //���Լ�����ɫ������
		throw CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC();


	//����glew����DC,RC

	//wglMakeCurrent(NULL, NULL);
	//wglDeleteContext(hRC);
	//ReleaseDC(hWnd, hDC);
	//DestroyWindow(hWnd);

	//if (!(hWnd = CreateWindowEx( dwExStyle,            // ��չ������
	//							wndClass.c_str(),      // ������
	//							wndTitle.c_str(),                 // ���ڱ���
	//							WS_CLIPSIBLINGS|       // ����Ĵ���������
	//							WS_CLIPCHILDREN|       // ����Ĵ���������
	//							dwStyle,               // ѡ��Ĵ�������
	//							0,0,                   // ����λ��
	//							WindowRect.right-WindowRect.left,
	//							                       // ��������õĴ��ڿ��
	//							WindowRect.bottom-WindowRect.top,
	//							                       // ��������õĴ��ڸ߶�
	//							NULL,                  // �޸�����
	//							NULL,                  // �޲˵�
	//							hInstance,             // ʵ��
	//							NULL)))                // ����WM_CREATE�����κζ���
	//{
	//	throw GLWndNotCreate();
	//}

	//if(!(hDC = GetDC(hWnd)))                           //ȡ���豸��������ô?
	//	throw GLWndErrHDC();

	//ctglChoosePixelFormat(hDC, PixAttribs, NULL, 1, (int*)&PixelFormat, &PixelCount);
	//SetPixelFormat(hDC, PixelFormat, &pfd);

	ShowWindow(hWnd,SW_SHOW);                         //��ʾ����
	SetForegroundWindow(hWnd);                        //����������ȼ�
	SetFocus(hWnd);                                   //���ü��̵Ľ������˴���
	reshape(wndSize.width, wndSize.height);                      //����͸��GL��Ļ

	init();                                     //��ʼ���½���GL����
}