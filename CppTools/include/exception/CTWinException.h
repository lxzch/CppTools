#pragma once
#ifndef CTWINEXCEPTION_H
#define CTWINEXCEPTION_H

#include <CTExc>

#define _CT_EXC_WINDOWS_BEGIN	_CT_EXC_BEGIN namespace CTWindowsException {
#define _CT_EXC_WINDOWS_END		} _CT_EXC_END
#define _CT_EXC_WINDOWS			_CT_EXC::CTWindowsException
#define _CT_EXC_WINDOWS__		_CT_EXC_WINDOWS::
#define _USN_CT_EXC_WINDOWS		_USN( CppTools::CTException::CTWindowsException )

_CT_EXC_WINDOWS_BEGIN

class CPPTOOLS_API CTWindowsExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//Windows实例运行异常基类 CTE-501
{
public:
	CTWindowsExceptionBase();

protected:
	CTWindowsExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTWinRunError
	: public CTWindowsExceptionBase
	//Windows实例运行异常 CTE-5011
{
public:
	CTWinRunError(const std::string& file = NO_DEFAULT);

private:
	std::string file;
};

class CPPTOOLS_API CTWinOutTime
	: public CTWindowsExceptionBase
	//Windows实例运行超时异常 CTE-5012
{
public:
	CTWinOutTime();
};

_CT_EXC_WINDOWS_END

#endif /* CTWindowsException.h */