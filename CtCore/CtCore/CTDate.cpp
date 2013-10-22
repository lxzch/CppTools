#include "stdafx.h"
#include <CTDate>

static int days_total_month[12] = 
{
	31, 59, 90, 120, 151, 181,
	212, 243, 273, 304, 334, 365
};

bool CppTools::CTDate::CheckDate(int year, int month, int day)
{
	if((!year)
		|| (month > 12 || month < 0)
		|| (day < 1))
		throw CppTools::CTException::CTDateException::CTDateErrException(year, month, day);
	else
	{
		if(month == 1 ||
		   month == 3 ||
		   month == 5 ||
		   month == 7 ||
		   month == 8 ||
		   month == 10 ||
		   month == 12)
		{
			if(day > 31)
				throw CppTools::CTException::CTDateException::CTDateErrException(year, month, day);
		}
		else if(month == 2)
		{
			if(IsLeapYear(year))
			{
				if(day > 29)
					throw CppTools::CTException::CTDateException::CTDateErrException(year, month, day);
			}
			else
			{
				if(day > 28)
					throw CppTools::CTException::CTDateException::CTDateErrException(year, month, day);
			}
		}
		else
		{
			if(day > 30)
				throw CppTools::CTException::CTDateException::CTDateErrException(year, month, day);
		}
	}
	return true;
}

bool CppTools::CTDate::CheckTime(int hour, int minute, int second)
{
	if((hour < 0 || hour > 23)
		|| (minute < 0 || minute > 59)
		|| (second < 0 || second > 59))
		throw CppTools::CTException::CTDateException::CTTimeErrException(hour, minute, second);
	return true;
}

bool CppTools::CTDate::CheckTime(int hour, int minute, float second)
{
	if((hour < 0 || hour > 23)
		|| (minute < 0 || minute > 59)
		|| (second < 0.0f || second > 59.0f))
		throw CppTools::CTException::CTDateException::CTTimeErrException(hour, minute, second);
	return true;
}

bool CppTools::CTDate::CheckTime(int hour, int minute, double second)
{
	if((hour < 0 || hour > 23)
		|| (minute < 0 || minute > 59)
		|| (second < 0.0 || second > 59.0))
		throw CppTools::CTException::CTDateException::CTTimeErrException(hour, minute, second);
	return true;
}

bool CppTools::CTDate::IsLeapYear(int year)
{
	if(!year)
		throw CppTools::CTException::CTDateException::CTYearErrException(year);
	if(!(year % 4) && (year % 100) || !(year % 400))
		return true;
	return false;
}

CppTools::CTDate::CTDateStateEnum CppTools::CTDate::YearCompare(int year_1, int year_2)
{
	if(!year_1)
		throw CppTools::CTException::CTDateException::CTYearErrException(year_1);
	if(!year_2)
		throw CppTools::CTException::CTDateException::CTYearErrException(year_2);
	if(year_2 > year_1)
		return after;
	else if(year_2 < year_1)
		return before;
	else
		return equal;
}

CppTools::CTDate::CTDateStateEnum CppTools::CTDate::MonthCompare(int month_1, int month_2)
{
	if(!month_1)
		throw CppTools::CTException::CTDateException::CTMonthErrException(month_1);
	if(!month_2)
		throw CppTools::CTException::CTDateException::CTMonthErrException(month_2);
	if(month_2 > month_1)
		return after;
	else if(month_2 < month_1)
		return before;
	else
		return equal;
}

CppTools::CTDate::CTDateStateEnum CppTools::CTDate::DayCompare(int day_1, int day_2)
{
	if(!day_1)
		throw CppTools::CTException::CTDateException::CTDayErrException(day_1);
	if(!day_2)
		throw CppTools::CTException::CTDateException::CTDayErrException(day_2);
	if(day_2 > day_1)
		return after;
	else if(day_2 < day_1)
		return before;
	else
		return equal;
}

CppTools::CTDate::CTDateStateEnum CppTools::CTDate::DateCompare(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2)
{
	CheckDate(year_1, month_1, day_1);
	CheckDate(year_2, month_2, day_2);
	if(year_2 > year_1)
		return after;
	else if(year_2 < year_1)
		return before;
	else
	{
		if(month_2 > month_1)
			return after;
		else if(month_2 < month_1)
			return before;
		else
		{
			if(day_2 > day_1)
				return after;
			else if(day_2 < day_1)
				return before;
			else
				return equal;
		}
	}
}

int CppTools::CTDate::DayInYear(int year, int month, int day)
{
	CheckDate(year, month, day);
	int days = days_total_month[month];	
	if(month > 2 && IsLeapYear(year))
		++days;
	return days;
}

int CppTools::CTDate::DaySubDay(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2)
{
	int i, leap_year = 0, days;
	int year_min, month_min, day_min, year_max, month_max, day_max;
	int days_min, days_max;
	if(DateCompare(year_1, month_1, day_1, year_2, month_2, day_2) == after)
	{
		year_min = year_1;
		month_min = month_1; 
		day_min = day_1;
		year_max = year_2;
		month_max = month_2;
		day_max = day_2;		
	}
	else
	{		
		year_min = year_2;
		month_min = month_2;
		day_min = day_2;
		year_max = year_1;
		month_max = month_1;
		day_max = day_1;
	}
	days_max = DayInYear(year_max, month_max, day_max);
	days_min = DayInYear(year_min, month_min, day_min);
	for(i = year_min; i < year_max; ++i)
		if(IsLeapYear(i))
			++leap_year;
	if(year_min < 0)
		++year_min;
	if(year_max < 0)
		++year_max;
	days = (year_max - year_min) * 365 + leap_year + days_max - days_min;
	return days;
}

int CppTools::CTDate::Week(int year, int month, int day)
{
	if(DateCompare(year, month, day, 2012, 1, 2) == after)
		return (7 - (DaySubDay(year, month, day, 2012, 1, 2) - 1) % 7);
	else
		return (DaySubDay(year, month, day, 2012, 1, 2) % 7 + 1);
}

int CppTools::CTDate::WeekInYear(int year, int month, int day)
{
	int year_1_1 = Week(year, 1, 1);
	int days = DayInYear(year, month, day);
	return ((days + year_1_1 + 5) / 7);
}