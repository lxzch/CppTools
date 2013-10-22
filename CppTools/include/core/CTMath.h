#pragma once
#ifndef CTMATH_H
#define CTMATH_H

#include <common\CTNoInherit.h>
#include <CTData>
#include <float.h>

_CT_MATH_BEGIN

typedef enum CPPTOOLS_TYPE_API _CTAxis
{
	axis_x = 0,
	axis_y,
	axis_z,
} CTAxis;

typedef enum CPPTOOLS_TYPE_API _CTCoordPlane
{
	xoy = 0,
	yox,
	xoz,
	zox,
	yoz,
	zoy,

} CTCoordPlane;

template <UINT n = 1>
	class Factorial
		: public CTNoInherit<Factorial<n> >
		//阶乘，适用于编译时确定n的数值时
	{
	public:
		enum{ result = n * Factorial<n - 1>::result };
	};

template <>
	class Factorial<0>
		: public CTNoInherit<Factorial<0> >
	{
	public:
		enum{ result = 1 };
	};

//二维向量运算

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec2
		: public CTNoInherit<CTVec2<Tx> >
	{
	public:
		//连续存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//清除单个2维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//清除2维向量数组中某个2维向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, Tx* in_result);	//单个2维向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//用一个2维向量来给另一个向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y,
			Tx* result, int result_index);						//给一个2维向量数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//用一个2维向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result);										//用一个2维向量数组中的某个向量来给另一个向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//用一个2维向量数组中的某个向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(Tx* first, Tx* second,
			Tx err = 0);										//判断两个向量是否相等
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//将两个2维向量相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个2维向量数组中的向量相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//将两个2维向量相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个2维向量数组中的向量相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//将2维向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//将2维向量数组中的某个向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, Tx* second);			//两个2维向量的点积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, int index_1,
			Tx* second, int index_2);							//两个2维向量数组中两个向量的点积，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//求2维向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//求2维向量数组中某个向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, Tx* second);			//求两个2维向量之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, int index_1,
			Tx* second, int index_2);							//求两个2维向量数组中某两个向量之间的夹角，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//归一化2维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//归一化2维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//输出2维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//输出2维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//输出2维向量数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTVec2<float>  CTVec2f;
typedef CTVec2<double> CTVec2d;

#endif /* NO_SIMPLE */

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec2v
		: public CTNoInherit<CTVec2v<Tx> >
	{
	public:
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx2 vec2;
		//2元存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec2 in);						//清除单个2维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec2* in, int index);			//清除2维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, vec2 in_result);	//单个2维向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2 in, vec2 result);			//用一个2维向量来给另一个向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y,
			vec2* result, int result_index);					//给一个2维向量数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2 in,
			vec2* result, int result_index);					//用一个2维向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2* in, int in_index,
			vec2* result, int result_index);					//用一个2维向量数组中的某个向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(vec2 first, vec2 second,
			Tx err = 0);										//判断两个向量是否相等
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(vec2 first, vec2 second,
			vec2 result);										//将两个2维向量相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(vec2* first, int index_1,
			vec2* second, int index_2,
			vec2* result, int result_index);					//将两个2维向量数组中的向量相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(vec2 first, vec2 second,
			vec2 result);										//将两个2维向量相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(vec2* first, int index_1,
			vec2* second, int index_2,
			vec2* result, int result_index);					//将两个2维向量数组中的向量相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec2 in);					//将2维向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec2* in, int index);		//将2维向量数组中的某个向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(vec2 first, vec2 second);			//两个2维向量的点积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(vec2* first, int index_1,
			vec2* second, int index_2);							//两个2维向量数组中两个向量的点积，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(vec2 in);						//求向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(vec2* in, int index);			//求2维向量数组中某个向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(vec2 first, vec2 second);		//求两个2维向量之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(vec2* first, int index_1,
			vec2* second, int index_2);							//求两个2维向量数组中某两个向量之间的夹角，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec2 in);					//归一化2维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec2* in, int index);		//归一化2维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(vec2 in);						//输出2维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(vec2* in, int index);			//输出2维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(vec2* in, int num);			//输出2维向量数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTVec2v<float>  CTVec2vf;
typedef CTVec2v<double> CTVec2vd;

#endif /* NO_SIMPLE */

//三维向量运算		

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec3
		: public CTNoInherit<CTVec3<Tx> >
	{
	public:
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx3	vec3;
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx3	point3;
		//连续存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//清除单个3维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//清除3维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, Tx z,
			Tx* in_result);										//单个3维向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//用一个3维向量来给另一个向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y, Tx in_z,
			Tx* result, int result_index);						//给一个3维向量数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//用一个3维向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int index,
			Tx* result);										//用一个3维向量数组中的某个向量来给一个向量赋值，以index索引			
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//用一个3维向量数组中的某个向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equalv(const Tx* in, const int index,
			vec3 result);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(Tx* first, Tx* second,
			Tx err = 0);										//判断两个向量是否相等
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetry0(Tx* first, Tx* second);	//判断两个向量是否关于原点对称
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryXoY(Tx* first, Tx* second);//判断两个向量是否关于XoY平面对称
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryYoZ(Tx* first, Tx* second);//判断两个向量是否关于YoZ平面对称
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryXoZ(Tx* first, Tx* second);//判断两个向量是否关于XoZ平面对称
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//将两个3维向量相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个3维向量数组中的向量相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second,	Tx* result);							//将一个3维向量数组中的向量与一个向量相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//将两个3维向量相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个3维向量数组中的向量相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//将3维向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//将3维向量数组中的某个向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, Tx* second);			//两个3维向量的点积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, int index_1,
			Tx* second, int index_2);							//两个3维向量数组中两个向量的点积，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(Tx* first, Tx* second,
			Tx* result);										//求两个3维向量的叉积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(Tx* first, int index_1,
			Tx* second, int index_2, Tx* result);				//求两个3维向量数组中某两个向量的叉积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//求3维向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//求3维向量数组中某个向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, Tx* second);			//求两个3维向量之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, int index_1,
			Tx* second, int index_2);							//求两个3维向量数组中某两个向量之间的夹角，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_x(Tx* in);						//求3维向量与x轴之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_z(Tx* in);						//求3维向量与z轴之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//归一化3维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//归一化3维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(Tx* in, Tx* local_z,
			Tx* result_local_x, Tx* result_local_y);			//由光线入射方向和面元法线方向决定一个局部坐标系
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void projectSystem(Tx* local_x,
			Tx* local_y, Tx* local_z,
			Tx* result_a, Tx* result_b);						//由局部坐标系生成转换所需的向量变量a和b
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void project(Tx* a, Tx* b, Tx* n, Tx* in,
			Tx* result);										//输入a,b和法线n即可将基准坐标系中的向量转化为局部坐标系中的向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx theta(Tx* in);							//返回向量入射/反射角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx phi(Tx* in);							//返回向量方位角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//输出3维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//输出3维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//输出3维向量数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTVec3<float>  CTVec3f;
typedef CTVec3<double> CTVec3d;

#endif /* NO_SIMPLE */

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec3v
		: public CTNoInherit<CTVec3v<Tx> >
	{
	public:
		typedef typename CppTools::CTMath::CTVec3<Tx>::vec3		vec3;
		typedef typename CppTools::CTMath::CTVec3<Tx>::point3	point3;
		//3元存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec3 in);						//清除单个3维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec3* in, const int index);	//清除3维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const Tx x, const Tx y,
			const Tx z, vec3 in_result);						//单个3维向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3 in, vec3 result);	//用一个3维向量来给另一个向量赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const Tx in_x, const Tx in_y,
			const Tx in_z, vec3* result,
			const int result_index);							//给一个3维向量数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3 in,
			vec3* result, const int result_index);				//用一个3维向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3* in,
			const int in_index,	vec3* result,
			const int result_index);							//用一个3维向量数组中的某个向量来给另一个数组中的某个向量赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(vec3 first, vec3 second,
			Tx err = 0);										//判断两个向量是否相等
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(const vec3 first,
			const vec3 second, vec3 result);					//将两个3维向量相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2,
			vec3* result, const int result_index);				//将两个3维向量数组中的向量相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(const vec3 first,
			const vec3 second, vec3 result);					//将两个3维向量相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2,
			vec3* result, const int result_index);				//将两个3维向量数组中的向量相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec3 in);					//将3维向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec3* in, const int index);	//将3维向量数组中的某个向量反向
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(const vec3 first,
			const vec3 second);									//两个3维向量的点积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2);				//两个3维向量数组中两个向量的点积，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(const vec3 first,
			const vec3 second, vec3 result);					//求两个3维向量的叉积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(const vec3* first,
			const int index_1,
			const vec3* second,
			const int index_2, vec3* result);					//求两个3维向量数组中某两个向量的叉积
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(const vec3 in);					//求3维向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(const vec3* in,
			const int index);									//求3维向量数组中某个向量的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(const vec3 first,
			const vec3 second);									//求两个3维向量之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2);				//求两个3维向量数组中某两个向量之间的夹角，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_x(const vec3 in);				//求3维向量与x轴之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_y(const vec3 in);				//求3维向量与y轴之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_z(const vec3 in);				//求3维向量与z轴之间的夹角 <* 天顶角 *>
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoY(const vec3 in);				//求3维向量与XoY平面之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoZ(const vec3 in);				//求3维向量与XoZ平面之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_YoZ(const vec3 in);				//求3维向量与YoZ平面之间的夹角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoY_x(const vec3 in);			//求3维向量在XoY平面上的投影与x轴之间的夹角 <* 方位角 *>
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec3 in);					//归一化3维向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec3* in, const int index);//归一化3维向量数组中某个向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(const Tx thi,
			const Tx fri, const vec3 local_z,
			vec3 result_local_x, vec3 result_local_y);			//由光线入射方向和面元法线方向决定一个局部坐标系			
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(const vec3 in,
			const vec3 local_z, vec3 result_local_x,
			vec3 result_local_y);								//由光线入射方向和面元法线方向决定一个局部坐标系
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void projectSystem(const vec3 local_x,
			const vec3 local_y, const vec3 local_z,
			vec3 result_a, vec3 result_b);						//由局部坐标系生成转换所需的向量变量a和b
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void project(const vec3 a,
			const vec3 b, const vec3 n, const vec3 in,
			vec3 result);										//输入a,b和法线n即可将基准坐标系中的向量转化为局部坐标系中的向量
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(const vec3 in);				//输出3维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(const vec3* in,
			const int index);									//输出3维向量至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(const vec3* in,
			const int num);										//输出3维向量数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTVec3v<float>  CTVec3vf;
typedef CTVec3v<double> CTVec3vd;

#endif /* NO_SIMPLE */

//复数运算

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTCplx
		: public CTNoInherit<CTCplx<Tx> >
	{
	public:
		//连续存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//清除单个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//清除复数数组中某个2维向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx real, Tx image,
			Tx* in_result);										//单个复数赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//用一个复数来给另一个复数赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_real, Tx in_image,
			Tx* result, int result_index);						//给一个复数数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//用一个复数来给另一个数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//用一个复数数组中的某个复数来给另一个数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//将两个复数相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个复数数组中的复数相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//将两个复数相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//将两个复数数组中的复数相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//复数求反
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//复数数组中的某个复数求反
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(Tx* first, Tx* second,
			Tx* result);										//两个复数的乘法
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(Tx* first, int index_1,
			Tx* second, int index_2, Tx* result);				//两个复数数组中两个复数的乘法，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx exponent, Tx* result);		//以实数为指数，e为底数构成一个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx* in, Tx* result);				//以复数为指数，e为底数构成一个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx* in, int in_index,
			Tx* result, int result_index);						//以复数数组中某个复数为指数，e为底数构成一个复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(Tx* in, Tx* result);		//求共轭复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(Tx* in, int in_index,
			Tx* result, int result_index);						//求共轭复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//求复数的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//求复数数组中某个复数的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//归一化复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//归一化复数数组中某个复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//输出复数至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//输出复数至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//输出复数数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTCplx<float>  CTCplxf;
typedef CTCplx<double> CTCplxd;

#endif /* NO_SIMPLE */

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTCplxv
		: public CTNoInherit<CTCplxv<Tx> >
	{
	public:
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx2 cplx;
		//2元存储运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(cplx in);						//清除单个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(cplx* in, int index);			//清除复数数组中某个2维向量，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx real, Tx image,
			cplx in_result);									//单个复数赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx in, cplx result);			//用一个复数来给另一个复数赋值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_real, Tx in_image,
			cplx* result, int result_index);					//给一个复数数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx in,
			cplx* result, int result_index);					//用一个复数来给另一个数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx* in, int in_index,
			cplx* result, int result_index);					//用一个复数数组中的某个复数来给另一个数组中的某个复数赋值，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(cplx first, cplx second,
			cplx result);										//将两个复数相加
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(cplx* first, int index_1,
			cplx* second, int index_2,
			cplx* result, int result_index);					//将两个复数数组中的复数相加，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(cplx first, cplx second,
			cplx result);										//将两个复数相减，vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(cplx* first, int index_1,
			cplx* second, int index_2,
			cplx* result, int result_index);					//将两个复数数组中的复数相减，vec1-vec2，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(cplx in);					//复数求反
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(cplx* in, int index);		//复数数组中的某个复数求反
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(cplx first, cplx second,
			cplx result);										//两个复数的乘法
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(cplx* first, int index_1,
			cplx* second, int index_2, cplx result);			//两个复数数组中两个复数的乘法，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx exponent, cplx result);		//以实数为指数，e为底数构成一个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(cplx in, cplx result);			//以复数为指数，e为底数构成一个复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(cplx* in, int in_index,
			cplx* result, int result_index);					//以复数数组中某个复数为指数，e为底数构成一个复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(cplx in, cplx result);		//求共轭复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(cplx* in, int in_index,
			cplx* result, int result_index);					//求共轭复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(cplx in);						//求复数的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(cplx* in, int index);			//求复数数组中某个复数的模值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(cplx in);					//归一化复数
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(cplx* in, int index);		//归一化复数数组中某个复数，以index索引
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(cplx in);						//输出复数至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(cplx* in, int index);			//输出复数至屏幕
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(cplx* in, int num);			//输出复数数组至屏幕
	};

#ifndef NO_SIMPLE

typedef CTCplxv<float>  CTCplxvf;
typedef CTCplxv<double> CTCplxvd;

#endif /* NO_SIMPLE */

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTCalculate
		: public CTNoInherit<CTCalculate<Tx> >
	{
	public:
		typedef Tx*			p_Tx;
		typedef Tx**		pp_Tx;
		typedef Tx***		ppp_Tx;

		typedef CppTools::CTData::CTPoint2<Tx>										ct_point2;
		typedef CppTools::CTData::CTPoint3<Tx>										ct_point3;
		typedef typename CppTools::CTMath::CTVec3v<Tx>::vec3						vec3;
		typedef typename CppTools::CTMath::CTVec3v<Tx>::point3						point3;

		typedef typename CppTools::CTData::CTFuncBase<Tx, int>::p_TFunc_u			p_Tx_func_i;
		typedef typename CppTools::CTData::CTFuncBase<Tx, Tx>::p_TFunc_u			p_Tx_func_Tx;
		typedef typename CppTools::CTData::CTFuncBase<Tx, Tx, Tx>::p_TFunc_uv		p_Tx_func_Tx_Tx;
		typedef typename CppTools::CTData::CTFuncBase<Tx, Tx, Tx, Tx>::p_TFunc_uvw	p_Tx_func_Tx_Tx_Tx;

		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isNaN(const Tx num);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool checkNaN(const Tx num);

		//单位的转换
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle2Radian(Tx angle);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx radian2Angle(Tx radian);

		//基本运算
		static inline Tx sumOf(int n, ...);
		static inline Tx averageOf(int n, ...);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx sumOfSquares(Tx a, Tx b);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx difOfSquares(Tx a, Tx b);

		//基本工具
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(const Tx a, const Tx b, const Tx error = (Tx)1e-6);//浮点数近似比较

		//解析几何
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx compleAngle(Tx angle);//计算余角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx suppleAngle(Tx angle);//计算补角
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx distance(const Tx* point3_1, const Tx* point3_2);//计算两点之间的距离
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx distance(const ct_point3& point3_1, const ct_point3& point3_2);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void plainCenter(const point3 point_1, const point3 point_2, const point3 point_3, point3 center_point);//计算三角形面元中点
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void plainCenter(const point3 point_1, const point3 point_2, const point3 point_3, const point3 point_4, point3 center_point);//计算四边形面元中点

		//高等数学
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx Integral(const p_Tx_func_Tx func, const Tx x_start, const Tx x_end, const int n = 10000);//一重积分
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx Integral2d(const p_Tx_func_Tx_Tx func, const Tx x_start, const Tx x_end, const Tx y_start, const Tx y_end, const int x_n = 100, const int y_n = 100);//二重积分
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx sumFunc(const p_Tx_func_i func, const int start, const Tx error = (Tx)1e-3);	//从start到无穷，对func各项求和，直到func<error时结束
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx factorial(const UINT n);//阶乘

		//数理统计
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx maxOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx minOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx sumOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx squareOf(const Tx* data, const int n);//平方和
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx averageOf(const Tx* data, const int n);//均值
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx varianceOf(const Tx* data, const int n);//方差
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx stdDeviationOf(const Tx* data, const int n);//标准差
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx stdErrorOf(const Tx* data, const Tx true_value, const int n);//标准误差
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx rootMeanSquareOf(const Tx* data, const int n);//均方根

		//与物理相关的数学运算
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx steradian(const Tx area_on_sphere, const Tx radius);//已知球面面积求球面度
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx areaOnSphere(const Tx steradian, const Tx radius);//已知球面度求球面面积
	};

#ifndef NO_SIMPLE

typedef CTCalculate<float>  CTCalf;
typedef CTCalculate<double> CTCald;

#endif /* NO_SIMPLE */

CPPTOOLS_INLINEFUNC_API inline
	void RandomInit()
{
	srand((UINT)time(0));
}

template <typename Tx>
CPPTOOLS_INLINEFUNC_API inline
	Tx Random()
{
	return rand() / (Tx)RAND_MAX;
}

template <typename Tx>
CPPTOOLS_INLINEFUNC_API inline
	Tx Random(Tx start,
		Tx end)
{
	return (end - start) * Random<Tx>() + start;
}

CPPTOOLS_INLINEFUNC_API inline
	int Random(int max)
{
	return rand() * max / RAND_MAX;
}

CPPTOOLS_INLINEFUNC_API inline
	int Random(int min,
		int max)
{
	return (min + rand() * max / RAND_MAX);
}

template <typename Tx>
CPPTOOLS_INLINEFUNC_API inline
	Tx RandomGauss();

_CT_MATH_END

#include <core\CTMath.tpc>

#endif