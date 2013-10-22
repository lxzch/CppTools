#pragma once
#ifndef CTSVRCLNTOBJECT_H
#define CTSVRCLNTOBJECT_H

#include <common\CTObject.h>
#include <common\CTCInterface.h>

_CT_DATA_BEGIN

class CPPTOOLS_API CTSvrClntBase
	: public CTObject, public CTCIFSetServer<CTSvrClntBase>, public CTCIFGetServer<CTSvrClntBase>
{
public:
	typedef CTSvrClntBase		SCOBase_t;
	typedef SCOBase_t*			p_SCOBase_t;

public:
	CTSvrClntBase(const p_SCOBase_t sever = NULL);
	~CTSvrClntBase();

public:
	void setServer(const p_SCOBase_t sever = NULL);
	p_SCOBase_t getServer() const;
	bool isServerValid() const;
	void chkServerValid() const;

private:
	p_SCOBase_t server;
};

template <typename Tx>
class CPPTOOLS_TCLASS_API CTSvrSngClient
	: public CTSvrClntBase, public CTCIFSetClient<Tx>, public CTCIFGetClient<Tx>
{
public:
	typedef Tx*					p_Tx;
public:
	CTSvrSngClient(const p_Tx client = NULL, const p_SCOBase_t sever = NULL);
	~CTSvrSngClient();

public:
	inline void setClient(const p_Tx client = NULL);
	inline p_Tx getClient() const;
	inline p_Tx getSafeClient() const;
	inline const p_Tx getConstClient() const;
	inline bool isClientValid() const;
	inline void chkClientValid() const;
	bool operator < (CTSvrSngClient& right);
	bool operator == (CTSvrSngClient& right);
	bool operator () (CTSvrSngClient& in);
	bool operator () (CTSvrSngClient* in);

private:
	p_Tx client;
};

_CT_DATA_END

#include <common\CTSvrClntObject.tpc>

#endif /* CTSvrClntObject.h */