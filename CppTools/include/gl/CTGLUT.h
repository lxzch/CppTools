#pragma once
#ifndef CTGLUT_H
#define CTGLUT_H

#include <CTData>
#include <CTGLEW>
#include <glut.h>

#ifndef p_func_v_v
typedef GLvoid (*p_func_v_v)(GLvoid);
#endif

#ifndef p_func_v_ii
typedef GLvoid (*p_func_v_ii)(GLint, GLint);
#endif

#ifndef p_func_v_uii
typedef GLvoid (*p_func_v_uii)(GLubyte, GLint, GLint);
#endif

#ifndef p_func_v_iiii
typedef GLvoid (*p_func_v_iiii)(GLint, GLint, GLint, GLint);
#endif

typedef CppTools::CTData::CTFuncBase<GLvoid>::p_TFunc									CGUTInitFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid>::p_TFunc									CGUTDisplayFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid, GLint, GLint>::p_TFunc_uv					CGUTReshapeFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid, GLubyte, GLint, GLint>::p_TFunc_uvw		CGUTKeyboardFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid, GLint, GLint, GLint, GLint>::p_TFunc_uvwx	CGUTMouseFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid, GLint, GLint>::p_TFunc_uv					CGUTMotionFunc;
typedef CppTools::CTData::CTFuncBase<GLvoid>::p_TFunc									CGUTIdleFunc;

namespace CppTools
{
	namespace CTGL
	{
		namespace GLUT
		{
			typedef enum _CGUTEnum
			{
				glut_single = GLUT_SINGLE,
				glut_double = GLUT_DOUBLE,
				glut_index = GLUT_INDEX,
				glut_rgb = GLUT_RGB,
				glut_rgba = GLUT_RGBA,
			} CGUTEnum;

			static GLdouble cgut_3d_near = 1.5;
			static GLdouble cgut_3d_far = 20.0;

			CPPTOOLS_API inline void Update()
			{
				glutSwapBuffers();
			}

			CPPTOOLS_API inline void SetReshape()
			{
				glutPostRedisplay();
			}

			CPPTOOLS_API inline void SetIdle(CGUTInitFunc idleFunc)
			{
				glutIdleFunc(idleFunc);
			}

			CPPTOOLS_API void CreateGLUTWindows(GLint* argc, GLchar* argv[],
								CGUTEnum display_mode,
								GLsizei position_x, GLsizei position_y,
								GLsizei width, GLsizei height,
								GLchar* title = NULL,
								CGUTInitFunc initFunc = NULL,
								CGUTDisplayFunc displayFunc = NULL,
								CGUTReshapeFunc reshapeFunc = NULL,
								CGUTKeyboardFunc keyboardFunc = NULL,
								CGUTMouseFunc mouseFunc = NULL,
								CGUTIdleFunc idleFunc = NULL,
								CGUTMotionFunc motionFunc = NULL);
			CPPTOOLS_API void Reshape2d(GLint width, GLint height);
			CPPTOOLS_API void Reshape3d(GLint width, GLint height);
		}
	}
}

#endif