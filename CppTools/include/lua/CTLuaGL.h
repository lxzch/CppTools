#pragma once

#ifndef CTLUAGL_H
#define CTLUAGL_H

#include <gl\CTGL.h>
#include <lua\CTLua.h>

#ifdef _DEBUG
#pragma comment(lib, "ctluad.lib")
#pragma comment(lib, "ctgld.lib")
#endif

#ifdef NDEBUG
#pragma comment(lib, "ctlua.lib")
#pragma comment(lib, "ctgl.lib")
#endif

namespace CppTools
{
	namespace CTLuaGL
	{
		CPPTOOLS_API void InitLuaGL(CTLuaState* L);

		static int lglBegin(CTLuaState* L);
		static int lglClear(CTLuaState* L);
		static int lglClearColor(CTLuaState* L);
		static int lglClearDepth(CTLuaState* L);
		static int lglColor3f(CTLuaState* L);
		static int lglColor4f(CTLuaState* L);
		static int lglColor3d(CTLuaState* L);
		static int lglColor4d(CTLuaState* L);
		static int lglEnd(CTLuaState* L);
		static int lglFlush(CTLuaState* L);
		static int lglVertex3f(CTLuaState* L);
		static int lglVertex4f(CTLuaState* L);
		static int lglVertex3d(CTLuaState* L);
		static int lglVertex4d(CTLuaState* L);
		static int lglBegin(CTLuaState* L);
		static int lglBegin(CTLuaState* L);
		static int lglBegin(CTLuaState* L);
	}
}

#endif