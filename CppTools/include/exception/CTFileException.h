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
	//�ļ���д������࣬���Ա���һ���ļ��� CTE-410
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
	//û���ļ�����������open()֮ǰ CTE-4101
{
public:
	CTFileNoName();
};

class CPPTOOLS_API CTFileNotFound
	: public CTFileExceptionBase
	//�ļ������ڣ�������open()֮�� CTE-4102
{
public:
	CTFileNotFound(const std::string& file = NO_DEFAULT);
};

class CPPTOOLS_API CTFileIOBad
	: public CTFileExceptionBase
	//�ļ���дʧ�ܣ�������bad()ʱ��bad���ֻ���򿪵�д�룬����д���豸û���㹻�ռ� CTE-4103
{
public:
	CTFileIOBad(const std::string& file = NO_DEFAULT);
};

class CPPTOOLS_API CTFileIOFail
	: public CTFileExceptionBase
{
	//�ļ���ʽ����������fail()ʱ��fail�����Ҫint������char֮�� CTE-4104
public:
	CTFileIOFail(const std::string& file = NO_DEFAULT);
};

_CT_EXC_FILE_END

#endif /* CTFileException.h */