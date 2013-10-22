#ifndef CTCSTRING_H
#define CTCSTRING_H

#include <common\CTUniform.h>
#include <sstream>

_CT_STR_BEGIN

template<typename Tx>
	CPPTOOLS_TFUNC_API std::string NtoS(const Tx& in)
	{
		std::stringstream ss;
		ss << in;
		return ss.str();
	}	//������ת�����ַ���

template<typename Tx>
	CPPTOOLS_TFUNC_API Tx StoN(const std::string& in)
	{
		std::stringstream ss;
		Tx res;
		ss << in;
		ss >> res;
		return res;
	}	//���ַ���ת��������

_CT_STR_END

#endif