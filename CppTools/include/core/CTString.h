#pragma once

#ifndef CTSTRING_H
#define CTSTRING_H

#include <CTData>
#include <exception\CTFileException.h>

template class CPPTOOLS_API std::allocator<std::string>;
template class CPPTOOLS_API std::vector<std::string>;
//template class CPPTOOLS_API std::list<std::string>;

typedef std::vector<std::string> stringVector;
typedef std::list<std::string> stringList;

namespace CppTools
{
	namespace CTData
	{
		namespace CTStr
		{
			class CPPTOOLS_API CTString
				: public std::string, public CTObject
				//std::string����չ�ַ�����
			{
			public:
				typedef std::vector<CTString> CTStrVector;

				CTString(const std::string& in = "");
				template <typename Tx>
				CTString(const CppTools::CTData::CTDataBase<Tx>& in);
				CTString(const char* in);
				CTString(const int in);
				CTString(const UINT in);
				CTString(const char in);
				CTString(const UCHAR in);
				CTString(const long in);
				CTString(const ULONG in);
				CTString(const float in);
				CTString(const double in);

				~CTString();

				void toUpper();
				//�������ַ�ת���ɴ�д
				void toLower();
				//�������ַ�ת����Сд

				int toInt();
				//ת����32λ����
				UINT toUint();
				//ת����32λ�޷�������
				char toChar();          
				//ת����8λ�ַ���
				UCHAR toUchar();
				//ת����8λ�޷����ַ���
				long toLong();          
				//ת����32λ������
				ULONG toUlong(); 
				//ת����32λ�޷��ų�����
				float toFloat();        
				//ת����32λ������
				double toDouble();      
				//ת����64λ˫������

				CTString trim();
				//���ַ�����ͷ�ͽ�β���Ŀո�ȥ��
				stringVector split(const char& separator = ' ');
				//���ַ������տո���,���������һ��stringList��
				CTStrVector c_split(const char& separator = ' ');
				//���ַ������տո���,���������һ��ctStrList��

				CTString& operator = (const char* right)
				{
					erase();
					append(right);
					return *this;
				}

				CTString& operator + (const char* right)
				{
					append(right);
					return *this;
				}

				CTString& operator += (const char* right)
				{
					append(right);
					return *this;
				}

				friend CTString& operator + (const char* left, CTString& right)
				{
					right._inserttop(left);
					return right;
				}

				template<typename Tx>
				CTString& operator = (const Tx& right)
				{
					_newdata(right);
					return *this;
				}

				template<typename Tx>
				CTString& operator + (const Tx& right)
				{
					_append(right);
					return *this;
				}				

				template<typename Tx>
				CTString& operator += (const Tx& right)
				{
					_append(right);
					return *this;
				}

				template<typename Tx>
				friend CTString& operator + (Tx& left, CTString& right)
				{
					right._inserttop(left);
					return right;
				}

				template<>
				CTString& operator + (const CTString& right)
				{
					append(std::string(right.c_str()));
					return *this;
				}

				template<>
				CTString& operator + (const std::string& right)
				{
					append(right);
					return *this;
				}

				template<>
				CTString& operator += (const std::string& right)
				{
					append(right);
					return *this;
				}

				friend CTString& operator + (const CTString& left, CTString& right)
				{
					right.insert(0, std::string(left.c_str()));
					return right;
				}

				friend CTString& operator += (const CTString& left, CTString& right)
				{
					right.insert(0, std::string(left.c_str()));
					return right;
				}

				friend CTString& operator + (const std::string& left, CTString& right)
				{
					right.insert(0, left);
					return right;
				}

				friend CTString& operator += (const std::string& left, CTString& right)
				{
					right.insert(0, left);
					return right;
				}

				friend std::istream& operator >>(std::istream& in, CTString& right)
				{
					in >> std::string(right.c_str());
					return in;
				}

				friend std::ostream& operator <<(std::ostream& out, const CTString& right)
				{
					out << std::string(right.c_str());
					return out;
				}

			protected:
				template<typename Tx>
				void _newdata(Tx _data)
				{
					erase();
					append(CppTools::CTData::CTStr::NtoS(_data));
				}

				template<typename Tx>
				void _append(Tx _data)
				{
					append(CppTools::CTData::CTStr::NtoS(_data));
				}

				template<typename Tx>
				void _inserttop(Tx _data)
				{
					insert(0, CppTools::CTData::CTStr::NtoS(_data));
				}
			};

			class CPPTOOLS_API CTStringVector
				: public std::vector<std::string>, public CTObject
			{
			public:
				void readFrom(const std::string& file, bool isClear = true);
				void writeTo(const std::string& file, const std::string& seperator = "", const bool is_endl = true);
				void writeTo(std::ofstream& fout, const std::string& seperator = "", const bool is_endl = true);
				void writeTo(std::ofstream& fout, const std::vector<int>& seperator, const bool is_endl = true);
				void eraseAt(size_t position);
			};

			class CTStringVectors
				: public CTObject
			{
			public:
				inline void writeTo(const std::string& file, const std::string& seperator = "", const bool is_endl = true, const bool is_vector_endl = true);
				inline void writeTo(const std::string& file, const std::vector<std::vector<int> >& seperator, const bool is_endl = true, const bool is_vector_endl = true);
				std::vector<CTStringVector> svs;
			};

			//class CPPTOOLS_API CTStringList
			//	: public std::list<std::string>
			//{
			//public:
			//	void readFrom(const std::string& file = "", bool isClear = true);
			//	void writeTo(const std::string& file = "");
			//	void eraseAt(size_t position);
			//};
			CPPTOOLS_API std::ostream& CTIosSpace(std::ostream& in, size_t num);
		}
	}
}

void CppTools::CTData::CTStr::CTStringVectors::writeTo(const std::string& file, const std::string& seperator, const bool is_endl, const bool is_vector_endl)
{
	if(!file.size())
		throw CppTools::CTException::CTFileException::CTFileNoName();
	std::ofstream fout(file.c_str());
	if(!fout)
		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
	size_t i;
	for(i = 0; i < svs.size(); ++i)
	{
		svs[i].writeTo(fout, seperator, is_endl);
		if(is_vector_endl)
			fout<<std::endl;
	}
	fout.close();
}

void CppTools::CTData::CTStr::CTStringVectors::writeTo(const std::string& file, const std::vector<std::vector<int> >& seperator, const bool is_endl, const bool is_vector_endl)
{
	if(!file.size())
		throw CppTools::CTException::CTFileException::CTFileNoName();
	std::ofstream fout(file.c_str());
	if(!fout)
		throw CppTools::CTException::CTFileException::CTFileNotFound(file);
	size_t i;
	for(i = 0; i < svs.size(); ++i)
	{
		svs[i].writeTo(fout, seperator[i], is_endl);
		if(is_vector_endl)
			fout<<std::endl;
	}
	fout.close();
}

#ifndef NO_SIMPLE

#endif

#define StoI  CppTools::CTData::CTStr::StoN<int>
#define StoUI CppTools::CTData::CTStr::StoN<UINT>
#define StoC  CppTools::CTData::CTStr::StoN<char>
#define StoUC CppTools::CTData::CTStr::StoN<UCHAR>
#define StoL  CppTools::CTData::CTStr::StoN<long>
#define StoUL CppTools::CTData::CTStr::StoN<ULONG>
#define StoF  CppTools::CTData::CTStr::StoN<float>
#define StoD  CppTools::CTData::CTStr::StoN<double>

#endif