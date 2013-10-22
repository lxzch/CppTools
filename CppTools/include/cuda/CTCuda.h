#pragma once
#ifndef CTCUDA_H
#define CTCUDA_H

#include <CTBase>
#include <math_constants.h>
#include <cutil_inline.h>
#include <exception\CTCudaException.h>

#define __cuda_host_data__
#define __cuda_device_data__
#define __cuda_host_fuction__
#define __cuda_device_fuction__

#define __cda_hdata	__cuda_host_data__
#define __cda_ddata	__cuda_device_data__
#define __cda_hfun	__cuda_host_fuction__
#define __cda_dfun	__cuda_device_fuction__

typedef float2 Complex;

#define cda_host2h		cudaMemcpyHostToHost
#define cda_host2d		cudaMemcpyHostToDevice
#define cda_device2h	cudaMemcpyDeviceToHost
#define cda_device2d	cudaMemcpyDeviceToDevice
#define cda_sysdef		cudaMemcpyDefault
#define cda_noaction	(-1)

namespace CppTools
{
	namespace CTCuda
	{
		template <typename Tx>
		class CPPTOOLS_TCLASS_API CTCudaAct
			: public CTNoInherit<CTCudaAct<Tx> >
		{
		public:
			typedef Tx		_Tx;
			typedef Tx*		p_Tx;
			typedef Tx**	pp_Tx;

			static const int sz_Tx = sizeof(Tx);
			static inline void init();			
			static inline void malloc(void**, const size_t size);
			static inline Tx* malloc(const size_t number);
			static inline void free(Tx* devPtr);
			static inline void send(__cda_hdata void* dst, __cda_ddata const void* src, const size_t size);
			static inline void send(const size_t number, __cda_hdata Tx* dst, __cda_ddata const Tx* src);
			static inline void get(__cda_ddata void* dst, __cda_hdata const void* src, const size_t size);
			static inline void get(const size_t number, __cda_ddata void* dst, __cda_hdata const void* src);
		};

		typedef CTCudaAct<float>	CTCdaf;
		typedef CTCudaAct<GLfloat>	CTCdagf;
		typedef CTCudaAct<double>	CTCdad;
		typedef CTCudaAct<GLdouble>	CTCdagd;
	}
}

#include <cuda\CTCuda.tpc>

#endif