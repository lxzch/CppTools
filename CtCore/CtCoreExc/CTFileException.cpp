#include "stdafx.h"
#include <exception\CTFileException.h>

//CTFileExceptionBase

CppTools::CTException::CTFileException::CTFileExceptionBase::CTFileExceptionBase(const std::string& file)
: CTExceptionBase(410, "while operating the file: ", "文件操作失败,文件名: "), filename(file)
{
	init();
}

CppTools::CTException::CTFileException::CTFileExceptionBase::CTFileExceptionBase(const CTExcCode_t exc_code, const std::string& exc_err, const std::string& exc_err_c, const std::string& file)
: CTExceptionBase(exc_code, exc_err, exc_err_c), filename(file)
{
}

void CppTools::CTException::CTFileException::CTFileExceptionBase::init()
{
	addExcString(filename);
	addExcString_c(filename);
}

std::string CppTools::CTException::CTFileException::CTFileExceptionBase::getFileName() const
{
	return filename;
}

void CppTools::CTException::CTFileException::CTFileExceptionBase::setFileName(const std::string& file)
{
	filename = file;
}

//CTFileNoName

CppTools::CTException::CTFileException::CTFileNoName::CTFileNoName()
: CTFileExceptionBase(4101, "file no name", "缺少文件名")
{
}

//CTFileNotFound

CppTools::CTException::CTFileException::CTFileNotFound::CTFileNotFound(const std::string& file)
: CTFileExceptionBase(4102, "file not found: ", "文件未找到,文件名: ", file)
{
	init();
}

//CTFileIOBad

CppTools::CTException::CTFileException::CTFileIOBad::CTFileIOBad(const std::string& file)
: CTFileExceptionBase(4103, "fail while reading or writing: ", "文件读写失败，请确认是否向只读文件写入数据或者设备没有足够的空间,文件名: ", file)
{
	init();
	addExcString(" please check the only-read flag or confirm if there is enough space for this operating");
}

//CTFileIOFail

CppTools::CTException::CTFileException::CTFileIOFail::CTFileIOFail(const std::string& file)
: CTFileExceptionBase(4104, "bad type while reading or writing:", "文件读写错误，请确认读写数据类型,文件名: ", file)
{
	init();
}