#include "stdafx.h"
#include <exception\CTWinException.h>

//CTWindowsException

CppTools::CTException::CTWindowsException::CTWindowsExceptionBase::CTWindowsExceptionBase()
: CTExceptionBase(501, "when run a windows instance", "在运行一个windows实例时发生异常")
{
}

 //--protected
CppTools::CTException::CTWindowsException::CTWindowsExceptionBase::CTWindowsExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTWinRunError
CppTools::CTException::CTWindowsException::CTWinRunError::CTWinRunError(const std::string& file)
: CTWindowsExceptionBase(5011, "when run the windows instance: ", "在运行一个windows实例时发生异常,进程名: "), file(file)
{
}

//CTWinOutTime

CppTools::CTException::CTWindowsException::CTWinOutTime::CTWinOutTime()
: CTWindowsExceptionBase(5011, "out of time when run a windows instance", "在运行一个windows实例时超时")
{
}