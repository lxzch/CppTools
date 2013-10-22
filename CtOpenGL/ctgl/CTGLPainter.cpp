#include "stdafx.h"
#include <gl\CTGLPainter.h>

void CppTools::CTGL::CTGL2d::Draw(const CGRect2f& rect, const CGColor3f& color)
{
	Start(gl_quads);
	{
		glColor3f(color.red, color.green, color.blue);
		glVertex2f(rect.left.x, rect.left.y);
		glVertex2f(rect.right.x, rect.left.y);
		glVertex2f(rect.right.x, rect.right.y);
		glVertex2f(rect.left.x, rect.right.y);
	}End();
}

void CppTools::CTGL::CTGL2d::Draw(const CGRect2d& rect, const CGColor3d& color)
{
	Start(gl_quads);
	{
		glColor3d(color.red, color.green, color.blue);
		glVertex2d(rect.left.x, rect.left.y);
		glVertex2d(rect.right.x, rect.left.y);
		glVertex2d(rect.right.x, rect.right.y);
		glVertex2d(rect.left.x, rect.right.y);
	}End();
}

void CppTools::CTGL::CTGL2d::Draw(const CGRect2f& rect, const CGColor3fList& color)
{
	Start(gl_quads);
	{
		glColor3f(color.left_top.red, color.left_top.green, color.left_top.blue);				glVertex2d(rect.left.x, rect.left.y);
		glColor3f(color.right_top.red, color.right_top.green, color.right_top.blue);			glVertex2d(rect.right.x, rect.left.y);
		glColor3f(color.right_bottom.red, color.right_bottom.green, color.right_bottom.blue);	glVertex2d(rect.right.x, rect.right.y);
		glColor3f(color.left_bottom.red, color.left_bottom.green, color.left_bottom.blue);		glVertex2d(rect.left.x, rect.right.y);
	}End();
}

void CppTools::CTGL::CTGL2d::Draw(const CGRect2d& rect, const CGColor3dList& color)
{
	Start(gl_quads);
	{
		glColor3d(color.left_top.red, color.left_top.green, color.left_top.blue);				glVertex2d(rect.left.x, rect.left.y);
		glColor3d(color.right_top.red, color.right_top.green, color.right_top.blue);			glVertex2d(rect.right.x, rect.left.y);
		glColor3d(color.right_bottom.red, color.right_bottom.green, color.right_bottom.blue);	glVertex2d(rect.right.x, rect.right.y);
		glColor3d(color.left_bottom.red, color.left_bottom.green, color.left_bottom.blue);		glVertex2d(rect.left.x, rect.right.y);
	}End();
}

void CppTools::CTGL::CTGL2d::Draw(const CGRect2f& rect, const CGRect2f& texture, const CTTexture id, bool transparent)
{
	if(transparent)
	{
		Use(blend);
		glBlendFunc(src_a, one_src_a);
	}
	Use(texture_2d);
	glBindTexture(texture_2d, id);
	Start(gl_quads);
	{
		glTexCoord2f(texture.left.x, texture.left.y);		glVertex2f(rect.left.x, rect.left.y);
		glTexCoord2f(texture.right.x, texture.left.y);		glVertex2f(rect.right.x, rect.left.y);
		glTexCoord2f(texture.right.x, texture.right.y);		glVertex2f(rect.right.x, rect.right.y);
		glTexCoord2f(texture.left.x, texture.right.y);		glVertex2f(rect.left.x, rect.right.y);
	}End();
	Disuse(texture_2d);
	if(transparent)
		Disuse(blend);
}

void CppTools::CTGL::CTGL2d::Draw(const CGRect2d& rect, const CGRect2d& texture, const CTTexture id, bool transparent)
{
	if(transparent)
	{
		Use(blend);
		glBlendFunc(src_a, one_src_a);
	}
	Use(texture_2d);
	glBindTexture(texture_2d, id);
	Start(gl_quads);
	{
		glTexCoord2d(texture.left.x, texture.left.y);		glVertex2d(rect.left.x, rect.left.y);
		glTexCoord2d(texture.right.x, texture.left.y);		glVertex2d(rect.right.x, rect.left.y);
		glTexCoord2d(texture.right.x, texture.right.y);		glVertex2d(rect.right.x, rect.right.y);
		glTexCoord2d(texture.left.x, texture.right.y);		glVertex2d(rect.left.x, rect.right.y);
	}End();
	Disuse(texture_2d);
	if(transparent)
		Disuse(blend);
}

void CppTools::CTGL::CTGL2d::DrawHyaline(const CGRect2d& rect, const CGRect2d& mask, const CTMask m_id, const CTTexture t_id)
{
	Use(blend);
	glBlendFunc(one, dst_color);
	Draw(rect, mask, m_id);
	glBlendFunc(src_color, zero);
	Draw(rect, mask, t_id);
}

void CppTools::CTGL::CTGL3d::SetFace(CGRect3d& rect, GLdouble x, GLdouble y, GLdouble z, CTGLPlane plane, const GLdouble center_x, const GLdouble center_y, const GLdouble center_z)
{
	switch(plane)
	{
	case zox:  //从下往上 看XoZ平面 上平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x - x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x - x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case xoz:  //从上往下 看XoZ平面 下平面
		rect.left_top.x = center_x - x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x - x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case zoy:  //从右往左 看YoZ平面 左平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y - y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y - y;
		rect.left_bottom.z = center_z - z;
		break;
	case yoz:  //从左往右 看YoZ平面 右平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case yox:  //从外往里 看XoY平面 里平面		
		rect.left_top.x = center_x - x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z - z;
		rect.right_top.x = center_x - x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z - z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;		
		break;
	case xoy:  //从里往外 看XoY平面 外平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x - x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z + z;
		rect.left_bottom.x = center_x - x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z + z;
		break;
	default:
		break;
	}	
}

void CppTools::CTGL::CTGL3d::SetFace(CGRect3f& rect, GLfloat x, GLfloat y, GLfloat z, CTGLPlane plane, const GLfloat center_x, const GLfloat center_y, const GLfloat center_z)
{
	switch(plane)
	{
	case zox:  //从下往上 看XoZ平面 上平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x - x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x - x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case xoz:  //从上往下 看XoZ平面 下平面
		rect.left_top.x = center_x - x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x - x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case zoy:  //从右往左 看YoZ平面 左平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y - y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y + y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y + y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y - y;
		rect.left_bottom.z = center_z - z;
		break;
	case yoz:  //从左往右 看YoZ平面 右平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;
		break;
	case yox:  //从外往里 看XoY平面 里平面		
		rect.left_top.x = center_x - x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z - z;
		rect.right_top.x = center_x - x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z - z;
		rect.right_bottom.x = center_x + x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z - z;
		rect.left_bottom.x = center_x + x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z - z;		
		break;
	case xoy:  //从里往外 看XoY平面 外平面
		rect.left_top.x = center_x + x;
		rect.left_top.y = center_y + y;
		rect.left_top.z = center_z + z;
		rect.right_top.x = center_x + x;
		rect.right_top.y = center_y - y;
		rect.right_top.z = center_z + z;
		rect.right_bottom.x = center_x - x;
		rect.right_bottom.y = center_y - y;
		rect.right_bottom.z = center_z + z;
		rect.left_bottom.x = center_x - x;
		rect.left_bottom.y = center_y + y;
		rect.left_bottom.z = center_z + z;
		break;
	default:
		break;
	}	
}

void CppTools::CTGL::CTGL3d::SetFace(CGRect3f& rect, GLfloat x, GLfloat y, GLfloat z, CTGLPlane plane, const CGPoint3f& center)
{
	SetFace(rect, x, y, z, plane, center.x, center.y, center.z);
}

void CppTools::CTGL::CTGL3d::SetFace(CGRect3d& rect, GLdouble x, GLdouble y, GLdouble z, CTGLPlane plane, const CGPoint3d& center)
{
	SetFace(rect, x, y, z, plane, center.x, center.y, center.z);
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3f& rect, const CGColor3f& color)
{
	Start(gl_quads);
	{
		glColor3f(color.red, color.green, color.blue);
		glVertex3f(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glVertex3f(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
		glVertex3f(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glVertex3f(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
	}End();
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3d& rect, const CGColor3d& color)
{
	Start(gl_quads);
	{
		glColor3d(color.red, color.green, color.blue);
		glVertex3d(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glVertex3d(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
		glVertex3d(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glVertex3d(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
	}End();
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3f& rect, const CGColor3fList& color)
{
	Start(gl_quads);
	{
		glColor3f(color.left_top.red, color.left_top.green, color.left_top.blue);				glVertex3f(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glColor3f(color.right_top.red, color.right_top.green, color.right_top.blue);			glVertex3f(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
		glColor3f(color.right_bottom.red, color.right_bottom.green, color.right_bottom.blue);	glVertex3f(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glColor3f(color.left_bottom.red, color.left_bottom.green, color.left_bottom.blue);		glVertex3f(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
	}End();
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3d& rect, const CGColor3dList& color)
{
	Start(gl_quads);
	{
		glColor3d(color.left_top.red, color.left_top.green, color.left_top.blue);				glVertex3d(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glColor3d(color.right_top.red, color.right_top.green, color.right_top.blue);			glVertex3d(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
		glColor3d(color.right_bottom.red, color.right_bottom.green, color.right_bottom.blue);	glVertex3d(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glColor3d(color.left_bottom.red, color.left_bottom.green, color.left_bottom.blue);		glVertex3d(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
	}End();
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3f& rect, const CGRect2f& texture, const CTTexture id)
{
	Use(texture_2d);
	glBindTexture(texture_2d, id);
	Start(gl_quads);
	{
		glTexCoord2f(texture.left.x, texture.left.y);				glVertex3f(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glTexCoord2f(texture.right.x, texture.left.y);				glVertex3f(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glTexCoord2f(texture.right.x, texture.right.y);				glVertex3f(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
		glTexCoord2f(texture.left.x, texture.right.y);				glVertex3f(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
	}End();
	Disuse(texture_2d);
}

void CppTools::CTGL::CTGL3d::Draw(const CGRect3d& rect, const CGRect2d& texture, const CTTexture id)
{
	Use(texture_2d);
	glBindTexture(texture_2d, id);
	Start(gl_quads);
	{
		glTexCoord2d(texture.left.x, texture.left.y);				glVertex3d(rect.left_top.x, rect.left_top.y, rect.left_top.z);
		glTexCoord2d(texture.right.x, texture.left.y);				glVertex3d(rect.right_top.x, rect.right_top.y, rect.right_top.z);
		glTexCoord2d(texture.right.x, texture.right.y);				glVertex3d(rect.right_bottom.x, rect.right_bottom.y, rect.right_bottom.z);
		glTexCoord2d(texture.left.x, texture.right.y);				glVertex3d(rect.left_bottom.x, rect.left_bottom.y, rect.left_bottom.z);
	}End();
	Disuse(texture_2d);
}