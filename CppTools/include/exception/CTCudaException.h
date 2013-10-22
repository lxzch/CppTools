#pragma once
#ifndef CTCUDAEXCEPTION_H
#define CTCUDAEXCEPTION_H

#include <exception\CTException.h>
#include <core\CTString.h>

namespace CppTools
{
	namespace CTException
	{
		namespace CTCudaException
		{
			class CPPTOOLS_API CTCudaExceptionBase
				: public CTExceptionBase
			{
			public:
				CTCudaExceptionBase(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
				void setErr(CppTools::CTData::CTStr::CTString& errmsg);
				void setFile(CppTools::CTData::CTStr::CTString& filename);
				void setLine(CppTools::CTData::CTStr::CTString& linenum);
				CppTools::CTData::CTStr::CTString getErr() const;
				CppTools::CTData::CTStr::CTString getFile() const;
				int getLine();
				virtual const char* what() const throw();
				virtual const std::string c_what() const throw();

			protected:
				CppTools::CTData::CTStr::CTString err, file, line;
			};

			class CPPTOOLS_API CTCudaErrSetDevice
				: public CTCudaExceptionBase
			{
			public:
				CTCudaErrSetDevice(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};

			class CPPTOOLS_API CTCudaErrMemory
				: public CTCudaExceptionBase
			{
			public:
				CTCudaErrMemory(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};

			class CPPTOOLS_API CTCudaErrMemcpyHost2Device
				: public CTCudaExceptionBase
			{
			public:
				CTCudaErrMemcpyHost2Device(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};

			class CPPTOOLS_API CTCudaErrMemcpyDevice2Host
				: public CTCudaExceptionBase
			{
			public:
				CTCudaErrMemcpyDevice2Host(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};

			class CPPTOOLS_API CTCudaFailPlan
				: public CTCudaExceptionBase
			{
			public:
				CTCudaFailPlan(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};

			class CPPTOOLS_API CTCudaFailExecute
				: public CTCudaExceptionBase
			{
			public:
				CTCudaFailExecute(const CppTools::CTData::CTStr::CTString& err = "错误信息", const CppTools::CTData::CTStr::CTString& file = NO_DEFAULT, const CppTools::CTData::CTStr::CTString& line = "0");
			};
		}
	}
}

#ifndef NO_SIMPLE

typedef CppTools::CTException::CTCudaException::CTCudaExceptionBase			CTCudaExceptionBase;
typedef CppTools::CTException::CTCudaException::CTCudaErrMemory				CTCudaErrMemory;
typedef CppTools::CTException::CTCudaException::CTCudaErrSetDevice			CTCudaErrSetDevice;
typedef CppTools::CTException::CTCudaException::CTCudaErrMemcpyHost2Device	CTCudaErrMemcpyHost2Device;
typedef CppTools::CTException::CTCudaException::CTCudaErrMemcpyDevice2Host	CTCudaErrMemcpyDevice2Host;
typedef CppTools::CTException::CTCudaException::CTCudaFailPlan				CTCudaFailPlan;
typedef CppTools::CTException::CTCudaException::CTCudaFailExecute			CTCudaFailExecute;

#endif

#endif