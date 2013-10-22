#include "stdafx.h"
#include <exception\CTObjectException.h>

//CTObjectException

CppTools::CTException::CTObjectException::CTObjectExceptionBase::CTObjectExceptionBase()
: CTExceptionBase(101, "CTObject received a error", "CTObject �յ�һ������")
{
}

 //--protected
CppTools::CTException::CTObjectException::CTObjectExceptionBase::CTObjectExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTObjecInvalidBase

CppTools::CTException::CTObjectException::CTObjectInvalidBase::CTObjectInvalidBase()
: CTObjectExceptionBase(1010, "CTObject is invalid", "δ�� CTObject�� �Ķ������õ�ʵ��")
{
}

 //--protected
CppTools::CTException::CTObjectException::CTObjectInvalidBase::CTObjectInvalidBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTObjectExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTSeverObjectInvalid

CppTools::CTException::CTObjectException::CTServerObjectInvalid::CTServerObjectInvalid()
: CTObjectInvalidBase(1011, "CTServerObject is invalid", "δ�� CTServerObject�� �Ķ������õ�ʵ��")
{
}

//CTClientObjectInvalid

CppTools::CTException::CTObjectException::CTClientObjectInvalid::CTClientObjectInvalid()
: CTObjectInvalidBase(1012, "CTClientObject is invalid", "δ�� CTClientObject�� �Ķ������õ�ʵ��")
{
}

//CTObjectNotSole

CppTools::CTException::CTObjectException::CTObjectNotSole::CTObjectNotSole()
: CTObjectExceptionBase(102, "CTObject is not sole", "CTObject�� ����ֻ����һ��ʵ��")
{
}