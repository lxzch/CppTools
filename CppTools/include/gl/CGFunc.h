#pragma once
#ifndef CGFUNC_H
#define CGFUNC_H

#include <common\CGDefine.h>

#pragma comment (lib, "winmm.lib")

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glew32.lib")

namespace CppTools
{
	namespace CTGL
	{
		//封装的OpenGL函数
		CPPTOOLS_INLINEFUNC_API inline const GLubyte* Ver()
		{
			return glGetString(gl_version);
		}

		CPPTOOLS_INLINEFUNC_API inline void Cls()
		{
			glClear(color_buffer);
		}

		CPPTOOLS_INLINEFUNC_API inline void Clsd()
		{
			glClear(color_buffer | depth_buffer);
		}

		CPPTOOLS_INLINEFUNC_API inline void ClColor()
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		}

		CPPTOOLS_INLINEFUNC_API inline void Use(CTGLEnum state)
		{
			glEnable(state);
		}

		CPPTOOLS_INLINEFUNC_API inline void Disuse(CTGLEnum state)
		{
			glDisable(state);
		}

		CPPTOOLS_INLINEFUNC_API inline void Start(CTGLShapeEnum shape)
		{
			glBegin(shape);
		}

		CPPTOOLS_INLINEFUNC_API inline void End()
		{
			glEnd();
		}

		CPPTOOLS_INLINEFUNC_API inline void ClMatrix()
		{
			glLoadIdentity();
		}

		CPPTOOLS_INLINEFUNC_API inline void SaveMatrix()
		{
			glPushMatrix();
		}

		CPPTOOLS_INLINEFUNC_API inline void LoadMatrix()
		{
			glPopMatrix();
		}

		//CT扩展的函数
		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer2(Tx** point, GLint position, Tx x, Tx y)
		{
			point[position][0] = x;
			point[position][1] = y;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer2(Tx* point, GLint position, Tx x, Tx y)
		{
			point[position * 2] = x;
			point[position * 2 + 1] = y;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer2(Tx* point, Tx x, Tx y)
		{
			point[0] = x;
			point[1] = y;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer3(Tx** point, GLint position, Tx x, Tx y, Tx z)
		{
			point[position][0] = x;
			point[position][1] = y;
			point[position][2] = z;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer3(Tx* point, GLint position, Tx x, Tx y, Tx z)
		{
			point[position * 3] = x;
			point[position * 3 + 1] = y;
			point[position * 3 + 2] = z;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer3(Tx* point, Tx x, Tx y, Tx z)
		{
			point[0] = x;
			point[1] = y;
			point[2] = z;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer4(Tx** point, GLint position, Tx x, Tx y, Tx z, Tx a)
		{
			point[position][0] = x;
			point[position][1] = y;
			point[position][2] = z;
			point[position][3] = a;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer4(Tx* point, GLint position, Tx x, Tx y, Tx z, Tx a)
		{
			point[position * 4] = x;
			point[position * 4 + 1] = y;
			point[position * 4 + 2] = z;
			point[position * 4 + 3] = a;
		}

		template<typename Tx>
		CPPTOOLS_TFUNC_API inline void SetPointer4(Tx* point, Tx x, Tx y, Tx z, Tx a)
		{
			point[0] = x;
			point[1] = y;
			point[2] = z;
			point[3] = a;
		}

		//CT封装的glew函数

		CPPTOOLS_API void GlewInit();
		CPPTOOLS_API BOOL ChoosePixelFormat(HDC hdc, const int* piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

		template <typename Tx>
		CPPTOOLS_INLINEFUNC_API inline void MultiElementsDraw(CTGLShapeEnum mode, GLsizei *count, CTGLDataTypeEnum type, Tx** vertex_index, GLsizei vertex_count)
		{
			glMultiDrawElements(mode, (const GLsizei*)count, type, (const GLvoid **)vertex_index, vertex_count);
		}

		template <typename Tx>
		CPPTOOLS_INLINEFUNC_API inline void SetVertex(GLint size, CTGLDataTypeEnum data_type, GLsizei stride, Tx* pointer)
		{
			glVertexPointer(size, data_type, stride, (const GLvoid*)pointer);
		}

		template <typename Tx>
		CPPTOOLS_INLINEFUNC_API inline void SetColor(GLint size, CTGLDataTypeEnum data_type, GLsizei stride, Tx* pointer)
		{
			glColorPointer(size, data_type, stride, (const GLvoid*)pointer);
		}

		template <typename Tx>
		CPPTOOLS_INLINEFUNC_API inline void SetNormal(CTGLDataTypeEnum data_type, GLsizei stride, Tx* pointer)
		{
			glNormalPointer(data_type, stride, (const GLvoid*)pointer);
		}

		template <typename Tx>
		CPPTOOLS_INLINEFUNC_API inline void SetTexCoord(GLint size, CTGLDataTypeEnum data_type, GLsizei stride, Tx* pointer)
		{
			glTexCoordPointer(size, data_type, stride, (const GLvoid*)pointer);
		}
		
		//CT扩展的glew函数

		CPPTOOLS_INLINEFUNC_API inline void VAon()
		{
			glEnableClientState(GL_VERTEX_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline void VAoff()
		{
			glDisableClientState(GL_VERTEX_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline void CAon()
		{
			glEnableClientState(GL_COLOR_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline void CAoff()
		{
			glDisableClientState(GL_COLOR_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline void NAon()
		{
			glEnableClientState(GL_NORMAL_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline void NAoff()
		{
			glDisableClientState(GL_NORMAL_ARRAY);
		}

		CPPTOOLS_INLINEFUNC_API inline CTGLHandle NewBuffer()
		{
			CTGLHandle bo;
			glGenBuffers(1, &bo);
			return bo;
		}

		CPPTOOLS_INLINEFUNC_API inline CTGLHandle* NewBuffers(GLsizei number)
		{
				CTGLHandle* bo = CppTools::CTMemory::NewArray1d<CTGLHandle>(number);
				glGenBuffers(number, bo);
				return bo;
		}		

		CPPTOOLS_API CTGLHandle NewBO(CTGlewEnum bo_mode, CTGlewEnum draw_mode, UINT memory_size, const GLvoid* data = 0);
	}
}

#endif