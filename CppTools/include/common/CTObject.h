#pragma once
#ifndef CTOBJECT_H
#define CTOBJECT_H

#include <common\cpptools.h>
#include <common\CTUniform.h>
#include <exception\CTObjectException.h>

_CT_DATA_BEGIN

class CPPTOOLS_API CTObject
{
public:
	CTObject();
	virtual ~CTObject();

public:
	bool isValid() const;
	void chkValid();

private:
	bool _exist;
};

_CT_DATA_END

#endif /* CTObject.h */