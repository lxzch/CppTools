#include "stdafx.h"
#include <exception\CTObjectException.h>

//CTObjectException

CppTools::CTException::CTObjectException::CTObjectExceptionBase::CTObjectExceptionBase()
: CTExceptionBase(101, "CTObject received a error", "CTObject 收到一个错误")
{
}

 //--protected
CppTools::CTException::CTObjectException::CTObjectExceptionBase::CTObjectExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTObjecInvalidBase

CppTools::CTException::CTObjectException::CTObjectInvalidBase::CTObjectInvalidBase()
: CTObjectExceptionBase(1010, "CTObject is invalid", "未将 CTObject类 的对象引用到实例")
{
}

 //--protected
CppTools::CTException::CTObjectException::CTObjectInvalidBase::CTObjectInvalidBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTObjectExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTSeverObjectInvalid

CppTools::CTException::CTObjectException::CTServerObjectInvalid::CTServerObjectInvalid()
: CTObjectInvalidBase(1011, "CTServerObject is invalid", "未将 CTServerObject类 的对象引用到实例")
{
}

//CTClientObjectInvalid

CppTools::CTException::CTObjectException::CTClientObjectInvalid::CTClientObjectInvalid()
: CTObjectInvalidBase(1012, "CTClientObject is invalid", "未将 CTClientObject类 的对象引用到实例")
{
}

//CTObjectNotSole

CppTools::CTException::CTObjectException::CTObjectNotSole::CTObjectNotSole()
: CTObjectExceptionBase(102, "CTObject is not sole", "CTObject类 有且只能有一个实例")
{
}