#include "stdafx.h"
#include <gl\CTGLSL.h>

std::string CppTools::CTGL::GLSL::ReadGlslFile(const std::string& filename)
{
	std::ifstream fin;
	std::string line, filetext;
	if(filename.empty())
		throw CppTools::CTException::CTFileException::CTFileNoName();
	fin.open(filename.c_str());
	if(!fin)
		throw CppTools::CTException::CTFileException::CTFileNotFound(filename);

	while(fin.good())
	{
		std::getline(fin, line);
		filetext.append(line + "\n");
	}	
	fin.close();
	return filetext;
}

CppTools::CTGL::CTGLSLhandle CppTools::CTGL::GLSL::RegGlsl(const std::string& glsl_context, const GLenum type)
{
	GLuint shader, program;
	GLint compiled, linked;
	shader = glCreateShader(type);
	const GLchar* shader_source = glsl_context.c_str();
	const GLint shader_length = (GLint)glsl_context.size();
	glShaderSource(shader, 1, &shader_source, &shader_length);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if(!compiled)
		throw CppTools::CTException::CTGLException::CTGLSLComplieException(shader);
	program = glCreateProgram();
	glAttachShader(program, shader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if(!linked)
		throw CppTools::CTException::CTGLException::CTGLSLLinkException(program);
	return CTGLSLhandle(shader, program);
}

CppTools::CTGL::CTGLSLhandle CppTools::CTGL::GLSL::ReadGlsl(const std::string& filename, const GLenum type)
{
	return RegGlsl(ReadGlslFile(filename), type);
}