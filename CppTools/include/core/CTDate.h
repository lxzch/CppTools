#pragma once

#ifndef CTDATE_H
#define CTDATE_H

#include <CTBase>
#include <exception\CTDateException.h>

namespace CppTools
{
	namespace CTDate
	{
		typedef enum CPPTOOLS_TYPE_API _CTDateStateEnum
		{
			equal = 0,
			before,
			after,
		} CTDateStateEnum;		

		//判断日期是否符合常识
		CPPTOOLS_API
			bool CheckDate(const CTDate_i year,
				const CTDate_i month,
				const CTDate_i day);

		//判断时间是否符合常识
		CPPTOOLS_API
			bool CheckTime(const CTDate_i hour,
				const CTDate_i minute,
				const CTDate_i second);
		CPPTOOLS_API
			bool CheckTime(const CTDate_i hour,
				const CTDate_i minute,
				const float second);
		CPPTOOLS_API
			bool CheckTime(const CTDate_i hour,
				const CTDate_i minute,
				const double second);

		struct CPPTOOLS_TYPE_API CTDate_t
		{
			CTDate_t(const CTDate_i year = 2000,
				const CTDate_i month = 1,
				const CTDate_i day = 1)
				: year(year), month(month), day(day)
			{
				CheckDate(year,
					month,
					day);
			}
			CTDate_i year,
				month,
				day;
		};

		template <typename Tx>
		struct CPPTOOLS_TYPE_API CTTime_t
		{
			CTTime_t(const CTDate_i hour,
				const CTDate_i minute,
				const Tx second)
				: hour(hour), minute(minute), second(second)
			{
				CheckTime(hour,
					minute,
					second);
			}
			CTDate_i hour,
				minute;
			Tx second;
		};

		typedef CTTime_t<CTDate_i>				CTTime_ti;
		typedef CTTime_t<float>					CTTime_tf;
		typedef CTTime_t<double>				CTTime_td;
			
		CPPTOOLS_INLINEFUNC_API inline
			bool CheckDate(const CTDate_t& date)
		{
			return CheckDate(date.year,
				date.month,
				date.day);
		}

		template <typename Tx>
		CPPTOOLS_INLINE_TFUNC_API inline
			bool CheckTime(const CTTime_t<Tx>& time)
		{
			return CheckTime(time.hour,
				time.minute,
				time.second);
		}

		//判断闰年
		CPPTOOLS_API
			bool IsLeapYear(const CTDate_i year);

		//年份大小比较
		CPPTOOLS_API
			CTDateStateEnum YearCompare(const CTDate_i year_1,
				const CTDate_i year_2);

		//月份大小比较
		CPPTOOLS_API
			CTDateStateEnum MonthCompare(const CTDate_i month_1,
				const CTDate_i year_2);

		//日子大小比较
		CPPTOOLS_API
			CTDateStateEnum DayCompare(const CTDate_i day_1,
				const CTDate_i day_2);

		//日期前后比较
		CPPTOOLS_API
			CTDateStateEnum DateCompare(const CTDate_i year_1,
				const CTDate_i month_1,
				const CTDate_i day_1,
				const CTDate_i year_2,
				const CTDate_i month_2,
				const CTDate_i day_2);
		CPPTOOLS_INLINEFUNC_API inline
			CTDateStateEnum DateCompare(const CTDate_t& date_1, const CTDate_t& date_2)
		{
			return DateCompare(date_1.year, date_1.month, date_1.day,
								 date_2.year, date_2.month, date_2.day);
		}

		//返回日期是一年第几天
		CPPTOOLS_API
			CTDate_i DayInYear(const CTDate_i year,
				const CTDate_i month,
				const CTDate_i day);
		CPPTOOLS_INLINEFUNC_API inline
			CTDate_i DayInYear(const CTDate_t& date)
		{
			return DayInYear(date.year,
				date.month,
				date.day);
		}

		//返回两个日期相差多少天
		CPPTOOLS_API
			CTDate_i DaySubDay(const CTDate_i year_1,
				const CTDate_i month_1,
				const CTDate_i day_1,
				const CTDate_i year_2,
				const CTDate_i month_2,
				const CTDate_i day_2);
		CPPTOOLS_INLINEFUNC_API inline
			CTDate_i DaySubDay(const CTDate_t& date_1,
				const CTDate_t& date_2)
		{
			return DaySubDay(date_1.year, date_1.month, date_1.day,
				date_2.year, date_2.month, date_2.day);
		}

		//返回日期是星期几
		CPPTOOLS_API
			CTDate_i Week(const CTDate_i year,
				const CTDate_i month,
				const CTDate_i day);
		CPPTOOLS_INLINEFUNC_API inline
			CTDate_i Week(const CTDate_t& date)
		{
			return Week(date.year,
				date.month,
				date.day);
		}

		//返回日期是第几周
		CPPTOOLS_API
			CTDate_i WeekInYear(const CTDate_i year,
				const CTDate_i month,
				const CTDate_i day);
		CPPTOOLS_INLINEFUNC_API inline
			CTDate_i WeekInYear(CTDate_t& date)
		{
			return WeekInYear(date.year,
				date.month,
				date.day);
		}
	}
}

#endif