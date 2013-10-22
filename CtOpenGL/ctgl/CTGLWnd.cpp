#include "stdafx.h"
#include <gl\CTGLWnd.h>

bool* CppTools::CTGL::CTGLWnd::keys = NULL;
bool CppTools::CTGL::CTGLWnd::active = true;
bool CppTools::CTGL::CTGLWnd::fullScreen = true;
bool CppTools::CTGL::CTGLWnd::done = false;

CppTools::CTGL::CTGLWnd::CTGLWnd(const std::string& wndClass, const std::string& wndTitle, const GLint& position_x, const GLint& position_y, const GLint& width, const GLint& height, const GLint& bits)
: wndClass(wndClass), wndTitle(wndTitle), wndPos(position_x, position_y), wndSize(width, height), bits(bits)
{
	initWindow();
}

CppTools::CTGL::CTGLWnd::~CTGLWnd()
{
}

void CppTools::CTGL::CTGLWnd::initWindow()
{
	hRC = NULL;
	hDC = NULL;
	hWnd = NULL;
	
	keys = CppTools::CTMemory::NewArray1d<bool>(256);
	memset(keys, false, 256);
}

void CppTools::CTGL::CTGLWnd::createGLWindow()
{
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
		throw CppTools::CTException::CTGLException::CTGLWndNotCreate();

	static PIXELFORMATDESCRIPTOR pfd=                  //pfd ���ߴ���������ϣ���Ķ���
	{
		sizeof(PIXELFORMATDESCRIPTOR),                 //������ʽ�������Ĵ�С
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

	if(!(PixelFormat = ChoosePixelFormat(hDC,&pfd)))   //Windows�ҵ���Ӧ�����ظ�ʽ����?
		throw CppTools::CTException::CTGLException::CTGLWndErrPFD();

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))         //�ܹ��������ظ�ʽô?
		throw CppTools::CTException::CTGLException::CTGLWndErrSetPFD();

	if(!(hRC = wglCreateContext(hDC)))                //�ܷ�ȡ����ɫ������?
		throw CppTools::CTException::CTGLException::CTGLWndErrHRC();

	if(!wglMakeCurrent(hDC,hRC))                      //���Լ�����ɫ������
		throw CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC();

	wglMakeCurrent(hDC, hRC);
	ShowWindow(hWnd,SW_SHOW);                         //��ʾ����
	SetForegroundWindow(hWnd);                        //����������ȼ�
	SetFocus(hWnd);                                   //���ü��̵Ľ������˴���
	reshape(wndSize.width, wndSize.height);                      //����͸��GL��Ļ

	init();                                     //��ʼ���½���GL����
}

GLvoid CppTools::CTGL::CTGLWnd::killGLWindow()
{
	if (fullScreen)                                     // ���Ǵ���ȫ��ģʽ��?
	{
		ChangeDisplaySettings(NULL, 0);                  // �ǵĻ����л�������
		ShowCursor(true);                               // ��ʾ���ָ��
	}
	if (hRC)                                            // ����ӵ����ɫ��������?
	{
		if (!wglMakeCurrent(NULL, NULL))                 // �����ܷ��ͷ�DC��RC������?
		{
			throw CppTools::CTException::CTGLException::CTGLWndErrRelease();
		}
		if (!wglDeleteContext(hRC))                     // �����ܷ�ɾ��RC?
		{
			throw CppTools::CTException::CTGLException::CTGLWndErrReleaseHRC();
		}
		hRC = NULL;                                     // ��RC��Ϊ NULL
	}
	if (hDC && !ReleaseDC(hWnd, hDC))                    // �����ܷ��ͷ� DC?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrReleaseHDC();
		hDC = NULL;                                     // �� DC ��Ϊ NULL
	}
	if (hWnd && !DestroyWindow(hWnd))                   // �ܷ����ٴ���?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrDestroy();
		hWnd = NULL;                                    // �� hWnd ��Ϊ NULL
	}
	if (!UnregisterClass(wndClass.c_str(), hInstance))           // �ܷ�ע����?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrUnreg();
		hInstance = NULL;                               // �� hInstance ��Ϊ NULL
	}
}

int CppTools::CTGL::CTGLWnd::messageFunc(MSG& msg)
{
	while(!done)                                      //����ѭ��ֱ��done=TRUE
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))      //����Ϣ�ڵȴ���?
		{
			if(msg.message == WM_QUIT)                //�յ��˳���Ϣ?
			{
				done = true;                          //�ǣ���done=TRUE
			}
			else                                      //���ǣ���������Ϣ
			{
				TranslateMessage(&msg);               //������Ϣ
				DispatchMessage(&msg);                //������Ϣ
			}
		}
		else                                          //���û����Ϣ
		{
		                                              //���Ƴ���������ESC��������DrawGLScene()���˳���Ϣ
			if(active)                                //���򼤻��ô?
			{
				if(keys[VK_ESCAPE])                   //ESC������ô?
				{
					done = true;                      //ESC�����˳��ź�
				}
				else                                  //�����˳���ʱ��ˢ����Ļ
				{
					display();                    //���Ƴ���
					SwapBuffers(hDC);                 //��������(˫����)
				}
			}
			if(keys[VK_F1])                           //F1��������ô?
			{
				keys[VK_F1] = false;                  //���ǣ�ʹ��Ӧ��Key�����е�ֵΪFALSE
				killGLWindow();                       //���ٵ�ǰ�Ĵ���
				fullScreen = !fullScreen;             //�л�ȫ��/����ģʽ
				                                      //�ؽ�OpenGL����
				createGLWindow();
			}			
		}
	}
	return(msg.wParam);
}

bool CppTools::CTGL::CTGLWnd::isFullScreen() const
{
	return fullScreen;
}

void CppTools::CTGL::CTGLWnd::setFullScreen(bool flag)
{
	fullScreen = flag;
}

LRESULT CALLBACK CppTools::CTGL::CTGLWnd::WndProc(HWND hWnd,                   //���ڵľ��
										       	  UINT uMsg,                    //���ڵ���Ϣ
											      WPARAM wParam,                //���ӵ���Ϣ����
											      LPARAM lParam)                //���ӵ���Ϣ����
{
	switch(uMsg)                                      //���Windows��Ϣ
	{
		case WM_ACTIVATE:                                 //���Ӵ��ڼ�����Ϣ
		{
			if(!HIWORD(wParam))                           //�����С��״̬
			{
				active = true;                            //�����ڼ���״̬
			}
			else
			{
				active = false;                           //�����ټ���
			}
			return 0;                                     //������Ϣѭ��
		}
		case WM_SYSCOMMAND:                               //�ж�ϵͳ����InterceptSystemCommands
		{
			switch(wParam)                                //���ϵͳ����CheckSystemCalls
			{
			case SC_SCREENSAVE:                           //����Ҫ����?
			case SC_MONITORPOWER:                         //��ʾ��Ҫ����ڵ�ģʽ?
				return 0;                                 //��ֹ����
			}
			break;
		}
		case WM_CLOSE:                                    //�յ�Close��Ϣ?
		{
			PostQuitMessage(0);                           //�����˳���Ϣ
			return 0;
		}
		case WM_KEYDOWN:                                  //�м�����ô?
		{
			keys[wParam] = true;                          //����ǣ���ΪTRUE
			return 0;
		}
		case WM_KEYUP:                                    //�м��ſ�ô?
		{
			keys[wParam] = false;                         //����ǣ���ΪFALSE
			return 0;
		}
		case WM_SIZE:
		{
			reshape(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}
	}
	return DefWindowProc(hWnd, uMsg ,wParam, lParam);    //��DefWindowProc��������δ�������Ϣ��
}

std::string CppTools::CTGL::CTGLWnd::getTitle() const
{
	return wndTitle;
}

void CppTools::CTGL::CTGLWnd::setTitle(std::string &new_title)
{
	wndTitle = new_title;
}

int CppTools::CTGL::CTGLWnd::show(MSG& msg)
{
	createGLWindow();
	return messageFunc(msg);
}