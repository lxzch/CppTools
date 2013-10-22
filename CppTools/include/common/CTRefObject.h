#pragma once
#ifndef CTREFOBJECT_H
#define CTREFOBJECT_H

#include <CTData>
#include <common\CTSvrClntObject.h>

_CT_DATA_BEGIN

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTRefObject
		: public CTSafeObject
	{
	private:
		class _CTRO_Clnt;
		typedef _CTRO_Clnt*				p_CTRO_CLnt;

	public:
		typedef Tx*						p_Tx;

		CTRefObject(const p_Tx ref = NULL);
		CTRefObject(const CTRefObject<Tx>& ref);
		CTRefObject(const CTRefObject<Tx>* ref);
		~CTRefObject();
		CTSize_t getCount() const;
		void setReference(p_Tx ref);
		void setReference(const CTRefObject<Tx>& ref);
		void setReference(const CTRefObject<Tx>* ref);
		p_Tx getReference() const;
		const p_Tx operator ->() const;
		p_Tx operator ->();
		const Tx& operator *() const;
		Tx& operator *();

	protected:
		void init();
		void dispose();

	private:
		p_CTRO_CLnt _roo;
	};

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTRefObject<Tx>::_CTRO_Clnt
		: public CTSafeObject
	{
	public:
		_CTRO_Clnt();
		~_CTRO_Clnt();

	public:
		void init();
		void dispose();

	public:
		CTSvrSngClient<Tx>* _sco;
		CTInt*				_num;
	};

_CT_DATA_END

#include <CTRefObject.tpc>

#endif /* CTRefObject.h */