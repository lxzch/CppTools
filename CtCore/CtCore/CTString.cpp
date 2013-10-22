#include "stdafx.h"
#include <CTString>

CppTools::CTData::CTStr::CTString::CTString(const std::string& in)
: std::string(in)
{
}

template <typename Tx>
CppTools::CTData::CTStr::CTString::CTString(const CppTools::CTData::CTDataBase<Tx>& in)
: std::string(in.getData())
{
}

CppTools::CTData::CTStr::CTString::CTString(const char* in)
: std::string(in)
{
}

CppTools::CTData::CTStr::CTString::CTString(const char in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::CTString(const UCHAR in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::CTString(const int in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::CTString(const UINT in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::CTString(const long in)
: std::string(NtoS(in))					
{
}

CppTools::CTData::CTStr::CTString::CTString(const ULONG in)
: std::string(NtoS(in))					
{
}

CppTools::CTData::CTStr::CTString::CTString(const float in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::CTString(const double in)
: std::string(NtoS(in))
{
}

CppTools::CTData::CTStr::CTString::~CTString()
{
}

void CppTools::CTData::CTStr::CTString::toUpper()
{
	char* _str = _Myptr();
	for(size_t i = 0; i < _Mysize; ++i)
		if(_str[i] >= 97 && _str[i] <= 122)
			_str[i] -= 32;
}

void CppTools::CTData::CTStr::CTString::toLower()
{
	char* _str = _Myptr();
	for(size_t i = 0; i < _Mysize; ++i)
		if(_str[i] >= 65 && _str[i] <= 90)
			_str[i] += 32;
}

int CppTools::CTData::CTStr::CTString::toInt()
{	
	return StoI(*this);
}

unsigned int CppTools::CTData::CTStr::CTString::toUint()
{
	return StoUI(*this);
}

char CppTools::CTData::CTStr::CTString::toChar()
{	
	return StoC(*this);
}

unsigned char CppTools::CTData::CTStr::CTString::toUchar()
{
	return StoUC(*this);
}

long CppTools::CTData::CTStr::CTString::toLong()
{
	return StoL(*this);
}

unsigned long CppTools::CTData::CTStr::CTString::toUlong()
{
	return StoUL(*this);
}

float CppTools::CTData::CTStr::CTString::toFloat()
{
	return StoF(*this);
}

double CppTools::CTData::CTStr::CTString::toDouble()
{
	return StoD(*this);
}

CppTools::CTData::CTStr::CTString CppTools::CTData::CTStr::CTString::trim()
{
	size_type i, pos_s, pos_e;
	char* _str = _Myptr();
	for (i = 0; i < _Mysize; ++i)
		if (_str[i] != ' ')
			break;
	pos_s = i;

	for (i = _Mysize - 1; i >= 0; --i)
		if (_str[i] != ' ')
			break;
	pos_e = i;
	if(pos_s == 0 && pos_e == _Mysize - 1)
		return *this;
	*this = substr(pos_s, pos_e);
	return *this;
}

stringVector CppTools::CTData::CTStr::CTString::split(const char& separator)
{
	stringVector temp;
	size_type i;
	std::string t;
	char* _str = _Myptr();
	for(i = 0; i <= _Mysize; ++i)
	{
		if(_str[i] == separator)
		{
			if(t.empty())
				continue;
			temp.push_back(t);
			t.erase();
			continue;
		}
		t += _str[i];
	}
	if(!t.empty())
		temp.push_back(t);
	return temp;
}

CppTools::CTData::CTStr::CTString::CTStrVector CppTools::CTData::CTStr::CTString::c_split(const char& separator)
{
	std::vector<CppTools::CTData::CTStr::CTString> temp;
	size_type i;
	std::string t;
	char* _str = _Myptr();
	for(i = 0; i <= _Mysize; ++i)
	{
		if(_str[i] == separator)
		{
			if(t.empty())
				continue;
			temp.push_back(t);
			t.erase();
			continue;
		}
		t += _str[i];
	}
	if(!t.empty())
		temp.push_back(t);
	return temp;
}

//CTStringVector

void CppTools::CTData::CTStr::CTStringVector::readFrom(const std::string& file, bool isClear)
{
	if(isClear)
		clear();
	if(!file.size())
		throw CppTools::CTException::CTFileException::CTFileNoName();
	std::ifstream fin(file.c_str());
	std::string t;
	if(!fin)
		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
	while(std::getline(fin, t))
		push_back(t);
}

void CppTools::CTData::CTStr::CTStringVector::writeTo(const std::string& file, const std::string& seperator, const bool is_endl)
{
	if(!file.size())
		throw CppTools::CTException::CTFileException::CTFileNoName();
	std::ofstream fout(file.c_str());
	if(!fout)
		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
	size_t i;
	for(i = 0; i < size(); ++i)
	{
		fout<<at(i);
		if(i != size() - 1)
			fout<<seperator;
		if(is_endl)
			fout<<std::endl;
	}
	fout.close();
}

void CppTools::CTData::CTStr::CTStringVector::writeTo(std::ofstream& fout, const std::string& seperator, const bool is_endl)
{
	if(!fout)
		throw CppTools::CTException::CTFileException::CTFileNotFound();
	size_t i;
	for(i = 0; i < size(); ++i)
	{
		fout<<at(i);
		if(i != size() - 1)
			fout<<seperator;
		if(is_endl)
			fout<<std::endl;
	}
}

void CppTools::CTData::CTStr::CTStringVector::writeTo(std::ofstream& fout, const std::vector<int>& seperator, const bool is_endl)
{
	if(!fout)
		throw CppTools::CTException::CTFileException::CTFileNotFound();
	size_t i;
	CTIosSpace(fout, seperator[0]);
	for(i = 0; i < size(); ++i)
	{
		fout<<at(i);
		if((i != size() - 1) && ((i + 1) < seperator.size()))
			CTIosSpace(fout, seperator[i + 1]);
		if(is_endl)
			fout<<std::endl;
	}
}

void CppTools::CTData::CTStr::CTStringVector::eraseAt(size_t position)
{
	erase(CTStringVector::begin() + position);
}

std::ostream& CppTools::CTData::CTStr::CTIosSpace(std::ostream& in, size_t num)
{
	for(size_t i = 0; i < num; ++i)
		in<<" ";
	return in;
}

//CTStringList

//void CppTools::CTData::CTStr::CTStringList::readFrom(const std::string& file, bool isClear)
//{
//	if(isClear)
//		clear();
//	if(!file.size())
//		throw CppTools::CTException::CTFileException::CTFileNoName();
//	std::ifstream fin;
//	fin.open(file.c_str());
//	std::string t;
//	if(!fin)
//		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
//	while(std::getline(fin, t))
//		push_back(t);
//}
//
//void CppTools::CTData::CTStr::CTStringList::writeTo(const std::string& file)
//{
//	if(!file.size())
//		throw CppTools::CTException::CTFileException::CTFileNoName();
//	std::ofstream fout;
//	fout.open(file.c_str());
//	if(!fout)
//		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
//	//size_t i;
//	//for(i = 0; i < size(); ++i)
//	//	fout<<(*this)[i]<<std::endl;
//	fout.close();
//}
//
//void CppTools::CTData::CTStr::CTStringList::eraseAt(size_t position)
//{
//}