#pragma once
#ifndef CTLUA_H
#define CTLUA_H

#include "lua.hpp"
#include <string>
#include <map>

#include <exception\CTLuaException.h>

#ifdef _DEBUG
#pragma comment(lib, "ctcored.lib")
#endif

#ifdef NDEBUG
#pragma comment(lib, "ctcore.lib")
#endif

#pragma comment(lib, "lua51.lib")
#pragma comment(lib, "lua5.1.lib")

typedef lua_State CTLuaState;
typedef int (*p_func_si_lua)(CTLuaState*);
typedef std::map<std::string, p_func_si_lua> CTLuaMap;

namespace CppTools
{
	namespace CTLua
	{
		CPPTOOLS_API CTLuaState* ReadLuaFile(const std::string& filename = "", const bool default_lib = false);
		CPPTOOLS_API void DoLua(const CTLuaMap& LM, const std::string& filename = "", const bool default_lib = false);
		CPPTOOLS_API void RegFunc(const CTLuaMap& LM, CTLuaState* L);
	}
}

#endif