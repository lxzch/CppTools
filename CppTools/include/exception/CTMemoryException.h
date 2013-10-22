#pragma once
#ifndef CTMEMORYEXCEPTION_H
#define CTMEMORYEXCEPTION_H

#include <CTExc>

#define _CT_EXC_MEMORY_BEGIN	_CT_EXC_BEGIN namespace CTMemoryException {
#define _CT_EXC_MEMORY_END		} _CT_EXC_END
#define _CT_EXC_MEMORY			_CT_EXC::CTMemoryException
#define _CT_EXC_MEMORY__		_CT_EXC_MEMORY::
#define _USN_CT_EXC_MEMORY		_USN( CppTools::CTException::CTMemoryException )

_CT_EXC_MEMORY_BEGIN

class CPPTOOLS_API CTMemoryExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//内存异常基类 CTE-300
{
public:
	CTMemoryExceptionBase();

protected:
	CTMemoryExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "");
};

class CPPTOOLS_API CTNotEnoughMemory
	: public CTMemoryExceptionBase
	//申请内存失败异常 CTE-301
{
public:
	CTNotEnoughMemory();
};

class CPPTOOLS_API CTArrayOutRange
	: public CTMemoryExceptionBase
	//数组访问越界 CTE-302
{
public:
	CTArrayOutRange(const CTSize_t position);
	CTArrayOutRange(const std::string& exc_err_mc = NO_DEFAULT);
};

class CPPTOOLS_API CTArrayOutRange1D
	: public CTMemoryExceptionBase
	//1维数组访问越界异常 CTE-3021
{
public:	
	CTArrayOutRange1D(const CTSize_t error_position = 0);

public:
	CTSize_t getPosition() const;

private:
	CTSize_t position;
};

class CPPTOOLS_API CTArrayOutRange2D
	: public CTMemoryExceptionBase
	//2维数组访问越界异常 CTE-3022
{
public:
	CTArrayOutRange2D(const CTSize_t error_position_x = 0, const CTSize_t error_position_y = 0);

public:
	CTSize_t getPositionX() const;
	CTSize_t getPositionY() const;

private:
	CTSize_t position_x, position_y;
};

class CPPTOOLS_API CTArrayOutRange3D
	: public CTMemoryExceptionBase
	//3维数组访问越界异常 CTE-3023
{
public:
	CTArrayOutRange3D(const CTSize_t error_position_x = 0, const CTSize_t error_position_y = 0, const CTSize_t error_position_z = 0);

public:
	CTSize_t getPositionX() const;
	CTSize_t getPositionY() const;
	CTSize_t getPositionZ() const;

private:
	CTSize_t position_x, position_y, position_z;
};



class CPPTOOLS_API CTMemorySizeError
	: public CTMemoryExceptionBase
	//数组大小不正确 CTE-303
{
public:
	CTMemorySizeError();
};

_CT_EXC_MEMORY_END	

#endif /* CTMemoryException.h */