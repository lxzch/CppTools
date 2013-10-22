#pragma once
#ifndef CTGLPAINTER_H
#define CTGLPAINTER_H

#include <gl\CTGLkits.h>

namespace CppTools
{
	namespace CTGL
	{
		//2άͼ�κ�����
		namespace CTGL2d
		{
			CPPTOOLS_API void Draw(const CGRect2f& rect, const CGColor3f& color);
			CPPTOOLS_API void Draw(const CGRect2d& rect, const CGColor3d& color);
			CPPTOOLS_API void Draw(const CGRect2f& rect, const CGColor3fList& color);
			CPPTOOLS_API void Draw(const CGRect2d& rect, const CGColor3dList& color);
			CPPTOOLS_API void Draw(const CGRect2f& rect, const CGRect2f& texture, const CTTexture id, const bool transparent = false);
			CPPTOOLS_API void Draw(const CGRect2d& rect, const CGRect2d& texture, const CTTexture id, const bool transparent = false);
			CPPTOOLS_API void DrawCircle(const CGPoint2d& center, const GLdouble radius, const CGColor3d& centercolor = CTColor::Red, const CGColor3d& circlecolor = CTColor::Red);

			CPPTOOLS_API void DrawHyaline(const CGRect2d& rect, const CGRect2d& mask, const CTMask m_id, const CTTexture t_id);
		}

		//3άͼ�κ�����
		namespace CTGL3d
		{
			typedef enum CPPTOOLS_TYPE_API _CTGLPlane
			{
				zox = 1,  //�������� ��XoZƽ�� ��ƽ��
				xoz = 2,  //�������� ��XoZƽ�� ��ƽ��
				zoy = 3,  //�������� ��YoZƽ�� ��ƽ��
				yoz = 4,  //�������� ��YoZƽ�� ��ƽ��
				yox = 5,  //�������� ��XoYƽ�� ��ƽ��
				xoy = 6,  //�������� ��XoYƽ�� ��ƽ��
				
			} CTGLPlane;

			CPPTOOLS_API void SetFace(CGRect3f& rect, GLfloat x, GLfloat y, GLfloat z, CTGLPlane plane, const GLfloat center_x = 0.0, const GLfloat center_y = 0.0, const GLfloat center_z = 0.0);
			CPPTOOLS_API void SetFace(CGRect3d& rect, GLdouble x, GLdouble y, GLdouble z, CTGLPlane plane, const GLdouble center_x = 0.0, const GLdouble center_y = 0.0, const GLdouble center_z = 0.0);
			CPPTOOLS_API void SetFace(CGRect3f& rect, GLfloat x, GLfloat y, GLfloat z, CTGLPlane plane, const CGPoint3f& center);
			CPPTOOLS_API void SetFace(CGRect3d& rect, GLdouble x, GLdouble y, GLdouble z, CTGLPlane plane, const CGPoint3d& center);
			CPPTOOLS_API void Draw(const CGRect3f& rect, const CGColor3f& color);
			CPPTOOLS_API void Draw(const CGRect3d& rect, const CGColor3d& color);
			CPPTOOLS_API void Draw(const CGRect3f& rect, const CGColor3fList& color);
			CPPTOOLS_API void Draw(const CGRect3d& rect, const CGColor3dList& color);
			CPPTOOLS_API void Draw(const CGRect3f& rect, const CGRect2f& texture, const CTTexture id);
			CPPTOOLS_API void Draw(const CGRect3d& rect, const CGRect2d& texture, const CTTexture id);
		}
	}
}

#endif