#pragma once
#ifndef CTARRAY1D_H
#define CTARRAY1D_H

#include <CTMemory>

namespace CppTools
{
	namespace CTMemory
	{
		template<typename Tx>
		class CPPTOOLS_TCLASS_API CTArray1d
		{
		public:
			explicit CTArray1d(const int size = 0);
			CTArray1d(const CTArray1d& _old);
			~CTArray1d();

			Tx* newArray(int size);
			Tx get(int position) const;
			void set(int position, Tx context);
			int size() const;
			void resize(int new_size);
			const CTArray1d& operator =(const CTArray1d& right);
			bool operator ==(const CTArray1d& right) const;
			bool operator !=(const CTArray1d& right) const;
			Tx& operator [](int position);
			const Tx& operator [](int position) const;
			Tx& operator ()(int position) const;
			friend std::istream& operator >>(std::istream& in, CTArray1d& right)
			{
				for(int i = 0; i < right._size; ++i)
					in >> right.data[i];
				return in;
			}
			friend std::ostream& operator <<(std::ostream& out, const CTArray1d& right)
			{
				for(int i = 0; i < right._size; ++i)
					out << right.data[i] << setw(2);
				out << endl;
				return out;
			}

		protected:
			Tx* data;
			int _size;
		};		
	}
}

#include <core\CTArray1d.tpc>

typedef CppTools::CTMemory::CTArray1d<char>			CTMat1c;
typedef CppTools::CTMemory::CTArray1d<UINT>			CTMat1u;
typedef CppTools::CTMemory::CTArray1d<int>			CTMat1i;
typedef CppTools::CTMemory::CTArray1d<long>			CTMat1l;
typedef CppTools::CTMemory::CTArray1d<float>		CTMat1f;
typedef CppTools::CTMemory::CTArray1d<double>		CTMat1d;
typedef CppTools::CTMemory::CTArray1d<std::string>	CTMat1s;

#ifndef mat1
typedef CTMat1f mat1;
#endif

#endif