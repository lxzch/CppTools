#include "stdafx.h"
#include <common\CTObject.h>

//CTObject

CppTools::CTData::CTObject::CTObject()
: _exist(true)
{
}

CppTools::CTData::CTObject::~CTObject()
{
	_exist = false;
}

bool CppTools::CTData::CTObject::isValid() const
{
	return _exist;
}

void CppTools::CTData::CTObject::chkValid()
{
	if(!isValid())
	{
		throw CppTools::CTException::CTObjectException::CTObjectInvalidBase();
	}
}