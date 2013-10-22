#pragma once
#ifndef CTDATAEXCEPTION_H
#define CTDATAEXCEPTION_H

#include <CTExc>

#define _CT_EXC_DATA_BEGIN		_CT_EXC_BEGIN namespace CTDataException {
#define _CT_EXC_DATA_END		} _CT_EXC_END
#define _CT_EXC_DATA			_CT_EXC::CTDataException
#define _CT_EXC_DATA__			_CT_EXC_DATA::
#define _USN_CT_EXC_DATA		_USN( CppTools::CTException::CTDataException )

_CT_EXC_DATA_BEGIN

class CPPTOOLS_API CTDataExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//数据异常基类 CTE-200
{
public:
	CTDataExceptionBase();

protected:
	CTDataExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTDataNotANumber
	: public CTDataExceptionBase
	//数据不是一个数字，NaN异常 CTE-201
{
public:
	CTDataNotANumber();
};

class CPPTOOLS_API CTDataTypeExceptionBase
	: public CTDataExceptionBase
	//数据类型异常基类 CTE-202
{
public:
	CTDataTypeExceptionBase(const std::string& need_type = NO_DEFAULT);
	std::string getNeed() const;

protected:
	CTDataTypeExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "", const std::string& need_type = NO_DEFAULT);
	void setNeed(const std::string& need_type);

private:
	std::string need;
};

class CPPTOOLS_API CTDataTypeNotMatch
	: public CTDataTypeExceptionBase
	//输入与所需数据类型不匹配 CTE-2021
{
public:
	CTDataTypeNotMatch(const std::string& need_type = NO_DEFAULT, const std::string& given_type = NO_DEFAULT);
	std::string getGiven() const;

protected:
	void setGiven(const std::string& given_type);

private:
	std::string given;
};

class CPPTOOLS_API CTAngleException
	: public CTDataExceptionBase
	//角度异常类 CTE-210
{
public:
	CTAngleException(CTData_i degree, CTData_i minute, CTData_d second);

protected:
	CTData_i degree, minute;
	CTData_d second;
};

_CT_EXC_DATA_END

#endif /* CTDataException.h */