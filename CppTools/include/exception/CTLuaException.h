#pragma once
#ifndef CTLUAEXCEPTION_H
#define CTLUAEXCEPTION_H

#include "CTException.h"

namespace CppTools
{
	namespace CTException
	{
		namespace CTLuaException
		{
			class CPPTOOLS_API CTLuaExceptionBase
				: public CTExceptionBase
			{
			public:
				CTLuaExceptionBase(const std::string lua_error = NO_DEFAULT)
					: lua_error(lua_error)
				{
				}

				~CTLuaExceptionBase()
				{
				}

				virtual const char* what() const throw()
				{
					return "Error: while operating a lua file";
				}

				virtual const std::string c_what() const throw()
				{
					std::string msg;
					msg = "发生错误: Lua脚本文件操作失败\n失败信息: ";
					msg += lua_error;
					return msg;
				}

			protected:
				std::string lua_error;
			};

			class CPPTOOLS_API CTLuaNotReadyException
				: public CTLuaExceptionBase
			{
			public:
				CTLuaNotReadyException(const std::string lua_error = "Lua对象没有初始化")
					: CTLuaExceptionBase(lua_error)
				{
				}

				virtual const char* what() const throw()
				{
					return "Error: Lua object not ready";
				}

				virtual const std::string c_what() const throw()
				{
					std::string msg;
					msg = "发生错误: ";
					msg += lua_error;
					return msg;
				}
			};

			class CPPTOOLS_API CTLuaNotFoundException
				: public CTLuaExceptionBase
			{
			public:
				CTLuaNotFoundException(const std::string lua_error_file = NO_DEFAULT)
					: CTLuaExceptionBase(lua_error_file)
				{
				}

				virtual const char* what() const throw()
				{
					return "Error: while opening a lua file";
				}

				virtual const std::string c_what() const throw()
				{
					std::string msg;
					msg = "发生错误: 无法运行Lua脚本文件\n文件名: ";
					msg += lua_error;
					return msg;
				}
			};

			class CPPTOOLS_API CTLuaNotNumberException
				: public CTLuaExceptionBase
			{
			public:
				CTLuaNotNumberException(const std::string lua_error = "当需要一个 数字 的时候, 收到一个 非数字 类型")
					: CTLuaExceptionBase(lua_error)
				{
				}

				virtual const char* what() const throw()
				{
					return "Error: need a number, not a different type";
				}

				virtual const std::string c_what() const throw()
				{
					std::string msg;
					msg = "发生错误: ";
					msg += lua_error;
					return msg;
				}
			};
		}
	}
}

#ifndef NO_SIMPLE

typedef CppTools::CTException::CTLuaException::CTLuaExceptionBase		CTLuaExceptionBase;
typedef CppTools::CTException::CTLuaException::CTLuaNotReadyException	CTLuaNotReadyException;
typedef CppTools::CTException::CTLuaException::CTLuaNotFoundException	CTLuaNotFoundException;
typedef CppTools::CTException::CTLuaException::CTLuaNotNumberException	CTLuaNotNumberException;

#endif

#endif