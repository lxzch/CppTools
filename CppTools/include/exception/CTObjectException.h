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
	//CTObject�쳣���� CTE-101
{
public:
	CTObjectExceptionBase();

protected:
	CTObjectExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTObjectInvalidBase
	: public CTObjectExceptionBase
	//������Ч���� CTE-1010
{
public:
	CTObjectInvalidBase();

protected:
	CTObjectInvalidBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTServerObjectInvalid
	: public CTObjectInvalidBase
	//���������Ч CTE-1011
{
public:
	CTServerObjectInvalid();
};

class CPPTOOLS_API CTClientObjectInvalid
	: public CTObjectInvalidBase
	//�ͻ�������Ч CTE-1012
{
public:
	CTClientObjectInvalid();
};

class CPPTOOLS_API CTObjectNotSole
	: public CTObjectExceptionBase
	//������Ψһ�� CTE-102
{
public:
	CTObjectNotSole();
};

_CT_EXC_OBJECT_END

#endif /* CTObjectException.h */