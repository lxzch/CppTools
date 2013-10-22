#include "stdafx.h"
#include <exception\CTTimerException.h>

//CTTimerExceptionBase

CppTools::CTException::CTTimerException::CTTimerExceptionBase::CTTimerExceptionBase()
: CTExceptionBase(510, "while running a timer", "使用计时器发生异常")
{
}

 //--protected
CppTools::CTException::CTTimerException::CTTimerExceptionBase::CTTimerExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTTimerErrStart

CppTools::CTException::CTTimerException::CTTimerErrStart::CTTimerErrStart()
: CTTimerExceptionBase(5101, "while starting a timer", "启动计时器失败")
{
}

//CTTimerErrGetAccracy

CppTools::CTException::CTTimerException::CTTimerErrGetAccracy::CTTimerErrGetAccracy()
: CTTimerExceptionBase(5102, "cannot get the timer accracy of this system", "无法取得系统所能支持的时间精度")
{
}

//CTTimerErrNoCallbackFunction

CppTools::CTException::CTTimerException::CTTimerErrNoCallbackFunction::CTTimerErrNoCallbackFunction()
: CTTimerExceptionBase(5103, "one timer one callback function", "没有设置定时器的回调函数")
{
}