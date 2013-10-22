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
	}	//将数字转换成字符串

template<typename Tx>
	CPPTOOLS_TFUNC_API Tx StoN(const std::string& in)
	{
		std::stringstream ss;
		Tx res;
		ss << in;
		ss >> res;
		return res;
	}	//将字符串转换成数字

_CT_STR_END

#endif