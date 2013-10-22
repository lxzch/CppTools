#ifndef CTROMEMORY_H
#define CTROMEMORY_H

#include <common\CTRefObject.h>
#include <core\CTMemory1d.h>

_CT_DATA_BEGIN

template <typename Tx>
	std::ostream& operator <<(std::ostream& oin,
		const CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<Tx> > obj);

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTRefObject<CppTools::CTMemory::CTMemory1d<Tx> >
		: public CTSafeObject,
		protected CTCIFInit,
		protected CTCIFDispose,
		public CTCIFSize<CTSize_t>
	{
	private:
		class _CTRO_Clnt;
		typedef _CTRO_Clnt*							p_CTRO_CLnt;
	public:
		typedef CppTools::CTMemory::CTMemory1d<Tx>	_Mem1d;
		typedef _Mem1d*								p_Mem1d;
		typedef Tx*									p_Tx;

	public:
		CTRefObject(const p_Mem1d ref = NULL);
		CTRefObject(const CTRefObject<_Mem1d>& ref);
		CTRefObject(const CTRefObject<_Mem1d>* ref);
		~CTRefObject();

	public:
		CTSize_t size() const;
		void setReference(p_Mem1d ref);
		void setReference(const CTRefObject<_Mem1d>& ref);
		void setReference(const CTRefObject<_Mem1d>* ref);
		p_Mem1d getReference() const;
		const p_Mem1d operator ->() const;
		p_Mem1d operator ->();
		const _Mem1d& operator *() const;
		_Mem1d& operator *();
		Tx& operator [](const CTSize_t index);
		const Tx& operator [](const CTSize_t index) const;
		friend std::ostream& operator << <>(std::ostream& oin, const CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<Tx> > obj);

	protected:
		void init();
		void dispose();

	protected:
		p_CTRO_CLnt _roo;
	};

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTRefObject<CppTools::CTMemory::CTMemory1d<Tx> >::_CTRO_Clnt
		: public CTSafeObject,
		public CTCIFInit,
		public CTCIFDispose
	{
	public:
		typedef typename CTRefObject<CppTools::CTMemory::CTMemory1d<Tx> >::_Mem1d	_Mem1d;
	public:	
		_CTRO_Clnt();
		~_CTRO_Clnt();

	public:
		void init();
		void dispose();

	public:
		CTSvrSngClient<_Mem1d>* _sco;
		CTInt*					_num;
	};

_CT_DATA_END

#include <core\CTROMemory.tpc>

#ifndef NO_SIMPLE

typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<int> >				CTROMem1di;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<UINT> >			CTROMem1dui;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<char> >			CTROMem1dc;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<UCHAR> >			CTROMem1duc;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<long> >			CTROMem1dl;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<ULONG> >			CTROMem1dul;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<float> >			CTROMem1df;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<double> >			CTROMem1dd;
typedef CppTools::CTData::CTRefObject<CppTools::CTMemory::CTMemory1d<std::string> >		CTROMem1ds;

#endif /* NO_SIMPLE */

#endif /* CTROMemory.h */