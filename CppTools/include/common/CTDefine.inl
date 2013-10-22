#ifndef CTDEFINE_INL
#define CTDEFINE_INL

#include <common\CTUniform.h>

_CT_BEGIN

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Min(Tx a, Tx b)
	{
		return (a < b) ? a : b;
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Max(Tx a, Tx b)
	{
		return (a > b) ? a : b;
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Abs(Tx a)
	{
		return (a > 0) ? a : -a;
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Pow2(Tx a)
	{
		return a * a;
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Pow3(Tx a)
	{
		return a * a * a;
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline Tx Sig(Tx a)
	{
		return (a == 0) ? (Tx)0 : ((a < 0) ? (Tx)-1 : (Tx)1);
	}

template <typename Tx> CPPTOOLS_API_HOSTDEVICE
	inline void Swap(Tx& a, Tx& b)
	{
		Tx temp = a;
		a = b;
		b = temp;
	}

CPPTOOLS_INLINEFUNC_API
	inline void CmdPause()
	{
		system("pause");
	}

CPPTOOLS_INLINEFUNC_API
	inline void CmdCls()
	{
		system("cls");
	}

CPPTOOLS_INLINEFUNC_API
	inline void Cmd(const std::string& cmd = "")
	{
		if(cmd == "‘›Õ£")
			system("pause");
		else if(cmd == "«Â∆¡")
			system("cls");
		else
			system(cmd.c_str());
	}

template <typename Tx> CPPTOOLS_INLINE_TFUNC_API
	inline Tx* Malloc(size_t number)
	{
		return (Tx*)malloc(number * sizeof(Tx));
	}

template <typename Tx> CPPTOOLS_INLINE_TFUNC_API
	inline void Free(Tx* point)
	{
		free(point);
	}

template<typename Tx> CPPTOOLS_INLINE_TFUNC_API
	inline void DeleteObj(Tx* object)
	{
		delete object;
		object = NULL;
	}

template<typename Tx> CPPTOOLS_INLINE_TFUNC_API
	inline void DeleteObjs(Tx* object)
	{
		delete[] object;
		object = NULL;
	}

_CT_END

#endif