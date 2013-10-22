#pragma once
#ifndef CTCUDA_H
#define CTCUDA_H

#include <cufft.h>
#include <math_constants.h>
#include <cutil_inline.h>
#include <exception\CTCudaException.h>

typedef float2 Complex;

namespace CppTools
{
	namespace CTCuda
	{
		extern "C"
		{
			static inline __host__ __device__ Complex ctcuAdd(Complex* first, Complex* second)
			{
				return make_float2(first->x + second->x, first->y + second->y);
			}

			static inline __host__ __device__ Complex ctcuMultiply(Complex* first, Complex* second)
			{
				return make_float2(first->x * second->x - first->y * second->y, first->x * second->y + first->y * second->x);
			}

			static inline __host__ __device__ Complex ctcuMultiplyf(Complex* first, float second)
			{
				return make_float2(first->x * second, first->y * second);
			}
		}

		CPPTOOLS_INLINEFUNC_API inline void cuInit()
		{
			cudaError_t err = cudaSetDevice(cutGetMaxGflopsDeviceId());
			if (err != CUDA_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaErrSetDevice(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuMalloc(void** devPtr, size_t size)
		{
			cudaError_t err = cudaMalloc(devPtr, size);
			if (err != CUDA_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaErrMemory(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuSend(void* dst, const void* src, size_t size)
		{
			cudaError_t err = cudaMemcpy(dst, src, size, cudaMemcpyHostToDevice);
			if (err != CUDA_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaErrMemcpyHost2Device(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuGet(void* dst, const void* src, size_t size)
		{
			cudaError_t err = cudaMemcpy(dst, src, size, cudaMemcpyDeviceToHost);
			if (err != CUDA_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaErrMemcpyDevice2Host(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuFFTPlan1d_c2c(cufftHandle* plan, int size)
		{
			cufftResult err = cufftPlan1d(plan, size, CUFFT_C2C, 1);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailPlan(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuFFT1d_c2c(cufftHandle plan, cufftComplex* in, cufftComplex* out)
		{
			cufftResult err = cufftExecC2C(plan, in, out, CUFFT_FORWARD);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailExecute(err, __FILE__, (int)__LINE__);
		}

		CPPTOOLS_INLINEFUNC_API inline void cuIFFT1d_c2c(cufftHandle plan, cufftComplex* in, cufftComplex* out)
		{
			cufftResult err = cufftExecC2C(plan, in, out, CUFFT_INVERSE);
			if (err != CUFFT_SUCCESS)
				throw CppTools::CTException::CTCudaException::CTCudaFailExecute(err, __FILE__, (int)__LINE__);
		}
	}
}

#endif