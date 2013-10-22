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
	GLuint PixelFormat;                                 // 保存查找匹配的结果	
	DWORD dwExStyle;                                    // 扩展窗口风格
	DWORD dwStyle;                                      // 窗口风格

	RECT WindowRect;                                    // 取得矩形的左上角和右下角的坐标值
	WindowRect.left = (long)wndPos.x;                          // 将Left 设为 0
	WindowRect.right = (long)wndSize.width;                     // 将Right 设为要求的宽度
	WindowRect.top = (long)wndPos.y;                           // 将Top 设为 0
	WindowRect.bottom = (long)wndSize.height;                   // 将Bottom 设为要求的高度
	hInstance = GetModuleHandle(NULL);                  // 取得我们窗口的实例
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;      // 移动时重画，并为窗口取得DC
	wc.lpfnWndProc = (WNDPROC) WndProc;                 // WndProc处理消息
	wc.cbClsExtra = 0;                                  // 无额外窗口数据
	wc.cbWndExtra = 0;                                  // 无额外窗口数据
	wc.hInstance = hInstance;                           // 设置实例
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);             // 装入缺省图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);           // 装入鼠标指针
	wc.hbrBackground = NULL;                            // GL不需要背景
	wc.lpszMenuName = NULL;                             // 不需要菜单
	wc.lpszClassName = wndClass.c_str();                        // 设定类名字
	if (!RegisterClass(&wc))                            // 尝试注册窗口类
		throw CppTools::CTException::CTGLException::CTGLWndNotRegister();

	if (fullScreen)                                     // 要尝试全屏模式吗?
	{
		DEVMODE dmScreenSettings;                       // 设备模式
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
		                                                // 确保内存分配
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);
		                                                // Devmode 结构的大小
		dmScreenSettings.dmPelsWidth = wndSize.width;           // 所选屏幕宽度
		dmScreenSettings.dmPelsHeight = wndSize.height;         // 所选屏幕高度
		dmScreenSettings.dmBitsPerPel = bits;           // 每象素所选的色彩深度
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		                                                // 尝试设置显示模式并返回结果。注: CDS_FULLSCREEN 移去了状态条。
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
		                                                // 若模式失败，提供两个选项：退出或在窗口内运行。
			if (MessageBox(NULL, "您的显卡不支持全屏模式\n是否使用窗口模式？", "CTGL", MB_YESNO|MB_ICONEXCLAMATION) == IDYES)
				fullScreen=false;                       // 选择窗口模式(Fullscreen=FALSE)
			else
				throw CppTools::CTException::CTGLException::CTGLWndClose();
		}
	}
	if (fullScreen)                                    // 仍处于全屏模式吗?
	{
		dwExStyle = WS_EX_APPWINDOW;                   // 扩展窗体风格
		dwStyle = WS_POPUP;                            // 窗体风格
		ShowCursor(false);                             // 隐藏鼠标指针
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;// 扩展窗体风格
		dwStyle = WS_OVERLAPPEDWINDOW;                 // 窗体风格
	}
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);
	                                                   // 调整窗口达到真正要求的大小
	if (!(hWnd = CreateWindowEx( dwExStyle,            // 扩展窗体风格
								wndClass.c_str(),      // 类名字
								wndTitle.c_str(),                 // 窗口标题
								WS_CLIPSIBLINGS|       // 必须的窗体风格属性
								WS_CLIPCHILDREN|       // 必须的窗体风格属性
								dwStyle,               // 选择的窗体属性
								0,0,                   // 窗口位置
								WindowRect.right-WindowRect.left,
								                       // 计算调整好的窗口宽度
								WindowRect.bottom-WindowRect.top,
								                       // 计算调整好的窗口高度
								NULL,                  // 无父窗口
								NULL,                  // 无菜单
								hInstance,             // 实例
								NULL)))                // 不向WM_CREATE传递任何东东
		throw CppTools::CTException::CTGLException::CTGLWndNotCreate();

	static PIXELFORMATDESCRIPTOR pfd=                  //pfd 告诉窗口我们所希望的东东
	{
		sizeof(PIXELFORMATDESCRIPTOR),                 //上述格式描述符的大小
		1,                                             //版本号
		PFD_DRAW_TO_WINDOW|                            //格式必须支持窗口
		PFD_SUPPORT_OPENGL|                            //格式必须支持OpenGL
		PFD_DOUBLEBUFFER,                              //必须支持双缓冲
		PFD_TYPE_RGBA,                                 //申请RGBA格式
		bits,                                          //选定色彩深度
		0,0,0,0,0,0,                                   //忽略的色彩位
		0,                                             //无Alpha缓存
		0,                                             //忽略ShiftBit
		0,                                             //无聚集缓存
		0,0,0,0,                                       //忽略聚集位
		bits,                                            //16位Z-缓存(深度缓存)
		0,                                             //无模板缓存
		0,                                             //无辅助缓存
		PFD_MAIN_PLANE,                                //主绘图层
		0,                                             //保留
		0,0,0                                          //忽略层遮罩
	};

	if(!(hDC = GetDC(hWnd)))                           //取得设备描述表了么?
		throw CppTools::CTException::CTGLException::CTGLWndErrHDC();

	if(!(PixelFormat = ChoosePixelFormat(hDC,&pfd)))   //Windows找到相应的象素格式了吗?
		throw CppTools::CTException::CTGLException::CTGLWndErrPFD();

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))         //能够设置象素格式么?
		throw CppTools::CTException::CTGLException::CTGLWndErrSetPFD();

	if(!(hRC = wglCreateContext(hDC)))                //能否取得着色描述表?
		throw CppTools::CTException::CTGLException::CTGLWndErrHRC();

	if(!wglMakeCurrent(hDC,hRC))                      //尝试激活着色描述表
		throw CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC();

	wglMakeCurrent(hDC, hRC);
	ShowWindow(hWnd,SW_SHOW);                         //显示窗口
	SetForegroundWindow(hWnd);                        //略略提高优先级
	SetFocus(hWnd);                                   //设置键盘的焦点至此窗口
	reshape(wndSize.width, wndSize.height);                      //设置透视GL屏幕

	init();                                     //初始化新建的GL窗口
}

GLvoid CppTools::CTGL::CTGLWnd::killGLWindow()
{
	if (fullScreen)                                     // 我们处于全屏模式吗?
	{
		ChangeDisplaySettings(NULL, 0);                  // 是的话，切换回桌面
		ShowCursor(true);                               // 显示鼠标指针
	}
	if (hRC)                                            // 我们拥有着色描述表吗?
	{
		if (!wglMakeCurrent(NULL, NULL))                 // 我们能否释放DC和RC描述表?
		{
			throw CppTools::CTException::CTGLException::CTGLWndErrRelease();
		}
		if (!wglDeleteContext(hRC))                     // 我们能否删除RC?
		{
			throw CppTools::CTException::CTGLException::CTGLWndErrReleaseHRC();
		}
		hRC = NULL;                                     // 将RC设为 NULL
	}
	if (hDC && !ReleaseDC(hWnd, hDC))                    // 我们能否释放 DC?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrReleaseHDC();
		hDC = NULL;                                     // 将 DC 设为 NULL
	}
	if (hWnd && !DestroyWindow(hWnd))                   // 能否销毁窗口?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrDestroy();
		hWnd = NULL;                                    // 将 hWnd 设为 NULL
	}
	if (!UnregisterClass(wndClass.c_str(), hInstance))           // 能否注销类?
	{
		throw CppTools::CTException::CTGLException::CTGLWndErrUnreg();
		hInstance = NULL;                               // 将 hInstance 设为 NULL
	}
}

int CppTools::CTGL::CTGLWnd::messageFunc(MSG& msg)
{
	while(!done)                                      //保持循环直到done=TRUE
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))      //有消息在等待吗?
		{
			if(msg.message == WM_QUIT)                //收到退出消息?
			{
				done = true;                          //是，则done=TRUE
			}
			else                                      //不是，处理窗口消息
			{
				TranslateMessage(&msg);               //翻译消息
				DispatchMessage(&msg);                //发送消息
			}
		}
		else                                          //如果没有消息
		{
		                                              //绘制场景。监视ESC键和来自DrawGLScene()的退出消息
			if(active)                                //程序激活的么?
			{
				if(keys[VK_ESCAPE])                   //ESC按下了么?
				{
					done = true;                      //ESC发出退出信号
				}
				else                                  //不是退出的时候，刷新屏幕
				{
					display();                    //绘制场景
					SwapBuffers(hDC);                 //交换缓存(双缓存)
				}
			}
			if(keys[VK_F1])                           //F1键按下了么?
			{
				keys[VK_F1] = false;                  //若是，使对应的Key数组中的值为FALSE
				killGLWindow();                       //销毁当前的窗口
				fullScreen = !fullScreen;             //切换全屏/窗口模式
				                                      //重建OpenGL窗口
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

LRESULT CALLBACK CppTools::CTGL::CTGLWnd::WndProc(HWND hWnd,                   //窗口的句柄
										       	  UINT uMsg,                    //窗口的消息
											      WPARAM wParam,                //附加的消息内容
											      LPARAM lParam)                //附加的消息内容
{
	switch(uMsg)                                      //检查Windows消息
	{
		case WM_ACTIVATE:                                 //监视窗口激活消息
		{
			if(!HIWORD(wParam))                           //检查最小化状态
			{
				active = true;                            //程序处于激活状态
			}
			else
			{
				active = false;                           //程序不再激活
			}
			return 0;                                     //返回消息循环
		}
		case WM_SYSCOMMAND:                               //中断系统命令InterceptSystemCommands
		{
			switch(wParam)                                //检查系统调用CheckSystemCalls
			{
			case SC_SCREENSAVE:                           //屏保要运行?
			case SC_MONITORPOWER:                         //显示器要进入节电模式?
				return 0;                                 //阻止发生
			}
			break;
		}
		case WM_CLOSE:                                    //收到Close消息?
		{
			PostQuitMessage(0);                           //发出退出消息
			return 0;
		}
		case WM_KEYDOWN:                                  //有键按下么?
		{
			keys[wParam] = true;                          //如果是，设为TRUE
			return 0;
		}
		case WM_KEYUP:                                    //有键放开么?
		{
			keys[wParam] = false;                         //如果是，设为FALSE
			return 0;
		}
		case WM_SIZE:
		{
			reshape(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}
	}
	return DefWindowProc(hWnd, uMsg ,wParam, lParam);    //向DefWindowProc传递所有未处理的消息。
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