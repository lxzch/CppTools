#include "stdafx.h"
#include <CTAlgorithm>
#include "CTCoreTemplateFunc.h"

void CppTools::CTAlgorithm::RectTriPartition(const CppTools::CTData::CTLine1f& x,
										     const CppTools::CTData::CTLine1f& y,
											 const CppTools::CTData::CTSize2i& parts,
											 const CppTools::CTData::CTPoint3f& center,
											 float* vertex)
{
	TFunc_RectPartition(x, y, parts, center, vertex);
}

void CppTools::CTAlgorithm::RectTriPartition(const CppTools::CTData::CTLine1d& x,
											 const CppTools::CTData::CTLine1d& y,
											 const CppTools::CTData::CTSize2i& parts,
											 const CppTools::CTData::CTPoint3d& center,
											 double* vertex)
{
	TFunc_RectPartition(x, y, parts, center, vertex);
}

void CppTools::CTAlgorithm::RectFillZ(float* vertex, const float* z, const int vertex_num, const int offset)
{
	for(int i = 0; i < vertex_num; ++i)
		vertex[i * 3 + offset] = z[i];
}

void CppTools::CTAlgorithm::RectFillZ(float* vertex, const float* z, const float z_multiply, const int vertex_num, const int offset)
{
	for(int i = 0; i < vertex_num; ++i)
		vertex[i * 3 + offset] = z[i]  * z_multiply;
}

void CppTools::CTAlgorithm::RectFillZ(float* vertex, float* z, const float z_add, const int vertex_num, const int offset)
{
	for(int i = 0; i < vertex_num; ++i)
		vertex[i * 3 + offset] = z[i] + z_add;
}

void CppTools::CTAlgorithm::RectFillZ(float* vertex, const float* z, const float z_add, float z_multiply, const int vertex_num, const int offset)
{
	for(int i = 0; i < vertex_num; ++i)
		vertex[i * 3 + offset] = z[i] * z_multiply + z_add;
}

void CppTools::CTAlgorithm::RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, unsigned short* indices)
{
	TFunc_RectTriPartCreateVexrtexIndex(parts, indices);
}

void CppTools::CTAlgorithm::RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, UINT* indices)
{
	TFunc_RectTriPartCreateVexrtexIndex(parts, indices);
}

void CppTools::CTAlgorithm::RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, int* indices)
{
	TFunc_RectTriPartCreateVexrtexIndex(parts, indices);
}

void CppTools::CTAlgorithm::RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, long* indices)
{
	TFunc_RectTriPartCreateVexrtexIndex(parts, indices);
}