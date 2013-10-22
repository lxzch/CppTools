#pragma once

#ifndef CTGLMATERIAL_H
#define CTGLMATERIAL_H

#include <CTGLEW>

namespace CppTools
{
	namespace CTGL
	{
		CPPTOOLS_INLINEFUNC_API inline void Cullon()
		{
			glEnable(GL_CULL_FACE);
		}

		CPPTOOLS_INLINEFUNC_API inline void Culloff()
		{
			glDisable(GL_CULL_FACE);
		}

		CPPTOOLS_INLINEFUNC_API inline void UseFace(CTGLFaceEnum face)
		{
			glCullFace(face);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialAmbient(CTGLFaceEnum face, GLfloat* color)
		{
			glMaterialfv(face, GL_AMBIENT, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialDiffuse(CTGLFaceEnum face, GLfloat* color)
		{
			glMaterialfv(face, GL_DIFFUSE, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialAandD(CTGLFaceEnum face, GLfloat* color)
		{
			glMaterialfv(face, GL_AMBIENT_AND_DIFFUSE, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialSpecular(CTGLFaceEnum face, GLfloat* color)
		{
			glMaterialfv(face, GL_SPECULAR, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialShininess(CTGLFaceEnum face, GLfloat shininess)
		{
			glMaterialf(face, GL_SHININESS, shininess);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialEmission(CTGLFaceEnum face, GLfloat* color)
		{
			glMaterialfv(face, GL_EMISSION, color);
		}

		CPPTOOLS_INLINEFUNC_API inline void SetMaterialEmission(CTGLFaceEnum face, GLint* color)
		{
			glMaterialiv(face, GL_COLOR_INDEXES, color);
		}
	}
}

#endif