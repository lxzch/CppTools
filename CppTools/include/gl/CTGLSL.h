#pragma once
#ifndef CTGLSL_H
#define CTGLSL_H

#include <CTGLEW>
#include <exception\CTFileException.h>
#include <exception\CTGLException.h>
#include <fstream>
#include <string>
using namespace std;

#define UseGlsl(program) (glUseProgram((GLuint)program))
#define DeleteGlsl(program, shader) (glDetach((GLuint)program, (GLuint)shader))
#define InitGlsl() glewInit()

namespace CppTools
{
	namespace CTGL
	{
		typedef struct _CTGLSLhandle
		{
			_CTGLSLhandle(const GLhandleARB shader = 0, const GLhandleARB program = 0)
				: shader(shader), program(program)
			{
			}
			GLuint shader;
			GLuint program;
		} CTGLSLhandle;

		namespace GLSL
		{
			CPPTOOLS_API string ReadGlslFile(const std::string& filename ="");
			CPPTOOLS_API CTGLSLhandle RegGlsl(const std::string& glsl_context, const GLenum type = vertex_shader);
			CPPTOOLS_API CTGLSLhandle ReadGlsl(const std::string& filename ="", const GLenum type = vertex_shader);
		}
	}
}

#endif