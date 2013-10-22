#ifndef CTCMEMORY_H
#define CTCMEMORY_H

#include <CTBase>
#include <exception\CTMemoryException.h>

_CT_MEMORY_BEGIN

template<typename Tx> CPPTOOLS_TFUNC_API
	void Memset(Tx* dest,
	Tx value,
	int size,
	const int start_pos = 0)
{
	for(int i = start_pos; i < size; ++i)
		dest[i] = value;
}

template<typename Tx,
	typename Ty,
	typename Tz> CPPTOOLS_TFUNC_API
	void MemsetAdd(Tx* dest,
		Ty value,
		Tz increment,
		int size,
		const int start_pos = 0)
{
	for(int i = start_pos; i < size; ++i)
		dest[i] = value + i * increment;
}

template<typename Tx,
	typename Ty,
	typename Tz> CPPTOOLS_TFUNC_API
	void MemsetMult(Tx* dest,
		Ty value,
		Tz increment,
		int size,
		const int start_pos = 0)
{
	for(int i = start_pos; i < size; ++i)
		dest[i] = value * i * increment;
}

template<typename Tx,
	typename Ty,
	typename Tz> CPPTOOLS_TFUNC_API
	void MemsetMultAdd(Tx* dest,
		Tx value,
		Ty increase_increment,
		Tz multiply_increment,
		int size,
		const int start_pos = 0)
{
	for(int i = start_pos; i < size; ++i)
		dest[i] = value * i * multiply_increment + increase_increment;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	void Mem1dto2d(Tx* source,
		int num_per_line,
		int lines,
		Tx** dest)
{
	for(int i = 0; i < lines; ++i)
		dest[i] = source + num_per_line * i;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	void Mem1dto3d(Tx* source,
		int stride,
		int num_per_line,
		int lines,
		Tx*** dest)
{
	for(int i = 0; i < lines; ++i)
		for(int j = 0; j < num_per_line; ++j)
			dest[i][j] = source + num_per_line * stride * i + stride * j;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx* NewArray1d(int size)
{
	Tx* temp = NULL;
	temp = new Tx[size];
	if(!temp)
		throw CppTools::CTException::CTMemoryException::CTNotEnoughMemory();
	return temp;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx* NewArray1d(int size,
		Tx default_value)
{
	Tx* temp = NULL;
	temp = new Tx[size];
	Memset(temp, default_value, size);
	if(!temp)
		throw CppTools::CTException::CTMemoryException::CTNotEnoughMemory();
	return temp;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx** NewArray2d(int size_x,
		int size_y)
{
	Tx* _data = NewArray1d<Tx>(size_x * size_y);
	Tx** p_data = NewArray1d<Tx*>(size_x);
	Mem1dto2d(_data, size_y, size_x, p_data);
	return p_data;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx** NewArray2d(int size_x,
		int size_y,
		Tx default_value)
{
	Tx* _data = NewArray1d<Tx>(size_x * size_y, default_value);
	Tx** p_data = NewArray1d<Tx*>(size_x);
	Mem1dto2d(_data, size_y, size_x, p_data);
	return p_data;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx*** NewArray3d(int size_x,
		int size_y,
		int size_z)
{
	Tx* _data = NewArray1d<Tx>(size_x * size_y * size_z);
	Tx*** p_p_data = NewArray1d<Tx**>(size_x);
	Mem1dto3d(_data, size_z, size_y, size_x, p_p_data);
	return p_p_data;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	Tx*** NewArray3d(int size_x,
		int size_y,
		int size_z,
		Tx default_value)
{
	Tx* _data = NewArray1d<Tx>(size_x * size_y * size_z, default_value);
	Tx*** p_p_data = NewArray1d<Tx**>(size_x);	
	Mem1dto3d(_data, size_z, size_y, size_x, p_p_data);
	return p_p_data;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	void DeleteArray1d(Tx* array1d)
{
	delete[] array1d;
	array1d = NULL;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	void DeleteArray2d(Tx** array2d)
{
	delete[] array2d[0];
	delete[] array2d;
	array2d = NULL;
}

template<typename Tx> CPPTOOLS_TFUNC_API
	void DeleteArray3d(Tx*** array3d)
{
	delete[] array3d[0][0];
	delete[] array3d[0];
	delete[] array3d;
	array3d = NULL;
}

_CT_MEMORY_END

#endif /* CTCMemory.h */