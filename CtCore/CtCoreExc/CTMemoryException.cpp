#include "stdafx.h"
#include <exception\CTMemoryException.h>

//CTMemoryExceptionBase

CppTools::CTException::CTMemoryException::CTMemoryExceptionBase::CTMemoryExceptionBase()
: CTExceptionBase(300, "cannot access memory", "内存操作错误")
{
}

CppTools::CTException::CTMemoryException::CTMemoryExceptionBase::CTMemoryExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c)
: CTExceptionBase(exc_code, exc_err, exc_err_c)
{
}

//CTNotEnoughMemory

CppTools::CTException::CTMemoryException::CTNotEnoughMemory::CTNotEnoughMemory()
: CTMemoryExceptionBase(301, "not enough memory", "没有足够的内存")
{
}

//CTArrayOutRange

CppTools::CTException::CTMemoryException::CTArrayOutRange::CTArrayOutRange(const CTSize_t position)
: CTMemoryExceptionBase(302, "out of range while accessing a part of array", "数组访问越界,")
{
	addExcString(", position: ");
	addExcString(_CT_STR ::NtoS(position));
	addExcString_c("位置: ");
	addExcString_c(_CT_STR ::NtoS(position));
}

CppTools::CTException::CTMemoryException::CTArrayOutRange::CTArrayOutRange(const std::string& exc_err_mc)
: CTMemoryExceptionBase(302, "out of range while accessing a part of array", "数组访问越界,")
{
	addExcString_c(exc_err_mc);
}

//CTArrayOutRange CTArrayOutRange1D

CppTools::CTException::CTMemoryException::CTArrayOutRange1D::CTArrayOutRange1D(const CTSize_t error_position)
: CTMemoryExceptionBase(3021, "out of range while accessing a part of 1D-array, position: ", "数组访问越界,当访问第 "), position(error_position)
{
	addExcString(_CT_STR ::NtoS(position));
	addExcString_c(_CT_STR ::NtoS(position));
	addExcString_c(" 个位置时发生访问冲突");
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange1D::getPosition() const
{
	return position;
}

//CTArrayOutRange2D

CppTools::CTException::CTMemoryException::CTArrayOutRange2D::CTArrayOutRange2D(const CTSize_t error_position_x, const CTSize_t error_position_y)
: CTMemoryExceptionBase(3022, "out of range while accessing a part of 2D-array, position: row( ", "数组访问越界,当访问第 "), position_x(error_position_x), position_y(error_position_y)
{
	addExcString(_CT_STR ::NtoS(position_x));
	addExcString(" ), column( ");
	addExcString(_CT_STR ::NtoS(position_y));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(position_x));
	addExcString_c(" 行,第 ");
	addExcString_c(_CT_STR ::NtoS(position_y));
	addExcString_c(" 列时发生访问冲突");
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange2D::getPositionX() const
{
	return position_x;
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange2D::getPositionY() const
{
	return position_y;
}

//CTArrayOutRange3D

CppTools::CTException::CTMemoryException::CTArrayOutRange3D::CTArrayOutRange3D(const CTSize_t error_position_x, const CTSize_t error_position_y, const CTSize_t error_position_z)
: CTMemoryExceptionBase(3023, "out of range while accessing a part of 3D-array, position: row( ", "数组访问越界,当访问第 "), position_x(error_position_x), position_y(error_position_y), position_z(error_position_z)
{
	addExcString(_CT_STR ::NtoS(position_x));
	addExcString(" ), column( ");
	addExcString(_CT_STR ::NtoS(position_y));
	addExcString(" ), depth( ");
	addExcString(_CT_STR ::NtoS(position_z));
	addExcString(" )");
	addExcString_c(_CT_STR ::NtoS(position_x));
	addExcString_c(" 行,第 ");
	addExcString_c(_CT_STR ::NtoS(position_y));
	addExcString_c(" 列,第 ");
	addExcString_c(_CT_STR ::NtoS(position_z));
	addExcString_c(" 纵时发生访问冲突");
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange3D::getPositionX() const
{
	return position_x;
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange3D::getPositionY() const
{
	return position_y;
}

CTSize_t CppTools::CTException::CTMemoryException::CTArrayOutRange3D::getPositionZ() const
{
	return position_z;
}

//CTMemorySizeError

CppTools::CTException::CTMemoryException::CTMemorySizeError::CTMemorySizeError()
: CTMemoryExceptionBase(303, "size of memory applied is error", "申请内存失败, 所申请的内存大小不合适")
{
}