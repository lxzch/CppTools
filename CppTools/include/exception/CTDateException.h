#pragma once
#ifndef CTDATEEXCEPTION_H
#define CTDATEEXCEPTION_H

#include <CTExc>

#define _CT_EXC_DATE_BEGIN		_CT_EXC_BEGIN namespace CTDateException {
#define _CT_EXC_DATE_END		} _CT_EXC_END
#define _CT_EXC_DATE			_CT_EXC::CTDateException
#define _CT_EXC_DATE__			_CT_EXC_DATE::
#define _USN_CT_EXC_DATE		_USN( CppTools::CTException::CTDateException )

_CT_EXC_DATE_BEGIN

class CPPTOOLS_API CTDateExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//日期异常基类 CTE-900
{
public:
	CTDateExceptionBase();

protected:
	CTDateExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTDateErrException
	: public CTDateExceptionBase
	//日期异常类 CTE-901
{
public:
	CTDateErrException(const CTDate_i year, const CTDate_i month, const CTDate_i day);
	CTDate_i getYear() const;
	CTDate_i getMonth() const;
	CTDate_i getDay() const;

protected:
	void setDate(const CTDate_i year, const CTDate_i month, const CTDate_i day);

private:
	CTDate_i _year, _month, _day;
};

class CPPTOOLS_API CTYearErrException
	: public CTDateExceptionBase
	//年份异常类 CTE-902
{
public:
	CTYearErrException(const CTDate_i year);
	CTDate_i getYear() const;

protected:	
	void setYear(const CTDate_i year);

private:
	CTDate_i _year;
};

class CPPTOOLS_API CTMonthErrException
	: public CTDateExceptionBase
	//月份异常类 CTE-903
{
public:
	CTMonthErrException(const CTDate_i month);
	CTDate_i getMonth() const;

protected:
	void setMonth(const CTDate_i month);

private:
	CTDate_i _month;
};

class CPPTOOLS_API CTDayErrException
	: public CTDateExceptionBase
	//日异常类 CTE-904
{
public:
	CTDayErrException(const CTDate_i day);
	CTDate_i getDay() const;

protected:
	void setDay(const CTDate_i day);

private:
	CTDate_i _day;
};

class CPPTOOLS_API CTTimeErrException
	: public CTDateExceptionBase
	//时间异常类 CTE-905
{
public:
	CTTimeErrException(const CTDate_i hour, const CTDate_i minute, const CTDate_d second);
	CTDate_i getHour() const;
	CTDate_i getMinute() const;
	double getSecond() const;

protected:
	void setTime(const CTDate_i hour, const CTDate_i minute, const CTDate_d second);

private:
	CTDate_i _hour, _minute;
	CTDate_d _second;
};

_CT_EXC_DATE_END

#endif /* CTDataException.h */