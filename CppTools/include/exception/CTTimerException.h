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
	//���-��ʱ��������� CTE-510
{
public:
	CTTimerExceptionBase();

protected:
	CTTimerExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTTimerErrStart
	: public CTTimerExceptionBase
	//��ʱ������ʧ�� CTE-5101
{
public:
	CTTimerErrStart();
};

class CPPTOOLS_API CTTimerErrGetAccracy
	: public CTTimerExceptionBase
	//�޷�ȡ��ϵͳ����֧�ֵ�ʱ�侫�� CTE-5102
{
public:
	CTTimerErrGetAccracy();
};

class CPPTOOLS_API CTTimerErrNoCallbackFunction
	: public CTTimerExceptionBase
	//û�����ö�ʱ���Ļص����� CTE-5103
{
public:
	CTTimerErrNoCallbackFunction();
};

_CT_EXC_TIMER_END

#endif /* CTTimerException.h */