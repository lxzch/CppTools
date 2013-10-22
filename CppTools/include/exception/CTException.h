#pragma once
#ifndef CTEXCEPTION_H
#define CTEXCEPTION_H

#include <core\CTExcDefine.h>

_CT_EXC_BEGIN

class CPPTOOLS_API CTExceptionBase
	: public std::exception
	//异常总基类 CTE-100
{
public:
	CTExceptionBase();
	~CTExceptionBase();
	inline CTExcCode_t getExcCode() const;
	const char* what() const throw();
	virtual const std::string c_what() const throw();

protected:
	CTExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
	void setExcCode(const CTExcCode_t exc_code);
	void setExcString(const std::string& exc_err = "");
	void setExcString_c(const std::string& exc_err_c = "");
	void addExcString(const std::string& exc_err_m = "");
	void addExcString_c(const std::string& exc_err_cm = "");

private:
	void init();
	void dispose();

private:
	CTExcCode_t _exc_code;
	std::string* _exc_err_c;
	std::string* _exc_err;
};

CTExcCode_t CTExceptionBase::getExcCode() const
{
	return this->_exc_code;
}

_CT_EXC_END

#endif /* CTException.h */