#pragma once
#ifndef CTCUDAFFT_H
#define CTCUDAFFT_H

#include <CTCuda>
#include <cufft.h>

namespace CppTools
{
	namespace CTCuda
	{
		CPPTOOLS_INLINEFUNC_API inline void cdaFFTPlan1d_c2c(cufftHandle* plan, const int size)
		{
			cufftResult err = cufftPlan1d(plan, size, CUFFT_C2C, 1);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailPlan(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cdaFFT1d_c2c(cufftHandle plan, __ct_in cufftComplex* in, __ct_out cufftComplex* out)
		{
			cufftResult err = cufftExecC2C(plan, in, out, CUFFT_FORWARD);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailExecute(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cdaIFFT1d_c2c(cufftHandle plan, __ct_in cufftComplex* in, __ct_out cufftComplex* out)
		{
			cufftResult err = cufftExecC2C(plan, in, out, CUFFT_INVERSE);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailExecute(err, __FILE__, (int)__LINE__);
		}
	}
}

#endif