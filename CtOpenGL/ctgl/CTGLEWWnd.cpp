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
	{
		throw CppTools::CTException::CTGLException::CTGLWndNotCreate();
	}

	static CTPfd pfd=                  //pfd 告诉窗口我们所希望的东东
	{
		sizeof(CTPfd),                 //上述格式描述符的大小
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

	if(!(ChoosePixelFormat(hDC, PixAttribs, NULL, 1, (int*)&PixelFormat, &PixelCount)))   //Windows找到相应的象素格式了吗?
		throw CppTools::CTException::CTGLException::CTGLWndErrPFD();

	if(!SetPixelFormat(hDC, PixelFormat, &pfd))         //能够设置象素格式么?
		throw CppTools::CTException::CTGLException::CTGLWndErrSetPFD();

	if(!(hRC = wglCreateContextAttribsARB(hDC, 0, attribs)))                //能否取得着色描述表?
		throw CppTools::CTException::CTGLException::CTGLWndErrHRC();

	if(!wglMakeCurrent(hDC,hRC))                      //尝试激活着色描述表
		throw CppTools::CTException::CTGLException::CTGLWndErrCurrentHRC();


	//建立glew所需DC,RC

	//wglMakeCurrent(NULL, NULL);
	//wglDeleteContext(hRC);
	//ReleaseDC(hWnd, hDC);
	//DestroyWindow(hWnd);

	//if (!(hWnd = CreateWindowEx( dwExStyle,            // 扩展窗体风格
	//							wndClass.c_str(),      // 类名字
	//							wndTitle.c_str(),                 // 窗口标题
	//							WS_CLIPSIBLINGS|       // 必须的窗体风格属性
	//							WS_CLIPCHILDREN|       // 必须的窗体风格属性
	//							dwStyle,               // 选择的窗体属性
	//							0,0,                   // 窗口位置
	//							WindowRect.right-WindowRect.left,
	//							                       // 计算调整好的窗口宽度
	//							WindowRect.bottom-WindowRect.top,
	//							                       // 计算调整好的窗口高度
	//							NULL,                  // 无父窗口
	//							NULL,                  // 无菜单
	//							hInstance,             // 实例
	//							NULL)))                // 不向WM_CREATE传递任何东东
	//{
	//	throw GLWndNotCreate();
	//}

	//if(!(hDC = GetDC(hWnd)))                           //取得设备描述表了么?
	//	throw GLWndErrHDC();

	//ctglChoosePixelFormat(hDC, PixAttribs, NULL, 1, (int*)&PixelFormat, &PixelCount);
	//SetPixelFormat(hDC, PixelFormat, &pfd);

	ShowWindow(hWnd,SW_SHOW);                         //显示窗口
	SetForegroundWindow(hWnd);                        //略略提高优先级
	SetFocus(hWnd);                                   //设置键盘的焦点至此窗口
	reshape(wndSize.width, wndSize.height);                      //设置透视GL屏幕

	init();                                     //初始化新建的GL窗口
}