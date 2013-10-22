#pragma once

#ifndef CTGLLIGHT_H
#define CTGLLIGHT_H

#include <CTGLEW>

namespace CppTools
{
	namespace CTGL
	{
		CPPTOOLS_INLINEFUNC_API inline void Lighton()
		{
			glEnable(GL_LIGHTING);
		}

		CPPTOOLS_INLINEFUNC_API inline void Lightoff()
		{
			glDisable(GL_LIGHTING);
		}

		CPPTOOLS_INLINEFUNC_API inline void UseLight(CTGLLightEnum light)
		{
			glEnable(light);
		}

		CPPTOOLS_INLINEFUNC_API inline void DisuseLight(CTGLLightEnum light)
		{
			glDisable(light);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightAmbient(CTGLLightEnum light, GLfloat* color)
		{
			glLightfv(light, GL_AMBIENT, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightDiffuse(CTGLLightEnum light, GLfloat* color)
		{
			glLightfv(light, GL_DIFFUSE, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpecular(CTGLLightEnum light, GLfloat* color)
		{
			glLightfv(light, GL_SPECULAR, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightPosition(CTGLLightEnum light, GLfloat* position)
		{
			glLightfv(light, GL_POSITION, position);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotDirection(CTGLLightEnum light, GLfloat* direction)
		{
			//设置聚光方向
			glLightfv(light, GL_SPOT_DIRECTION, direction);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotExponent(CTGLLightEnum light, GLfloat exponent)
		{
			//设置聚光指数
			glLightf(light, GL_SPOT_EXPONENT, exponent);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotCutoff(CTGLLightEnum light, GLfloat cutoff)
		{
			//设置聚光切角
			glLightf(light, GL_SPOT_CUTOFF, cutoff);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotConstant(CTGLLightEnum light, GLfloat constant)
		{
			//设置常量衰减因子
			glLightf(light, GL_CONSTANT_ATTENUATION, constant);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotLinear(CTGLLightEnum light, GLfloat linear)
		{
			//设置线性衰减因子
			glLightf(light, GL_LINEAR_ATTENUATION, linear);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetLightSpotQuadratic(CTGLLightEnum light, GLfloat quadratic)
		{
			//设置二次衰减因子
			glLightf(light, GL_QUADRATIC_ATTENUATION, quadratic);
		}
	}
}

#endif