#include "stdafx.h"
#include <common\CTCntObject.h>

//CTCountableObject

int CppTools::CTData::CTCountableObject::_count;

CppTools::CTData::CTCountableObject::CTCountableObject()
{
	++_count;
}

CppTools::CTData::CTCountableObject::~CTCountableObject()
{
	--_count;
}

int CppTools::CTData::CTCountableObject::getCount()
{
	return _count;
}

//CTSoleObject

CppTools::CTData::CTSoleObject::CTSoleObject()
{
	if(getCount() > 1)
	{
		throw CppTools::CTException::CTObjectException::CTObjectNotSole();
	}
}
