#include "stdafx.h"
#include <gl\CTGLUT.h>

void CppTools::CTGL::GLUT::CreateGLUTWindows(GLint* argc, GLchar* argv[],
								 CGUTEnum display_mode,
								 GLsizei position_x, GLsizei position_y,
								 GLsizei width, GLsizei height,
								 GLchar* title,
								 CGUTInitFunc initFunc,
								 CGUTDisplayFunc displayFunc,
								 CGUTReshapeFunc reshapeFunc,
								 CGUTKeyboardFunc keyboardFunc,
								 CGUTMouseFunc mouseFunc,
								 CGUTIdleFunc idleFunc,
								 CGUTMotionFunc motionFunc)
{
	glutInit(argc, argv);
	glutInitDisplayMode(display_mode);
	glutInitWindowPosition(position_x, position_y);
	glutInitWindowSize(width, height);
	glutCreateWindow(title);
	glutDisplayFunc(displayFunc);
	glutReshapeFunc(reshapeFunc);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(motionFunc);
	glutIdleFunc(idleFunc);
	if(initFunc)
		(*initFunc)();
	glutMainLoop();
}

void CppTools::CTGL::GLUT::Reshape2d(GLint width, GLint height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void CppTools::CTGL::GLUT::Reshape3d(GLint width, GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	glFrustum(-x, +x, -1.0, +1.0, cgut_3d_near, cgut_3d_far);
	glMatrixMode(GL_MODELVIEW);
}