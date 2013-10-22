#pragma once
#ifndef CTMEMORY2D_H
#define CTMEMORY2D_H

#include <common\CTSvrClntMObject.h>

_CT_MEMORY_BEGIN

template <typename Tx>
class CTMemory1d;

template <typename Tx>
class CPPTOOLS_TCLASS_API CTMemory2d
	: private CppTools::CTData::CTSvrMulClient<CppTools::CTMemory::CTMemory1d<Tx> >,
	public CTCIFDispose,
	public CTCIFSize<CTSize_t>
{
public:
	typedef CppTools::CTData::CTSvrMulClient<CppTools::CTMemory::CTMemory1d<Tx> >	SCOBase_t;

private:
	typedef CTMemory1d<Tx>															Mem1d_t;
	typedef Mem1d_t*																p_Mem1d_t;

public:
	CTMemory2d();
	CTMemory2d(const CTSize_t size_x, const CTSize_t size_y);
	CTMemory2d(const CTSize_t size_x, const CTSize_t size_y, const Tx default_value);
	~CTMemory2d();

public:
	void create(const CTSize_t size_x, const CTSize_t size_y);
	void create(const CTSize_t size_x, const CTSize_t size_y, const Tx default_value);
	void dispose();
	bool isValid() const;

	CTSize_t size() const;
	inline Tx** original_data() const;
	inline Tx** safe_data() const;
	inline const Tx** const_data() const;

	Mem1d_t& operator [](const CTSize_t index);
	const Mem1d_t& operator [](const CTSize_t index) const;

private:
	using SCOBase_t::isClientValid;
	using SCOBase_t::getClient;
	using SCOBase_t::setClient;
	//using SCOBase_t::getSafeClient;
	//using SCOBase_t::getConstClient;

private:
	CTSize_t size_x, size_y;
};

_CT_MEMORY_END

#include <core\CTMemory2d.tpc>
#include <core\CTMemory1d.h>

#ifndef NO_SIMPLE

typedef CppTools::CTMemory::CTMemory2d<int>				CTMem2di;
typedef CppTools::CTMemory::CTMemory2d<CTSize_t>		CTMem2dst;
typedef CppTools::CTMemory::CTMemory2d<char>			CTMem2dc;
typedef CppTools::CTMemory::CTMemory2d<UCHAR>			CTMem2duc;
typedef CppTools::CTMemory::CTMemory2d<long>			CTMem2dl;
typedef CppTools::CTMemory::CTMemory2d<ULONG>			CTMem2dul;
typedef CppTools::CTMemory::CTMemory2d<float>			CTMem2df;
typedef CppTools::CTMemory::CTMemory2d<double>			CTMem2dd;
typedef CppTools::CTMemory::CTMemory2d<std::string>		CTMem2ds;

#endif /* NO_SIMPLE */

#endif /* CTMemory2d.h */