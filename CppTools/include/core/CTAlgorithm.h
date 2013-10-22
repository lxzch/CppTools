#pragma once
#ifndef CTALGORITHM_H
#define CTALGORITHM_H

#include <CTData>
#include <CTMath>
#include <CTMemory>

namespace CppTools
{
	namespace CTAlgorithm
	{
		//寻找最大最小值
		template <typename Tx>
		CppTools::CTData::CTMaxMin<Tx> FindMaxMin(const Tx* data, const CTSize_t num);
		template <typename Tx>
		Tx FindMax(const Tx* data, const CTSize_t num);
		template <typename Tx>
		Tx FindMin(const Tx* data, const CTSize_t num);

		//归一化数组
		template <typename Tx>
		void Uniform(const Tx* data, const CTSize_t num);
		template <typename Tx>
		void Uniform(const Tx* src_data, Tx* des_data, const CTSize_t num, const CTSize_t des_repeat = 1);
	}
}

#include <core\CTAlgorithm.tpc>

#endif