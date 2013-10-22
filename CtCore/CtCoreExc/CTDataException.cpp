#include "stdafx.h"
#include <exception\CTDataException.h>

//CTDataExceptionBase

CppTools::CTException::CTDataException::CTDataExceptionBase::CTDataExceptionBase()
: CTExceptionBase(200, "bad data", "���ݴ���")
{
}

 //--protected
CppTools::CTException::CTDataException::CTDataExceptionBase::CTDataExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTDataNotANumber

CppTools::CTException::CTDataException::CTDataNotANumber::CTDataNotANumber()
: CTDataExceptionBase(201, "data is not a number", "���ڴ�������ݲ���һ������")
{
}

//CTDataTypeExceptionBase

CppTools::CTException::CTDataException::CTDataTypeExceptionBase::CTDataTypeExceptionBase(const std::string& need_type)
: CTDataExceptionBase(202, "while operating data [ ", "��������: ���ݲ���ʧ��,�ڴ��� [ "), need(need_type)
{
	addExcString(need);
	addExcString(" ]");
	addExcString_c(need);
	addExcString_c(" ] ʱ��������");
}

 //--protected
CppTools::CTException::CTDataException::CTDataTypeExceptionBase::CTDataTypeExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c, const std::string& need_type)
: CTDataExceptionBase(exc_code, exc_err, exc_err_c), need(need_type)
{
}

void CppTools::CTException::CTDataException::CTDataTypeExceptionBase::setNeed(const std::string& need_type)
{
	need = need_type;
}

std::string CppTools::CTException::CTDataException::CTDataTypeExceptionBase::getNeed() const
{
	return need;
}

//CTDataTypeNotMatch

CppTools::CTException::CTDataException::CTDataTypeNotMatch::CTDataTypeNotMatch(const std::string& need_type, const std::string& given_type)
					: CTDataTypeExceptionBase(2021, "type is not match, need [ ", "�������Ͳ�ƥ��,��Ҫ [ ", need_type), given(given_type)
{
	addExcString(getNeed());
	addExcString(" ], but get [ ");
	addExcString(given);
	addExcString(" ]");
	addExcString_c(getNeed());
	addExcString_c(" ] ����,���õ����� [ ");
	addExcString_c(given);
	addExcString_c(" ] ����");
}

void CppTools::CTException::CTDataException::CTDataTypeNotMatch::setGiven(const std::string& given_type)
{
	given = given_type;
}

std::string CppTools::CTException::CTDataException::CTDataTypeNotMatch::getGiven() const
{
	return given;
}

//CTAngleException

CppTools::CTException::CTDataException::CTAngleException::CTAngleException(CTData_i degree, CTData_i minute, CTData_d second)
: CTDataExceptionBase(210, "bad angle ( ", "�Ƕ� ( "), degree(degree), minute(minute), second(second)
{
	addExcString(_CT_STR ::NtoS(degree));
	addExcString(",");
	addExcString(_CT_STR ::NtoS(minute));
	addExcString(",");
	addExcString(_CT_STR ::NtoS(second));
	addExcString(" )");

	addExcString_c(_CT_STR ::NtoS(degree));
	addExcString_c("��");
	addExcString_c(_CT_STR ::NtoS(minute));
	addExcString_c("��");
	addExcString_c(_CT_STR ::NtoS(second));
	addExcString_c("�� )�����ϳ�ʶ");
}