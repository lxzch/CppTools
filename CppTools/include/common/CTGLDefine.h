#pragma once

#ifndef CTGLDEFINE_H
#define CTGLDEFINE_H

#ifdef _WINDOWS
#include "windows.h"
#endif

typedef GLuint		CTDisplayMode;

typedef GLuint		CTTexture;
typedef CTTexture	CTTexture1d;
typedef CTTexture	CTTexture2d;
typedef CTTexture	CTTexture3d;

typedef GLuint		CTMask;

typedef GLuint		CTImageDatau;
typedef GLint		CTImageDatai;
typedef GLuint		CTImageMode;

typedef PIXELFORMATDESCRIPTOR CTPfd;

typedef GLuint		CTGLHandle;

typedef char GLchar;

namespace CppTools
{
	namespace CTGL
	{
		typedef enum CPPTOOLS_TYPE_API _CTGLEnum
		{
			//�Զ������
			auto_mode = -1,


			//��������
			rgb = GL_RGB,
			rgba = GL_RGBA,
			bgr = GL_BGR_EXT,
			bgra = GL_BGRA_EXT,

			gl_version = GL_VERSION,

			color_buffer = GL_COLOR_BUFFER_BIT,
			depth_buffer = GL_DEPTH_BUFFER_BIT,

			depth_test = GL_DEPTH_TEST,
			alpha_test = GL_ALPHA_TEST,

			//�������ò���
			texture_1d = GL_TEXTURE_1D,
			texture_2d = GL_TEXTURE_2D,
			blend = GL_BLEND,

			//������ģʽ
			zero = GL_ZERO,
			one = GL_ONE,
			src_a = GL_SRC_ALPHA,
			dst_a = GL_DST_ALPHA,
			src_color = GL_SRC_COLOR,
			dst_color = GL_DST_COLOR,
			one_src_a = GL_ONE_MINUS_SRC_ALPHA,
			one_dst_a = GL_ONE_MINUS_DST_ALPHA,

			//����ʹ�ò���
			unpack = GL_UNPACK_ALIGNMENT,

			wrap_s = GL_TEXTURE_WRAP_S,
			wrap_t = GL_TEXTURE_WRAP_T,

			clamp = GL_CLAMP,
			repeat = GL_REPEAT,

			mag_filter = GL_TEXTURE_MAG_FILTER,						//nearest linear
			min_filter = GL_TEXTURE_MIN_FILTER,						//nearest linear ��

			nearest = GL_NEAREST,									//�����
			linear = GL_LINEAR,										//˫���Բ���
			nearest_mipmap_nearest = GL_NEAREST_MIPMAP_NEAREST,
			nearest_mipmap_linear = GL_NEAREST_MIPMAP_LINEAR,
			linear_mipmap_nearest = GL_LINEAR_MIPMAP_NEAREST,
			linear_mipmap_linear = GL_LINEAR_MIPMAP_LINEAR,			//�����Բ���

			light = GL_LIGHTING,
		} CTGLEnum;

		//glBegin��ctglStart�Ĳ���
		typedef enum CPPTOOLS_TYPE_API _CTGLShapeEnum
		{
			gl_points = GL_POINTS,					//������
			gl_lines = GL_LINES,					//һ�Զ��㱻���ͳ�ֱ��
			gl_lines_s = GL_LINE_STRIP,				//��������ֱ��
			gl_lines_l = GL_LINE_LOOP,				//��������ֱ�ߣ�������ĩ��������
			gl_triangles = GL_TRIANGLES,			//3�����㱻���ͳ�������
			gl_triangles_s = GL_TRIANGLE_STRIP,		//����ʱ��˳���������ӵ������δ�
			gl_triangles_f = GL_TRIANGLE_FAN,		//�����һ������������δ�
			gl_quads = GL_QUADS,					//4�����㱻���ͳ��ı���
			gl_quads_s = GL_QUAD_STRIP,				//����ʱ��˳���������ӵ��ı��δ�
			gl_polygon = GL_POLYGON,				//����Σ�������n>=3��͹�����
		} CTGLShapeEnum;

		typedef enum CPPTOOLS_TYPE_API _CTGLLightEnum
		{
			light0 = GL_LIGHT0,
			light1 = GL_LIGHT1,
			light2 = GL_LIGHT2,
			light3 = GL_LIGHT3,
			light4 = GL_LIGHT4,
			light5 = GL_LIGHT5,
			light6 = GL_LIGHT6,
			light7 = GL_LIGHT7,
		} CTGLLightEnum;

		typedef enum CPPTOOLS_TYPE_API _CTGLFaceEnum
		{
			gl_front = GL_FRONT,
			gl_back = GL_BACK,
			gl_front_back = GL_FRONT_AND_BACK,
		} CTGLFaceEnum;

		typedef enum CPPTOOLS_TYPE_API _CTGLDataTypeEnum
		{
			gl_short = GL_SHORT,
			gl_int = GL_INT,
			gl_float = GL_FLOAT,
			gl_double = GL_DOUBLE,

			gl_byte = GL_BYTE,
			gl_ubyte = GL_UNSIGNED_BYTE,
			gl_ushort = GL_UNSIGNED_SHORT,
			gl_uint = GL_UNSIGNED_INT,
		} CTGLDataTypeEnum;

		typedef enum CPPTOOLS_TYPE_API _CTGlewEnum
		{
			texture_3d = GL_TEXTURE_3D,
			texture_cube = GL_TEXTURE_CUBE_MAP,
			wrap_r = GL_TEXTURE_WRAP_R,
			clamp_to_edge = GL_CLAMP_TO_EDGE,
			clamp_to_border = GL_CLAMP_TO_BORDER,
			mirrored = GL_MIRRORED_REPEAT,

			//mipmap�����
			mipmap_base_level = GL_TEXTURE_BASE_LEVEL,
			mipmap_max_level = GL_TEXTURE_MAX_LEVEL,

			mipmap_1d_array = GL_TEXTURE_1D_ARRAY,
			mipmap_2d_array = GL_TEXTURE_2D_ARRAY,
			mipmap_cube_map = GL_TEXTURE_CUBE_MAP,

			//��ɫ����������
			vertex_shader = GL_VERTEX_SHADER,
			fragment_shader = GL_FRAGMENT_SHADER,

			//������������
			ebo_buffer = GL_ELEMENT_ARRAY_BUFFER,
			vbo_buffer = GL_ARRAY_BUFFER,

			//������ʹ�÷�ʽ
			bo_static = GL_STATIC_DRAW,
			bo_dynamic = GL_DYNAMIC_DRAW,
		} CTGlewEnum;

		//���帨����������

		typedef CTData::CTColor3<GLubyte>		CGColor3u;
		typedef CTData::CTColor3<GLint>			CGColor3i;
		typedef CTData::CTColor3<GLfloat>		CGColor3f;
		typedef CTData::CTColor3<GLdouble>		CGColor3d;

		template<typename Tx>
		struct CPPTOOLS_TYPE_API CGColor3List
		{
			CTData::CTColor3<Tx> left_top, left_bottom, right_top, right_bottom;
		};

		typedef CGColor3List<GLubyte>		CGColor3uList;
		typedef CGColor3List<GLint>			CGColor3iList;
		typedef CGColor3List<GLfloat>		CGColor3fList;
		typedef CGColor3List<GLdouble>		CGColor3dList;

		typedef CTData::CTColor4<GLubyte>		CGColor4u;
		typedef CTData::CTColor4<GLint>			CGColor4i;
		typedef CTData::CTColor4<GLfloat>		CGColor4f;
		typedef CTData::CTColor4<GLdouble>		CGColor4d;

		typedef CTData::CTPoint2<GLubyte>		CGPoint2u;
		typedef CTData::CTPoint2<GLint>			CGPoint2i;
		typedef CTData::CTPoint2<GLfloat>		CGPoint2f;
		typedef CTData::CTPoint2<GLdouble>		CGPoint2d;

		typedef CTData::CTSize2<GLubyte>		CGSize2u;
		typedef CTData::CTSize2<GLint>			CGSize2i;
		typedef CTData::CTSize2<GLfloat>		CGSize2f;
		typedef CTData::CTSize2<GLdouble>		CGSize2d;

		typedef CGPoint2i						cgPos;
		typedef CGSize2i						cgSize;

		typedef CTData::CTPoint3<GLubyte>		CGPoint3u;
		typedef CTData::CTPoint3<GLint>			CGPoint3i;
		typedef CTData::CTPoint3<GLfloat>		CGPoint3f;
		typedef CTData::CTPoint3<GLdouble>		CGPoint3d;

		typedef CTData::CTRect2<GLubyte>		CGRect2u;
		typedef CTData::CTRect2<GLint>			CGRect2i;
		typedef CTData::CTRect2<GLfloat>		CGRect2f;
		typedef CTData::CTRect2<GLdouble>		CGRect2d;

		typedef CTData::CTRect3<GLubyte>		CGRect3u;
		typedef CTData::CTRect3<GLint>			CGRect3i;
		typedef CTData::CTRect3<GLfloat>		CGRect3f;
		typedef CTData::CTRect3<GLdouble>		CGRect3d;

		//��װ����ɫ
		namespace CTColor
		{
			static const CGColor3d Black(0.0, 0.0, 0.0);
			static const CGColor3d Red(1.0, 0.0, 0.0);
			static const CGColor3d Green(0.0, 1.0, 0.0);
			static const CGColor3d Blue(0.0, 0.0, 1.0);
			static const CGColor3d Yellow(1.0, 1.0, 0.0);
			static const CGColor3d Violet(1.0, 0.0, 1.0);
			static const CGColor3d Cyan(0.0, 1.0, 1.0);
			static const CGColor3d White(1.0, 1.0, 1.0);
		};
	}
}
#endif