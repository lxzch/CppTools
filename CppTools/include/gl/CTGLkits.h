#pragma once
#ifndef CTGLKITS_H
#define CTGLKITS_H

#ifdef QTOPENGL
#include <QtOpenGL\QGLWidget>
#endif

#pragma warning(disable:4996)

#include <cv.h>
#include <highgui.h>

#include <CTGLEW>
#include <gl\CTGLLight.h>
#include <gl\CTGLMaterial.h>
#include <CTMemory>

#ifdef _DEBUG
#pragma comment (lib, "opencv_highgui231d.lib")
#pragma comment (lib, "opencv_core231d.lib")
#endif
#ifdef NDEBUG
#pragma comment (lib, "opencv_highgui231.lib")
#pragma comment (lib, "opencv_core231.lib")
#endif

typedef IplImage CTImage;

namespace CppTools
{
	namespace CTGL
	{
		//CT扩展的纹理图片处理函数
		CPPTOOLS_API bool IsTexture(CTTexture& texture);
		CPPTOOLS_API CGPoint2d SetPoint(const GLdouble x, const GLdouble y);
		CPPTOOLS_API CGPoint2f SetPoint(const GLfloat x, const GLfloat y);
		CPPTOOLS_API CGSize2d SetSize(const GLdouble width, const GLdouble height);
		CPPTOOLS_API CGSize2f SetSize(const GLfloat width, const GLfloat height);
		CPPTOOLS_API CGRect2d SetRect(const GLdouble left_x, const GLdouble left_y, const GLdouble right_x, const GLdouble right_y);
		CPPTOOLS_API CGRect2f SetRect(const GLfloat left_x, const GLfloat left_y, const GLfloat right_x, const GLfloat right_y);
		CPPTOOLS_API CTImage* ReadImage(const std::string& filename = "");
		CPPTOOLS_API CTImage* ReadImage(const std::string filename, const std::string maskfile);

		CPPTOOLS_API CTTexture RegTexture2d(const GLsizei& size_x, const GLsizei& size_y, const CTImageDatau* data,
											const CTImageMode& RGBmode = bgr,
											const GLint& arrange = repeat, const GLint& quality = linear);
		CPPTOOLS_API CTTexture RegTexture2d(const CTImage* data,
											const CTImageMode& RGBmode = bgr,
											const GLint& arrange = repeat, const GLint& quality = linear);
		CPPTOOLS_API CTTexture ReadTexture2d(const std::string& filename = "",
											 const CTImageMode RGBmode = bgr,
											 const GLint arrange = repeat, const GLint quality = linear);
		CPPTOOLS_API CTTexture ReadTextureWithMask2d(const std::string& filename = "",
													 const std::string& maskname = "",
													 const CTImageMode RGBmode = bgr,
													 const GLint arrange = repeat, const GLint quality = linear);
		CPPTOOLS_API void DelTexture(const CTTexture id);
	}
}

#endif