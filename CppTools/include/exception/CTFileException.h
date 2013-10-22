#pragma once
#ifndef CTFILEEXCEPTION_H
#define CTFILEEXCEPTION_H

#include <CTExc>

#define _CT_EXC_FILE_BEGIN		_CT_EXC_BEGIN namespace CTFileException {
#define _CT_EXC_FILE_END		} _CT_EXC_END
#define _CT_EXC_FILE			_CT_EXC::CTFileException
#define _CT_EXC_FILE__			_CT_EXC_FILE::
#define _USN_CT_EXC_FILE		_USN( CppTools::CTException::CTFileException );

_CT_EXC_FILE_BEGIN

class CPPTOOLS_API CTFileExceptionBase
	: public CppTools::CTException::CTExceptionBase
	//文件读写错误基类，可以保存一个文件名 CTE-410
{
public:
	CTFileExceptionBase(const std::string& file = NO_DEFAULT);
	std::string getFileName() const;

protected:
	CTFileExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err = "", const std::string& exc_err_c = "", const std::string& file = NO_DEFAULT);
	void setFileName(const std::string& file);
	void init();

private:
	std::string filename;
};

class CPPTOOLS_API CTFileNoName
	: public CTFileExceptionBase
	//没有文件名，适用于open()之前 CTE-4101
{
public:
	CTFileNoName();
};

class CPPTOOLS_API CTFileNotFound
	: public CTFileExceptionBase
	//文件不存在，适用于open()之后 CTE-4102
{
public:
	CTFileNotFound(const std::string& file = NO_DEFAULT);
};

class CPPTOOLS_API CTFileIOBad
	: public CTFileExceptionBase
	//文件读写失败，适用于bad()时，bad检查只读打开但写入，或者写入设备没有足够空间 CTE-4103
{
public:
	CTFileIOBad(const std::string& file = NO_DEFAULT);
};

class CPPTOOLS_API CTFileIOFail
	: public CTFileExceptionBase
{
	//文件格式错误，适用于fail()时，fail检查需要int但读入char之类 CTE-4104
public:
	CTFileIOFail(const std::string& file = NO_DEFAULT);
};

_CT_EXC_FILE_END

#endif /* CTFileException.h */