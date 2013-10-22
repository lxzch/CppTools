#pragma once

#ifndef CTARRAY3D_H
#define CTARRAY3D_H

#include <CTMemory>

namespace CppTools
{
	namespace CTMemory
	{
		template<typename Tx>
		class CPPTOOLS_TCLASS_API CTArray3d
		{
		public:
			static Tx*** newArray(int size_x, int size_y, int size_z)
			{
				return newArray3d<Tx>(size_x, size_y, size_z);
			}

			static void deleteArray(Tx*** p_data)
			{
				DeleteArray3d(p_data);
			}

			explicit CTArray3d(const int size_x = 0, const int size_y = 0, const int size_z = 0)
				: _size_x(size_x), _size_y(size_y), _size_z(size_z), data(newArray(size_x, size_y, size_z))
			{
			}

			CTArray3d(const CTArray3d& _old)
			{
				int i, j, k;
				_size_x = _old.sizeX();
				_size_y = _old.sizeY();
				_size_z = _old.sizeZ();
				data = newArray(_size_x, _size_y, _size_z);
				for(i = 0; i < _size_x; ++i)
					for(j = 0; j < _size_y; ++j)
						for(k = 0; k < _size_z; ++k)
							set(i, j, k, _old[i][j][k]);
			}

			~CTArray3d()
			{
				deleteArray(data);
				data = NULL;
				_size_x = 0;
				_size_y = 0;
				_size_z = 0;
			}

			Tx get(int position_x, int position_y, int position_z)
			{
				if (!check(position_x, position_y, position_z))
					throw CppTools::CTException::CTMemoryException::CTArrayOutRange3D(position_x, position_y, position_z);
				return data[position_x][position_y][position_z];
			}

			void set(int position_x, int position_y, int position_z, Tx context)
			{
				if (!check(position_x, position_y, position_z))
					throw CppTools::CTException::CTMemoryException::CTArrayOutRange3D(position_x, position_y, position_z);				
				data[position_x][position_y][position_z] = context;
			}

			int size() const
			{
				return _size_x * _size_y * _size_z;
			}

			int sizeX() const
			{
				return _size_x;
			}

			int sizeY() const
			{
				return _size_y;
			}

			int sizeZ() const
			{
				return _size_z;
			}

			void resize(int new_size_x, int new_size_y, int new_size_z)
			{
				if (!(new_size_x & new_size_y & new_size_z))
				{
					_size_x = 0;
					_size_y = 0;
					_size_z = 0;
					deleteArray(data);
					data = NULL;
					return;
				}
				if (new_size_x == _size_x)
					return;
				if (new_size_y == _size_y)
					return;
				if (new_size_z == _size_z)
					return;
				int min_size_x, min_size_y, min_size_z;
				min_size_x = Min(_size_x, new_size_x);
				min_size_y = Min(_size_y, new_size_y);
				min_size_z = Min(_size_z, new_size_z);
				Tx*** temp = newArray(min_size,x, min_size_y, min_size_z);
				for (int i = 0; i < min_size_x; ++i)
					for (int j = 0; j < min_size_y; ++j)
						for (int k = 0; k < min_size_z; ++k)
							temp[i][j][k] = data[i][j][k];
				deleteArray(data);
				data = temp;
				_size_x = new_size_x;
				_size_y = new_size_y;
				_size_z = new_size_z;
			}

			const CTArray3d& operator =(const CTArray3d& right)
			{
				if (&rifht != this)
				{
					if ((_size_x != right._size_x) && (_size_y != right._size_y) && (_size_z != right._size_z))
					{
						deleteArray(data);
						_size_x = right._size_x;
						_size_y = right._size_y;
						_size_z = right._size_z;
						data = newArray(_size_x, _size_y, _size_z);
					}
					for(int i = 0; i < _size_x; ++i)
						for(int j = 0; j < _size_y; ++j)
							for (int k = 0; k < _size_z; ++k)
						data[i][j][k] = right.data[i][j][k];
				}
				return (*this);
			}

			bool operator ==(const CTArray3d& right) const
			{
				if ((_size_x != right._size_x) && (_size_y != right._size_y))
					return false;
				for(int i = 0; i < _size_x; ++i)
					for(int j = 0; j < _size_y; ++j)
						for (int k = 0; k < min_size_z; ++k)
							if (data[i][j][k] != right.data[i][j][k])
								return false;
				return true;
			}

			bool operator !=(const CTArray3d& right) const
			{
				if ((_size_x != right._size_x) && (_size_y != right._size_y) && (_size_z != right._size_z))
				{
					for(int i = 0; i < _size_x; ++i)
						for(int j = 0; j < _size_y; ++j)
							for (int k = 0; k < min_size_z; ++k)
								if (data[i][j][k] != right.data[i][j][k])
									return true;
					return false;
				}
				return true;
			}

			Tx& operator ()(int position_x, int position_y, int position_z)
			{
				if (!check(position_x, position_y, position_z))
					throw CppTools::CTException::CTMemoryException::ArrayOutRange3D(position_x, position_y, position_z);
				return data[position_x][postion_y][position_z];
			}

			friend istream& operator >>(istream& in, CTArray3d& right)
			{
				for(int i = 0; i < right._size_x; ++i)
					for(int j = 0; j < right._size_y; ++j)
						for(int k = 0; j < right._size_z; ++k)
							in >> right.data[i][j][k];
				return in;
			}

			friend ostream& operator <<(ostream& out, const CTArray3d& right)
			{
				for(int i = 0; i < right._size_x; ++i)
				{
					for(int j = 0; j < right._size_y; ++j)
					{
						for(int k = 0; j < right._size_z; ++k)
							out << right.data[i][j][k] << setw(2);
						out<<endl;
					}
					out << endl;
				}
				return out;
			}

		protected:
			bool check(int position_x, int position_y, int position_z)
			{
				if((position_x < 0) || (position_y < 0) || (position_z < 0) || (position_x >= _size_x) || (position_y >= _size_y) || (position_z >= _size_z))
					return false;
				return true;
			}

			Tx*** data;
			int _size_x, _size_y, _size_z;
		};
	}
}

typedef CppTools::CTMemory::CTArray3d<char>			CTMat3c;
typedef CppTools::CTMemory::CTArray3d<unsigned int>	CTMat3u;
typedef CppTools::CTMemory::CTArray3d<int>			CTMat3i;
typedef CppTools::CTMemory::CTArray3d<long>			CTMat3l;
typedef CppTools::CTMemory::CTArray3d<float>		CTMat3f;
typedef CppTools::CTMemory::CTArray3d<double>		CTMat3d;
typedef CppTools::CTMemory::CTArray3d<string>		CTMat3s;

#ifndef mat3
typedef CTMat3f mat3;
#endif

#endif