#include "stdafx.h"
#include <exception\CTException.h>

//CTException

CppTools::CTException::CTExceptionBase::CTExceptionBase()
: _exc_code(100), _exc_err(NULL), _exc_err_c(NULL)
{
	init();
	*_exc_err += _CT_STR ::NtoS(_exc_code);
	*_exc_err_c += _CT_STR ::NtoS(_exc_code);
	*_exc_err += " ): CppTools received an error";
	*_exc_err_c += " ): CppTools 收到一个错误";

}

 //--protected
CppTools::CTException::CTExceptionBase::CTExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: _exc_code(exc_code), _exc_err(NULL), _exc_err_c(NULL)
{
	init();
	*_exc_err += _CT_STR ::NtoS(_exc_code);
	*_exc_err_c += _CT_STR ::NtoS(_exc_code);
	*_exc_err += " ): ";
	*_exc_err_c += " ): ";
	*_exc_err += exc_err;
	*_exc_err_c += exc_err_c;
}

CppTools::CTException::CTExceptionBase::~CTExceptionBase()
{
	dispose();
}

void CppTools::CTException::CTExceptionBase::init()
{
	_exc_err = new std::string("Error ( CTE-");
	_exc_err_c = new std::string("发生错误 ( CTE-");
}

void CppTools::CTException::CTExceptionBase::dispose()
{
	delete _exc_err;
	_exc_err = NULL;
	delete _exc_err_c;
	_exc_err_c = NULL;
}

void CppTools::CTException::CTExceptionBase::setExcCode(const CTExcCode_t exc_code)
{
	_exc_code = exc_code;
}

void CppTools::CTException::CTExceptionBase::setExcString(const std::string& exc_err)
{
	(*_exc_err) = exc_err;
}

void CppTools::CTException::CTExceptionBase::setExcString_c(const std::string& exc_err_c)
{
	(*_exc_err_c) = exc_err_c;
}

void CppTools::CTException::CTExceptionBase::addExcString(const std::string& exc_err_m)
{
	(*_exc_err) += exc_err_m;
}

void CppTools::CTException::CTExceptionBase::addExcString_c(const std::string& exc_err_cm)
{
	(*_exc_err_c) += exc_err_cm;
}

const char* CppTools::CTException::CTExceptionBase::what() const throw()
{
	return _exc_err->c_str();
}

const std::string CppTools::CTException::CTExceptionBase::c_what() const throw()
{	
	return (*_exc_err_c);
}