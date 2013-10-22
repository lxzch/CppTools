#pragma once
#ifndef CTPARTITION_H
#define CTPARTITION_H

#include <CTMath>
#include <CTData>
#include <CTMemory>

namespace CppTools
{
	namespace CTAlgorithm
	{
		typedef enum CPPTOOLS_TYPE_API _CTShape
		{
			point = 0,
			points,

			line,
			lines,
			triangle,
			triangles,
			rectangle,
			rectangles,
			square,
			squares,
			circle,
			circles,

			cuboid,  //长方体
			cuboids,
			cube,    //正方体
			cubes,
			ball,
			balls,
		} CTShape;

		void CPPTOOLS_API RectTriPartition(const CppTools::CTData::CTLine1f& x,
										   const CppTools::CTData::CTLine1f& y,
										   const CppTools::CTData::CTSize2i& parts,
										   const CppTools::CTData::CTPoint3f& center,
										   float* vertex);
		void CPPTOOLS_API RectTriPartition(const CppTools::CTData::CTLine1d& x,
										   const CppTools::CTData::CTLine1d& y,
										   const CppTools::CTData::CTSize2i& parts,
										   const CppTools::CTData::CTPoint3d& center,
										   double* vertex);
		void CPPTOOLS_API RectFillZ(float* vertex, const float* z, const int vertex_num, const int offset = 2);
		void CPPTOOLS_API RectFillZ(float* vertex, const float* z, const float z_multiply, const int vertex_num, const int offset = 2);
		void CPPTOOLS_API RectFillZ(float* vertex, float* z, const float z_add, const int vertex_num, const int offset = 2);
		void CPPTOOLS_API RectFillZ(float* vertex, const float* z, const float z_add, float z_multiply, const int vertex_num, const int offset = 2);
		void CPPTOOLS_API RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, unsigned short* indices);
		void CPPTOOLS_API RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, UINT* indices);
		void CPPTOOLS_API RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, int* indices);
		void CPPTOOLS_API RectTriPartCreateVexrtexIndex(const CppTools::CTData::CTSize2i& parts, long* indices);
	}
}

#endif