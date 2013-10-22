#include "stdafx.h"
#include <common\CTSvrClntObject.h>

CppTools::CTData::CTSvrClntBase::CTSvrClntBase(const p_SCOBase_t server)
: server(server)
{
}

CppTools::CTData::CTSvrClntBase::~CTSvrClntBase()
{
	this->server = NULL;
}

void CppTools::CTData::CTSvrClntBase::setServer(const p_SCOBase_t server)
{
	this->server = server;
}

CppTools::CTData::CTSvrClntBase::p_SCOBase_t CppTools::CTData::CTSvrClntBase::getServer() const
{
	return server;
}

bool CppTools::CTData::CTSvrClntBase::isServerValid() const
{
	if(server)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CppTools::CTData::CTSvrClntBase::chkServerValid() const
{
	if(!isServerValid())
	{
		throw CppTools::CTException::CTObjectException::CTServerObjectInvalid();
	}
}