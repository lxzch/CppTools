#pragma once
#ifndef CTMEMORY1D_H
#define CTMEMORY1D_H

#include <CTSCO>

_CT_MEMORY_BEGIN

template<typename Tx>
class CPPTOOLS_TCLASS_API CTMemory1d
	: private CppTools::CTData::CTSvrSngClient<Tx>,
	public CTCIFDispose,
	public CTCIFSize<CTSize_t>
{
public:
	typedef CppTools::CTData::CTSvrSngClient<Tx>	SCOBase_t;

public:
	CTMemory1d();
	CTMemory1d(const CTSize_t size);
	CTMemory1d(const CTSize_t size, const Tx default_value);
	~CTMemory1d();

public:
	void create(const CTSize_t size);
	void create(const CTSize_t size, const Tx default_value);
	void dispose();
	bool isValid() const;

	CTSize_t size() const;
	inline Tx* original_data() const;
	inline Tx* safe_data() const;
	inline const Tx* const_data() const;

	Tx& operator [](const CTSize_t index);
	const Tx& operator [](const CTSize_t index) const;

private:
	using SCOBase_t::isClientValid;
	using SCOBase_t::getClient;
	using SCOBase_t::getSafeClient;
	using SCOBase_t::getConstClient;

private:
	CTSize_t _size;
};

_CT_MEMORY_END

#include <core\CTMemory1d.tpc>

#ifndef NO_SIMPLE

typedef CppTools::CTMemory::CTMemory1d<int>				CTMem1di;
typedef CppTools::CTMemory::CTMemory1d<CTSize_t>		CTMem1dst;
typedef CppTools::CTMemory::CTMemory1d<char>			CTMem1dc;
typedef CppTools::CTMemory::CTMemory1d<UCHAR>			CTMem1duc;
typedef CppTools::CTMemory::CTMemory1d<long>			CTMem1dl;
typedef CppTools::CTMemory::CTMemory1d<ULONG>			CTMem1dul;
typedef CppTools::CTMemory::CTMemory1d<float>			CTMem1df;
typedef CppTools::CTMemory::CTMemory1d<double>			CTMem1dd;
typedef CppTools::CTMemory::CTMemory1d<std::string>		CTMem1ds;

#endif /* NO_SIMPLE */

#endif /* CTMemory1d.h */