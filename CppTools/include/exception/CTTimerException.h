#pragma once
#ifndef CTTIMEREXCEPTION_H
#define CTTIMEREXCEPTION_H

#include <CTExc>

#define _CT_EXC_TIMER_BEGIN		_CT_EXC_BEGIN namespace CTTimerException {
#define _CT_EXC_TIMER_END		} _CT_EXC_END
#define _CT_EXC_TIMER			_CT_EXC::CTTimerException
#define _CT_EXC_TIMER__			_CT_EXC_TIMER::
#define _USN_CT_EXC_TIMER		_USN( CppTools::CTException::CTTimerException )

_CT_EXC_TIMER_BEGIN

class CPPTOOLS_API CTTimerExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//组件-计时器错误基类 CTE-510
{
public:
	CTTimerExceptionBase();

protected:
	CTTimerExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTTimerErrStart
	: public CTTimerExceptionBase
	//计时器启动失败 CTE-5101
{
public:
	CTTimerErrStart();
};

class CPPTOOLS_API CTTimerErrGetAccracy
	: public CTTimerExceptionBase
	//无法取得系统所能支持的时间精度 CTE-5102
{
public:
	CTTimerErrGetAccracy();
};

class CPPTOOLS_API CTTimerErrNoCallbackFunction
	: public CTTimerExceptionBase
	//没有设置定时器的回调函数 CTE-5103
{
public:
	CTTimerErrNoCallbackFunction();
};

_CT_EXC_TIMER_END

#endif /* CTTimerException.h */