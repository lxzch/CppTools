#pragma once

#ifndef CTARRAY2D_H
#define CTARRAY2D_H

#include <CTMemory>

namespace CppTools
{
	namespace CTMemory
	{
		template<typename Tx>
		class CPPTOOLS_TCLASS_API CTArray2d
		{
		public:
			Tx** newArray(int size_x, int size_y)
			{
				return NewArray2d<Tx>(size_x, size_y);				
			}

			void deleteArray(Tx** p_data)
			{
				DeleteArray2d(p_data);
			}

			explicit CTArray2d(const int size_x = 0, const int size_y = 0)
				: _size_x(size_x), _size_y(size_y), data(newArray(size_x, size_y))
			{
			}

			CTArray2d(const CTArray2d& _old)
			{
				int i, j;
				_size_x = _old.sizeX();
				_size_y = _old.sizeY();
				data = newArray(_size_x, _size_y);
				for(i = 0; i < _size_x; ++i)
					for(j = 0; j < _size_y; ++j)
						set(i, j, _old[i][j]);
			}

			~CTArray2d()
			{
				deleteArray(data);
				data = NULL;
				_size_x = 0;
				_size_y = 0;
			}

			Tx get(int position_x, int position_y)
			{
				if (!check(position_x, position_y))
					throw CppTools::CTException::CTMemoryException::CTArrayOutRange2D(position_x, position_y);
				return data[position_x][position_y];
			}

			void set(int position_x, int position_y, Tx context)
			{
				if (!check(position_x, position_y))
					throw CppTools::CTException::CTMemoryException::CTArrayOutRange2D(position_x, position_y);
				data[position_x][position_y] = context;
			}

			int size() const
			{
				return _size_x * _size_y;
			}

			int sizeX() const
			{
				return _size_x;
			}

			int sizeY() const
			{
				return _size_y;
			}

			void resize(int new_size_x, int new_size_y)
			{
				if (!(new_size_x & new_size_y))
				{
					_size_x = 0;
					_size_y = 0;
					delete[] data;
					return;
				}
				if (new_size_x == _size_x)
					return;
				if (new_size_y == _size_y)
					return;
				int min_size_x, min_size_y;
				min_size_x = Min(_size_x, new_size_x);
				min_size_y = Min(_size_y, new_size_y);
				temp = newArray(min_size,x, min_size_y);
				if(!temp)
					for (int i = 0; i < min_size_x; ++i)
					for (int j = 0; j < min_size_y; ++j)
						temp[i][j] = data[i][j];
				deleteArray(data);
				data = temp;
				_size_x = new_size_x;
				_size_y = new_size_y;
			}

			const CTArray2d& operator =(const CTArray2d& right)
			{
				if (&rifht != this)
				{
					if ((_size_x != right._size_x) && (_size_y != right._size_y))
					{						
						_size_x = right._size_x;
						_size_y = right._size_y;
						deleteArray(data);
						data = newArray(_size_x, _size_y);
					}
					for(int i = 0; i < _size_x; ++i)
						for(int j = 0; j < _size_y; ++j)
						data[i][j] = right.data[i][j];
				}
				return (*this);
			}

			bool operator ==(const CTArray2d& right) const
			{
				if ((_size_x != right._size_x) && (_size_y != right._size_y))
					return false;
				for(int i = 0; i < _size_x; ++i)
					for(int j = 0; j < _size_y; ++j)
						if (data[i][j] != right.data[i][j])
							return false;
				return true;
			}

			bool operator !=(const CTArray2d& right) const
			{
				if ((_size_x != right._size_x) && (_size_y != right._size_y))
				{
					for(int i = 0; i < _size_x; ++i)
						for(int j = 0; j < _size_y; ++j)
							if (data[i][j] != right.data[i][j])
								return true;
					return false;
				}
				return true;
			}

			Tx& operator ()(int position_x, int position_y)
			{
				if (!check(position_x, position_y))
					throw CppTools::CTException::CTMemoryException::CTArrayOutRange2D(position_x, position_y);
				return data[position_x][postion_y];
			}

			friend istream& operator >>(istream& in, CTArray2d& right)
			{
				for(int i = 0; i < right._size_x; ++i)
					for(int j = 0; j < right._size_y; ++j)
						in >> right.data[i][j];
				return in;
			}

			friend ostream& operator <<(ostream& out, const CTArray2d& right)
			{
				for(int i = 0; i < right._size_x; ++i)
				{
					for(int j = 0; j < right._size_y; ++j)
						out << right.data[i][j] << setw(2);
					out << endl;
				}
				return out;
			}

		protected:
			bool check(int position_x, int position_y)
			{
				if((position_x < 0) || (position_y < 0) || (position_x >= _size_x) || (position_y >= _size_y))
					return false;
				return true;
			}

			Tx** data;
			int _size_x, _size_y;
		};
	}
}

typedef CppTools::CTMemory::CTArray2d<char>			CTMat2c;
typedef CppTools::CTMemory::CTArray2d<unsigned int>	CTMat2u;
typedef CppTools::CTMemory::CTArray2d<int>			CTMat2i;
typedef CppTools::CTMemory::CTArray2d<long>			CTMat2l;
typedef CppTools::CTMemory::CTArray2d<float>		CTMat2f;
typedef CppTools::CTMemory::CTArray2d<double>		CTMat2d;
typedef CppTools::CTMemory::CTArray2d<string>		CTMat2s;

#ifndef mat2
typedef CTMat2f mat2;
#endif

#endif