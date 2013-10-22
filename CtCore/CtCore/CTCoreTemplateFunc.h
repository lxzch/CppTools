#pragma once
#ifndef CTCORETEMPLATEFUNC_H
#define CTCORETEMPLATEFUNC_H

#include <CTBase>

_CT_ALGORITHM_BEGIN

template<typename Tx,
	typename Ty>
	void TFunc_RectPartition(const CppTools::CTData::CTLine1<Tx>& x,
		const CppTools::CTData::CTLine1<Tx>& y,
		const CppTools::CTData::CTSize2<Ty>& parts,
		const CppTools::CTData::CTPoint3<Tx>& center,
		Tx* vertex)
	{
		if(!vertex)
			throw CppTools::CTException::CTMemoryException::CTMemoryExceptionBase();
		Ty i, j;
		int pos = 0;
		Tx ty;
		Tx dx = (x.end - x.start) / parts.width;
		Tx dy = (y.end - y.start) / parts.height;
		for(j = 0; j <= parts.height; ++j)
		{
			ty = y.start + (Tx)j * dy;
			for(i = 0; i <= parts.width; ++i)
			{
				vertex[pos++] = center.x + x.start + (Tx)i * dx;
				vertex[pos++] = center.y + ty;
				vertex[pos++] = center.z;
			}
		}
	}

template<typename Tx,
	typename Ty>
	void TFunc_RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2<Tx>& parts,
		Ty* indices)
	{
		if(!indices)
			throw CppTools::CTException::CTMemoryException::CTMemoryExceptionBase();
		Tx i, j;
		int pos = 0;
		CppTools::CTData::CTSize2<Tx> vertexes;
		vertexes.width = parts.width + 1;
		vertexes.height = parts.height + 1;
		for(j = 0; j < parts.height; ++j)
		{
			for(i = 0; i < parts.width; ++i)
			{
				indices[pos++] = (Ty)(j * vertexes.width + i);
				indices[pos++] = (Ty)((j + 1) * vertexes.width + i);
				indices[pos++] = (Ty)((j + 1) * vertexes.width + i + 1);
				indices[pos++] = (Ty)(j * vertexes.width + i);
				indices[pos++] = (Ty)((j + 1) * vertexes.width + i + 1);
				indices[pos++] = (Ty)(j * vertexes.width + i + 1);
			}
		}
	}

template<typename Tx,
	typename Ty>
	void TFunc_RectQuadPartCreateVexrtexIndex(const CppTools::CTData::CTSize2<Tx>& parts,
		Ty* indices)
	{
		if(!indices)
			throw CppTools::CTException::CTMemoryException::CTMemoryExceptionBase();
		Tx i, j;
		int pos = 0;
		for(j = 0; j < parts.height; ++j)
		{
			for(i = 0; i < parts.width; ++i)
			{
				indices[pos++] = (Ty)(j * parts.width + i);
				indices[pos++] = (Ty)((j + 1) * parts.width + i);
				indices[pos++] = (Ty)((j + 1) * parts.width + i + 1);
				indices[pos++] = (Ty)(j * parts.width + i + 1);
			}
		}
	}

_CT_ALGORITHM_END

#endif /* CTCoreTemplateFunc.h */