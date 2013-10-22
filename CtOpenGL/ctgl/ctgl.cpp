#include "stdafx.h"
#include <gl\CTGLkits.h>
#include <gl\CTGLWnd.h>

BOOL CppTools::CTGL::ChoosePixelFormat(HDC hdc,
									   const int* piAttribIList,
									   const FLOAT *pfAttribFList,
									   UINT nMaxFormats,
									   int *piFormats,
									   UINT *nNumFormats)
{
	return wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}

bool CppTools::CTGL::IsTexture(CTTexture& texture)
{
	if(!glIsTexture(texture))
		return false;
	return true;
}


CppTools::CTGL::CGRect2d CppTools::CTGL::SetRect(const GLdouble left_x, const GLdouble left_y,
												 const GLdouble right_x, const GLdouble right_y)
{
	CGRect2d rect;
	rect.left.x = left_x;
	rect.left.y = left_y;
	rect.right.x = right_x;
	rect.right.y = right_y;
	return rect;
}

CppTools::CTGL::CGRect2f CppTools::CTGL::SetRect(const GLfloat left_x, const GLfloat left_y,
												 const GLfloat right_x, const GLfloat right_y)
{
	CGRect2f rect;
	rect.left.x = left_x;
	rect.left.y = left_y;
	rect.right.x = right_x;
	rect.right.y = right_y;
	return rect;
}

CppTools::CTGL::CGPoint2d CppTools::CTGL::SetPoint(const GLdouble x, const GLdouble y)
{
	CGPoint2d point;
	point.x = x;
	point.y = y;
	return point;
}

CppTools::CTGL::CGPoint2f CppTools::CTGL::SetPoint(const GLfloat x, const GLfloat y)
{
	CGPoint2f point;
	point.x = x;
	point.y = y;
	return point;
}

CppTools::CTGL::CGSize2d CppTools::CTGL::SetSize(const GLdouble width, const GLdouble height)
{
	CGSize2d size;
	size.width = width;
	size.height = height;
	return size;
}

CppTools::CTGL::CGSize2f CppTools::CTGL::SetSize(const GLfloat width, const GLfloat height)
{
	CGSize2f size;
	size.width = width;
	size.height = height;
	return size;
}

CTImage* CppTools::CTGL::ReadImage(const std::string& filename)
{
	if(filename.empty())
	{
		throw CppTools::CTException::CTFileException::CTFileNoName();
	}
	CTImage* img = cvLoadImage(filename.c_str());
	if(!img)
	{
		throw CppTools::CTException::CTFileException::CTFileNotFound(filename);
	}
	return img;
}

CTImage* CppTools::CTGL::ReadImage(const std::string filename,
								   const std::string maskfile)
{
	CTImage* source;
	CTImage* mask;
	CTImage* result = new CTImage();
	source = ReadImage(filename);
	mask = ReadImage(maskfile);
	int size = mask->height * mask->width;
	int s_channel = source->nChannels;

	*result = *source;
	result->nChannels = 4;
	result->imageSize = size * 4;

	if(mask->nChannels == 1)
	{
		
		char* p_result = NULL;
		p_result = (char*)malloc(size * 4 * sizeof(char));
		if(!p_result)
			throw CppTools::CTException::CTMemoryException::CTNotEnoughMemory();
		result->imageData = p_result;
		char* p_source = source->imageData;
		char* p_mask = mask->imageData;		
		int i = 0, i_4;		
		while(i < size)
		{
			i_4 = i * 4;
			p_result[i_4] = p_source[i * s_channel];
			p_result[i_4 + 1] = p_source[i * s_channel + 1];
			p_result[i_4 + 2] = p_source[i * s_channel + 2];
			p_result[i_4 + 3] = p_mask[i];
			++i;
		}
	}
	else if(mask->nChannels == 3)
	{
		char* p_result = NULL;
		p_result = (char*)malloc(size * 4 * sizeof(char));
		if(!p_result)
			throw CppTools::CTException::CTMemoryException::CTNotEnoughMemory();
		result->imageData = p_result;
		char* p_source = source->imageData;
		char* p_mask = mask->imageData;		
		int i = 0, i_4, i_3;		
		while(i < size)
		{
			i_4 = i * 4;
			i_3 = i * 3;
			p_result[i_4] = p_source[i * s_channel];
			p_result[i_4 + 1] = p_source[i * s_channel + 1];
			p_result[i_4 + 2] = p_source[i * s_channel + 2];
			p_result[i_4 + 3] = (p_mask[i_3] + p_mask[i_3 + 1] + p_mask[i_3 + 2]) / 3;
			++i;
		}
	}
	else if(mask->nChannels == 4)
	{
		char* p_result = NULL;
		p_result = (char*)malloc(size * 4 * sizeof(char));
		if(!p_result)
			throw CppTools::CTException::CTMemoryException::CTNotEnoughMemory();
		result->imageData = p_result;
		char* p_source = source->imageData;
		char* p_mask = mask->imageData;	
		int i = 0, i_4;		
		while(i < size)
		{
			i_4 = i * 4;
			p_result[i_4] = p_source[i * s_channel];
			p_result[i_4 + 1] = p_source[i * s_channel + 1];
			p_result[i_4 + 2] = p_source[i * s_channel + 2];
			p_result[i_4 + 3] = p_mask[i_4 + 3];
			++i;
		}
	}	
	else
		return NULL;
	return result;
}

CTTexture CppTools::CTGL::RegTexture2d(const GLsizei& size_x, const GLsizei& size_y, const CTImageDatau* data,
									   const CTImageMode& RGBmode,
									   const GLint& arrange, const GLint& quality)
{
	GLuint texture;
	glPixelStorei(unpack, 1);
	glGenTextures(1, &texture);
	glBindTexture(texture_2d, texture);
	glTexImage2D(texture_2d, 0, GL_RGBA, size_x, size_y, 0, RGBmode, GL_UNSIGNED_BYTE, data);

	glTexParameteri(texture_2d, wrap_s, arrange);
	glTexParameteri(texture_2d, wrap_t, arrange);
	glTexParameteri(texture_2d, mag_filter, quality);
	glTexParameteri(texture_2d, min_filter, quality);
	return texture;
}

CTTexture CppTools::CTGL::RegTexture2d(const CTImage* data,
									   const CTImageMode& RGBmode,
									   const GLint& arrange, const GLint& quality)
{
	GLuint texture;
	glEnable(GL_TEXTURE_2D);
	glPixelStorei(unpack, 1);
	glGenTextures(1, &texture);
	glBindTexture(texture_2d, texture);
	glTexImage2D(texture_2d, 0, GL_RGBA, data->width, data->height, 0, RGBmode, GL_UNSIGNED_BYTE, data->imageData);

	glTexParameteri(texture_2d, wrap_s, arrange);
	glTexParameteri(texture_2d, wrap_t, arrange);
	glTexParameteri(texture_2d, mag_filter, quality);
	glTexParameteri(texture_2d, min_filter, quality);
	return texture;
}

CTTexture CppTools::CTGL::ReadTexture2d(const std::string& filename,
										const CTImageMode RGBmode,
										const GLint arrange, const GLint quality)
{
	if (RGBmode == auto_mode)
	{
		CTImage* tempimage = ReadImage(filename);
		GLint mode;
		if (tempimage->nChannels == 4)
			mode = bgra;
		else
			mode = bgr;
		return RegTexture2d(tempimage, mode, arrange, quality);
	}
	else
		return RegTexture2d(ReadImage(filename) ,RGBmode, arrange, quality);
}

CTTexture CppTools::CTGL::ReadTextureWithMask2d(const std::string& filename,
												const std::string& maskname,
												const CTImageMode RGBmode,
												const GLint arrange, const GLint quality)
{
	if (RGBmode == auto_mode)
		return NULL;
	return RegTexture2d(ReadImage(filename, maskname), RGBmode, arrange, quality);
}

void CppTools::CTGL::DelTexture(const CTTexture id)
{
	glDeleteTextures(1, &id);
}

void CppTools::CTGL::GlewInit()
{
	if(glewInit())
		throw CppTools::CTException::CTGLException::CTGLEWInitFail(Ver());
}

CTGLHandle CppTools::CTGL::NewBO(CTGlewEnum bo_mode, CTGlewEnum draw_mode, UINT memory_size, const GLvoid* data)
{
	CTGLHandle bo;
	bo = NewBuffer();
	glBindBuffer(bo_mode, bo);
	glBufferData(bo_mode, memory_size, data, draw_mode);
	return bo;
}

//void CppTools::CTGL::ctglewInit()
//{
//	//����һ��α���ڣ����ڴ���glew����
//	/*WNDCLASS wc;
//	ZeroMemory(&wc, sizeof(WNDCLASS));
//	wc.hInstance = GetModuleHandle(NULL);
//	wc.lpszClassName = "GLEW dummy window";
//	if(!RegisterClass(&wc))
//		throw GLWndNotRegister();
//	HWND hwnd = CreateWindow("GLEW dummy window", "GLEW dummy window", dwStyle,
//		                     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//							 NULL, NULL, GetModuleHandle(NULL), NULL);*/
//	HGLRC ew_hRC;
//	HDC ew_hDC;
//	HWND ew_hWnd;
//	WNDCLASS ew_wc;
//	HINSTANCE ew_hInstance;
//
//	GLuint ew_PixelFormat;                                 // �������ƥ��Ľ��	
//	DWORD ew_dwExStyle;                                    // ��չ���ڷ��
//	DWORD ew_dwStyle;                                      // ���ڷ��
//
//	RECT ew_WindowRect;                                    // ȡ�þ��ε����ϽǺ����½ǵ�����ֵ
//	ew_WindowRect.left = (long)0;                          // ��Left ��Ϊ 0
//	ew_WindowRect.right = (long)100;                     // ��Right ��ΪҪ��Ŀ��
//	ew_WindowRect.top = (long)0;                           // ��Top ��Ϊ 0
//	ew_WindowRect.bottom = (long)100;                   // ��Bottom ��ΪҪ��ĸ߶�
//	ew_hInstance = GetModuleHandle(NULL);                  // ȡ�����Ǵ��ڵ�ʵ��
//	ew_wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;      // �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
//	ew_wc.lpfnWndProc = (WNDPROC) ctGLWnd::WndProc;                 // WndProc������Ϣ
//	ew_wc.cbClsExtra = 0;                                  // �޶��ⴰ������
//	ew_wc.cbWndExtra = 0;                                  // �޶��ⴰ������
//	ew_wc.hInstance = ew_hInstance;                           // ����ʵ��
//	ew_wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);             // װ��ȱʡͼ��
//	ew_wc.hCursor = LoadCursor(NULL, IDC_ARROW);           // װ�����ָ��
//	ew_wc.hbrBackground = NULL;                            // GL����Ҫ����
//	ew_wc.lpszMenuName = NULL;                             // ����Ҫ�˵�
//	ew_wc.lpszClassName = "GLEW dummy window";                        // �趨������
//	if (!RegisterClass(&ew_wc))                            // ����ע�ᴰ����
//		throw GLWndNotRegister();
//	ew_dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;// ��չ������
//	ew_dwStyle = WS_OVERLAPPEDWINDOW;                 // ������
//	AdjustWindowRectEx(&ew_WindowRect, ew_dwStyle, FALSE, ew_dwExStyle);
//	if (!(ew_hWnd = CreateWindowEx( ew_dwExStyle,            // ��չ������
//								"GLEW dummy window",      // ������
//								"GLEW dummy window",                 // ���ڱ���
//								WS_CLIPSIBLINGS|       // ����Ĵ���������
//								WS_CLIPCHILDREN|       // ����Ĵ���������
//								ew_dwStyle,               // ѡ��Ĵ�������
//								0,0,                   // ����λ��
//								ew_WindowRect.right-ew_WindowRect.left,
//								                       // ��������õĴ��ڿ��
//								ew_WindowRect.bottom-ew_WindowRect.top,
//								                       // ��������õĴ��ڸ߶�
//								NULL,                  // �޸�����
//								NULL,                  // �޲˵�
//								ew_hInstance,             // ʵ��
//								NULL)))                // ����WM_CREATE�����κζ���
//		throw GLWndNotCreate();
//
//	if(!ew_hWnd)
//		throw GLWndNotCreate();
//	ShowWindow(ew_hWnd, SW_HIDE);
//	ew_hDC = GetDC(ew_hWnd);
//	if(!ew_hDC)
//		throw GLWndErrHDC();
//	static CTPfd ew_pfd=                  //pfd ���ߴ���������ϣ���Ķ���
//	{
//		sizeof(CTPfd),                 //������ʽ�������Ĵ�С
//		1,                                             //�汾��
//		PFD_DRAW_TO_WINDOW|                            //��ʽ����֧�ִ���
//		PFD_SUPPORT_OPENGL|                            //��ʽ����֧��OpenGL
//		PFD_DOUBLEBUFFER,                              //����֧��˫����
//		PFD_TYPE_RGBA,                                 //����RGBA��ʽ
//		16,                                          //ѡ��ɫ�����
//		0,0,0,0,0,0,                                   //���Ե�ɫ��λ
//		0,                                             //��Alpha����
//		0,                                             //����ShiftBit
//		0,                                             //�޾ۼ�����
//		0,0,0,0,                                       //���Ծۼ�λ
//		16,                                            //16λZ-����(��Ȼ���)
//		0,                                             //��ģ�建��
//		0,                                             //�޸�������
//		PFD_MAIN_PLANE,                                //����ͼ��
//		0,                                             //����
//		0,0,0                                          //���Բ�����
//	};
//	ew_PixelFormat = ChoosePixelFormat(ew_hDC, &ew_pfd);
//	if(!ew_PixelFormat)
//		throw GLWndErrPFD();
//	if(!SetPixelFormat(ew_hDC, ew_PixelFormat, &ew_pfd))
//		throw GLWndErrSetPFD();
//	ew_hRC = wglCreateContext(ew_hDC);
//	if(!ew_hRC)
//	{
//		ReleaseDC(ew_hWnd, ew_hDC);
//		throw GLWndErrHRC();
//	}
//	if(!wglMakeCurrent(ew_hDC, ew_hRC))
//	{
//		ReleaseDC(ew_hWnd, ew_hDC);
//		wglDeleteContext(ew_hRC);
//		throw GLWndErrCurrentHRC();
//	}
//	GLenum glew_err = glewInit();
//	wglMakeCurrent(NULL, NULL);
//	wglDeleteContext(ew_hRC);
//	DestroyWindow(ew_hWnd);
//	UnregisterClass("GLEW dummy window", GetModuleHandle(NULL));
//	if(glew_err != GLEW_OK)
//		throw GLEWInitFail(ctglVer());
//}