#pragma once
#ifndef CTDEFINE_H
#define CTDEFINE_H

#include <common\CTComDefine.h>

//区域语言选择为中文
//The default language is Chinese.Modify this code if you want to change another language.
#define CT_LANGUAGE		CT_CHN

#include <windows.h>

#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <ctime>
//包含所需STL标准库

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <vector>
#include <list>
#include <map>

#include <exception>

//类型再定义

#if !defined (_gl_h_) \
	&& !defined (__GL_H__) \
	&& !defined(__X_GL_H) \
	&& !defined (__REGAL_H__) \
	&& !defined (__glext_h_) \
	&& !defined (__GLEXT_H_) \
	&& !defined (__gl_ATI_h_) \
	&& !defined (__glew_h__) \
	&& !defined (__GLEW_H__)

typedef UINT			GLenum;
typedef UINT			GLbitfield;
typedef UINT			GLuint;
typedef int				GLint;
typedef int				GLsizei;
typedef UCHAR			GLboolean;
typedef signed char		GLbyte;
typedef short			GLshort;
typedef UCHAR			GLubyte;
typedef unsigned short	GLushort;
typedef unsigned long	GLulong;
typedef float			GLfloat;
typedef float			GLclampf;
typedef double			GLdouble;
typedef double			GLclampd;
typedef void			GLvoid;
typedef char			GLchar;

#endif

#ifdef CCU_SURPORT
 #define CCU_DEVICE __device__
 #define CCU_HOST __host__
 #define CCU_GLOBAL __global__
 #define CPPTOOLS_API_HOSTDEVICE __host__ __device__
 #define CPPTOOLS_CLASSFUNC_HOSTDEVICE __host__ __device__
#else
 #define CCU_DEVICE
 #define CCU_HOST
 #define CCU_GLOBAL
 #define CPPTOOLS_API_HOSTDEVICE CPPTOOLS_API
 #define CPPTOOLS_CLASSFUNC_HOSTDEVICE
#endif

//常用常量

const int ct_sz_uc		= sizeof(UCHAR);
const int ct_sz_c		= sizeof(char);
const int ct_sz_u		= sizeof(UINT);
const int ct_sz_i		= sizeof(int);
const int ct_sz_l		= sizeof(long);
const int ct_sz_f		= sizeof(float);
const int ct_sz_d		= sizeof(double);

const int ct_sz_p_uc	= sizeof(UCHAR*);
const int ct_sz_p_c		= sizeof(char*);
const int ct_sz_p_u		= sizeof(UINT*);
const int ct_sz_p_i		= sizeof(int*);
const int ct_sz_p_l		= sizeof(long*);
const int ct_sz_p_f		= sizeof(float*);
const int ct_sz_p_d		= sizeof(double*);
const int ct_sz_p_v		= sizeof(void*);

const int ct_sz_pp_uc	= sizeof(UCHAR**);
const int ct_sz_pp_c	= sizeof(char**);
const int ct_sz_pp_u	= sizeof(UINT**);
const int ct_sz_pp_i	= sizeof(int**);
const int ct_sz_pp_l	= sizeof(long**);
const int ct_sz_pp_f	= sizeof(float**);
const int ct_sz_pp_d	= sizeof(double**);
const int ct_sz_pp_v	= sizeof(void**);

const int ct_sz_ppp_uc	= sizeof(UCHAR***);
const int ct_sz_ppp_c	= sizeof(char***);
const int ct_sz_ppp_u	= sizeof(UINT***);
const int ct_sz_ppp_i	= sizeof(int***);
const int ct_sz_ppp_l	= sizeof(long***);
const int ct_sz_ppp_f	= sizeof(float***);
const int ct_sz_ppp_d	= sizeof(double***);
const int ct_sz_ppp_v	= sizeof(void***);

//函数参数说明符

#define __this_value_readonly
#define __this_value_readonly__maybe_NULL
#define __this_value_writeonly
#define __this_value_read_or_write
#define __this_value_create_by_new__you_must_delete_by_yourself

#define __ct_in			__this_value_readonly
#define __ct_in_opt		__this_value_readonly__maybe_NULL
#define __ct_out		__this_value_writeonly
#define __ct_in_out		__this_value_read_or_write
#define __ct_out_new	__this_value_created_by_new__must_delete_by_yourself

#include <common\CTUniform.h>
#include <common\CTDefine.inl>
#include <common\CTNoInherit.h>
#include <common\CTVer.h>

#endif /*CTDEFINE_H*/