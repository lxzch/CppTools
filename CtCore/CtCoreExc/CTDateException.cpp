#include "stdafx.h"
#include <exception\CTDateException.h>

//CTDateExceptionBase

CppTools::CTException::CTDateException::CTDateExceptionBase::CTDateExceptionBase()
: CTExceptionBase(900, "date is bad", "���ڲ���ȷ")
{
}

 //--protected
CppTools::CTException::CTDateException::CTDateExceptionBase::CTDateExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTDateErrException

CppTools::CTException::CTDateException::CTDateErrException::CTDateErrException(const CTDate_i year, const CTDate_i month, const CTDate_i day)
: CTDateExceptionBase(901, "the date is bad ( ", "���ڲ���ȷ: "), _year(year), _month(month), _day(day)
{
	addExcString(_CT_STR ::NtoS(_year));
	addExcString("/");
	addExcString(_CT_STR ::NtoS(_month));
	addExcString("/");
	addExcString(_CT_STR ::NtoS(_day));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(_year));
	addExcString_c("��");
	addExcString_c(_CT_STR ::NtoS(_month));
	addExcString_c("��");
	addExcString_c(_CT_STR ::NtoS(_day));
	addExcString_c("�� �����ϳ�ʶ");
}

CTDate_i CppTools::CTException::CTDateException::CTDateErrException::getYear() const
{
	return _year;
}

CTDate_i CppTools::CTException::CTDateException::CTDateErrException::getMonth() const
{
	return _month;
}

CTDate_i CppTools::CTException::CTDateException::CTDateErrException::getDay() const
{
	return _day;
}

void CppTools::CTException::CTDateException::CTDateErrException::setDate(const CTDate_i year, const CTDate_i month, const CTDate_i day)
{
	_year = year;
	_month = month;
	_day = day;
}

//CTYearErrException

CppTools::CTException::CTDateException::CTYearErrException::CTYearErrException(const CTDate_i year)
: CTDateExceptionBase(902, "the date is bad , especially the year ( ", "���ڲ���ȷ: "), _year(year)
{
	addExcString(_CT_STR ::NtoS(_year));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(_year));
	addExcString_c("�� �����ϳ�ʶ");
}

CTDate_i CppTools::CTException::CTDateException::CTYearErrException::getYear() const
{
	return _year;
}

void CppTools::CTException::CTDateException::CTYearErrException::setYear(const CTDate_i year)
{
	_year = year;
}

//CTMonthErrException

CppTools::CTException::CTDateException::CTMonthErrException::CTMonthErrException(const CTDate_i month)
: CTDateExceptionBase(903, "the date is bad , especially the month ( ", "���ڲ���ȷ: "), _month(month)
{
	addExcString(_CT_STR ::NtoS(_month));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(_month));
	addExcString_c("�� �����ϳ�ʶ");
}

CTDate_i CppTools::CTException::CTDateException::CTMonthErrException::getMonth() const
{
	return _month;
}

void CppTools::CTException::CTDateException::CTMonthErrException::setMonth(const CTDate_i month)
{
	_month = month;
}

//CTDayErrException

CppTools::CTException::CTDateException::CTDayErrException::CTDayErrException(const CTDate_i day)
: CTDateExceptionBase(904, "the date is bad , especially the day ( ", "���ڲ���ȷ: "), _day(day)
{
	addExcString(_CT_STR ::NtoS(_day));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(_day));
	addExcString_c("�� �����ϳ�ʶ");
}

CTDate_i CppTools::CTException::CTDateException::CTDayErrException::getDay() const
{
	return _day;
}

void CppTools::CTException::CTDateException::CTDayErrException::setDay(const CTDate_i day)
{
	_day = day;
}

//CTTimeErrException

CppTools::CTException::CTDateException::CTTimeErrException::CTTimeErrException(const CTDate_i hour, const CTDate_i minute, const double second)
: CTDateExceptionBase(905, "the time is bad ( ", "ʱ�䲻��ȷ: "), _hour(hour), _minute(minute), _second(second)
{
	addExcString(_CT_STR ::NtoS(_hour));
	addExcString(":");
	addExcString(_CT_STR ::NtoS(_minute));
	addExcString(":");
	addExcString(_CT_STR ::NtoS(_second));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(_hour));
	addExcString_c("ʱ");
	addExcString_c(_CT_STR ::NtoS(_minute));
	addExcString_c("��");
	addExcString_c(_CT_STR ::NtoS(_second));
	addExcString_c("�� �����ϳ�ʶ");
}

CTDate_i CppTools::CTException::CTDateException::CTTimeErrException::getHour() const
{
	return _hour;
}

CTDate_i CppTools::CTException::CTDateException::CTTimeErrException::getMinute() const
{
	return _minute;
}

double CppTools::CTException::CTDateException::CTTimeErrException::getSecond() const
{
	return _second;
}

void CppTools::CTException::CTDateException::CTTimeErrException::setTime(const CTDate_i hour, const CTDate_i minute, const double second)
{
	_hour = hour;
	_minute = minute;
	_second = second;
}