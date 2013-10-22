#include "stdafx.h"
#include <exception\CTTimerException.h>

//CTTimerExceptionBase

CppTools::CTException::CTTimerException::CTTimerExceptionBase::CTTimerExceptionBase()
: CTExceptionBase(510, "while running a timer", "ʹ�ü�ʱ�������쳣")
{
}

 //--protected
CppTools::CTException::CTTimerException::CTTimerExceptionBase::CTTimerExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTTimerErrStart

CppTools::CTException::CTTimerException::CTTimerErrStart::CTTimerErrStart()
: CTTimerExceptionBase(5101, "while starting a timer", "������ʱ��ʧ��")
{
}

//CTTimerErrGetAccracy

CppTools::CTException::CTTimerException::CTTimerErrGetAccracy::CTTimerErrGetAccracy()
: CTTimerExceptionBase(5102, "cannot get the timer accracy of this system", "�޷�ȡ��ϵͳ����֧�ֵ�ʱ�侫��")
{
}

//CTTimerErrNoCallbackFunction

CppTools::CTException::CTTimerException::CTTimerErrNoCallbackFunction::CTTimerErrNoCallbackFunction()
: CTTimerExceptionBase(5103, "one timer one callback function", "û�����ö�ʱ���Ļص�����")
{
}