#include "stdafx.h"
#include <gl\CTGLWnd.h>

GLvoid CppTools::CTGL::CTGLWnd::reshape(GLsizei width, GLsizei height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	glFrustum(-x, +x, -1.0, +1.0, 4, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

void CppTools::CTGL::CTGLWnd::init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	Cls();
	glEnable(GL_DEPTH_TEST);
}

void CppTools::CTGL::CTGLWnd::display()
{
}