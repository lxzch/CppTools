#ifndef CTSVRCLNTMOBJECT_H
#define CTSVRCLNTMOBJECT_H

#include <common\CTDefine.h>
#include <common\CTSvrClntObject.h>
#include <list>

_CT_DATA_BEGIN

template <typename Tx>
class CPPTOOLS_TCLASS_API CTSvrMulClient
	: public CTSvrClntBase
{
public:
	typedef Tx*												p_Tx;
	typedef Tx**											pp_Tx;

public:
	typedef CTSvrClntBase									SCOBase_t;
	typedef SCOBase_t*										p_SCOBase_t;

public:
	typedef typename std::list<p_Tx >						lclient_t;
	typedef typename lclient_t::iterator					lclient_it;
	typedef typename lclient_t::const_pointer				lclient_it_c;
	typedef typename lclient_t::reverse_iterator			lcient_it_r;
	typedef typename lclient_t::const_reverse_iterator		lclient_it_rc;

public:
	CTSvrMulClient(const p_SCOBase_t sever = NULL);
	~CTSvrMulClient();

public:
	CTSize_t size() const;
	void setClient(p_Tx client = NULL);
	pp_Tx getClient();
	void clear();
	void renew();
	void erase(const CTSize_t position);
	void erase(const p_Tx e_obj);
	bool isClientValid() const;
	void dispose();

private:
	void init();
	void refreshPointer();
	void refresh();

private:
	CTSize_t c_maxnum;
	CTSize_t num;
	pp_Tx client;
	std::list<p_Tx >* list_client;
};

template <typename Tx>
class CPPTOOLS_TCLASS_API CTSvrMulClient<CppTools::CTData::CTSvrSngClient<Tx> >
	: public CTSvrClntBase
{
public:
	typedef Tx*												p_Tx;
	typedef Tx**											pp_Tx;

public:
	typedef CTSvrClntBase									SCOBase_t;
	typedef SCOBase_t*										p_SCOBase_t;

protected:
	typedef typename CppTools::CTData::CTSvrSngClient<Tx>	SSC_t;
	typedef SSC_t*											p_SSC_t;

public:
	typedef typename std::list<p_SSC_t >					lclient_t;
	typedef typename lclient_t::iterator					lclient_it;
	typedef typename lclient_t::const_pointer				lclient_it_c;
	typedef typename lclient_t::reverse_iterator			lcient_it_r;
	typedef typename lclient_t::const_reverse_iterator		lclient_it_rc;

public:
	CTSvrMulClient(const p_SCOBase_t sever = NULL);
	~CTSvrMulClient();

public:
	CTSize_t size() const;
	void setClient(p_Tx client = NULL);
	pp_Tx getClient();
	void clear();
	void renew();
	void erase(const CTSize_t position);
	void erase(const p_Tx e_obj);
	bool isClientValid() const;
	void dispose();

private:
	void init();
	void refreshPointer();
	void refresh();

private:
	CTSize_t c_maxnum;
	CTSize_t num;
	pp_Tx client;
	std::list<p_SSC_t >* list_client;
};

_CT_DATA_END

#include <common\CTSvrClntMObject.tpc>

#endif