#pragma once
#ifndef CTOBJECTEXCEPTION_H
#define CTOBJECTEXCEPTION_H

#include <CTExc>

#define _CT_EXC_OBJECT_BEGIN	_CT_EXC_BEGIN namespace CTObjectException {
#define _CT_EXC_OBJECT_END		} _CT_EXC_END
#define _CT_EXC_OBJECT			_CT_EXC::CTObjectException
#define _CT_EXC_OBJECT__		_CT_EXC_OBJECT::
#define _USN_CT_EXC_OBJECT		_USN( CppTools::CTException::CTObjectException )

_CT_EXC_OBJECT_BEGIN

class CPPTOOLS_API CTObjectExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//CTObject异常基类 CTE-101
{
public:
	CTObjectExceptionBase();

protected:
	CTObjectExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTObjectInvalidBase
	: public CTObjectExceptionBase
	//对象无效基类 CTE-1010
{
public:
	CTObjectInvalidBase();

protected:
	CTObjectInvalidBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTServerObjectInvalid
	: public CTObjectInvalidBase
	//服务对象无效 CTE-1011
{
public:
	CTServerObjectInvalid();
};

class CPPTOOLS_API CTClientObjectInvalid
	: public CTObjectInvalidBase
	//客户对象无效 CTE-1012
{
public:
	CTClientObjectInvalid();
};

class CPPTOOLS_API CTObjectNotSole
	: public CTObjectExceptionBase
	//对象不是唯一的 CTE-102
{
public:
	CTObjectNotSole();
};

_CT_EXC_OBJECT_END

#endif /* CTObjectException.h */