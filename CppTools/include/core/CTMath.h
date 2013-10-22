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
		//�׳ˣ������ڱ���ʱȷ��n����ֵʱ
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

//��ά��������

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec2
		: public CTNoInherit<CTVec2<Tx> >
	{
	public:
		//�����洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//�������2ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//���2ά����������ĳ��2ά��������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, Tx* in_result);	//����2ά������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//��һ��2ά����������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y,
			Tx* result, int result_index);						//��һ��2ά���������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//��һ��2ά����������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result);										//��һ��2ά���������е�ĳ������������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//��һ��2ά���������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(Tx* first, Tx* second,
			Tx err = 0);										//�ж����������Ƿ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//������2ά�������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//������2ά���������е�������ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//������2ά���������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//������2ά���������е����������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//��2ά��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//��2ά���������е�ĳ����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, Tx* second);			//����2ά�����ĵ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, int index_1,
			Tx* second, int index_2);							//����2ά�������������������ĵ������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//��2ά������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//��2ά����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, Tx* second);			//������2ά����֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, int index_1,
			Tx* second, int index_2);							//������2ά����������ĳ��������֮��ļнǣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//��һ��2ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//��һ��2ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//���2ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//���2ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//���2ά������������Ļ
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
		//2Ԫ�洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec2 in);						//�������2ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec2* in, int index);			//���2ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, vec2 in_result);	//����2ά������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2 in, vec2 result);			//��һ��2ά����������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y,
			vec2* result, int result_index);					//��һ��2ά���������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2 in,
			vec2* result, int result_index);					//��һ��2ά����������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(vec2* in, int in_index,
			vec2* result, int result_index);					//��һ��2ά���������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(vec2 first, vec2 second,
			Tx err = 0);										//�ж����������Ƿ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(vec2 first, vec2 second,
			vec2 result);										//������2ά�������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(vec2* first, int index_1,
			vec2* second, int index_2,
			vec2* result, int result_index);					//������2ά���������е�������ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(vec2 first, vec2 second,
			vec2 result);										//������2ά���������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(vec2* first, int index_1,
			vec2* second, int index_2,
			vec2* result, int result_index);					//������2ά���������е����������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec2 in);					//��2ά��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec2* in, int index);		//��2ά���������е�ĳ����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(vec2 first, vec2 second);			//����2ά�����ĵ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(vec2* first, int index_1,
			vec2* second, int index_2);							//����2ά�������������������ĵ������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(vec2 in);						//��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(vec2* in, int index);			//��2ά����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(vec2 first, vec2 second);		//������2ά����֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(vec2* first, int index_1,
			vec2* second, int index_2);							//������2ά����������ĳ��������֮��ļнǣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec2 in);					//��һ��2ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec2* in, int index);		//��һ��2ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(vec2 in);						//���2ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(vec2* in, int index);			//���2ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(vec2* in, int num);			//���2ά������������Ļ
	};

#ifndef NO_SIMPLE

typedef CTVec2v<float>  CTVec2vf;
typedef CTVec2v<double> CTVec2vd;

#endif /* NO_SIMPLE */

//��ά��������		

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTVec3
		: public CTNoInherit<CTVec3<Tx> >
	{
	public:
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx3	vec3;
		typedef typename CppTools::CTData::CTArrayBase<Tx>::p_Tx3	point3;
		//�����洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//�������3ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//���3ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx x, Tx y, Tx z,
			Tx* in_result);										//����3ά������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//��һ��3ά����������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_x, Tx in_y, Tx in_z,
			Tx* result, int result_index);						//��һ��3ά���������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//��һ��3ά����������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int index,
			Tx* result);										//��һ��3ά���������е�ĳ����������һ��������ֵ����index����			
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//��һ��3ά���������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equalv(const Tx* in, const int index,
			vec3 result);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(Tx* first, Tx* second,
			Tx err = 0);										//�ж����������Ƿ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetry0(Tx* first, Tx* second);	//�ж����������Ƿ����ԭ��Գ�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryXoY(Tx* first, Tx* second);//�ж����������Ƿ����XoYƽ��Գ�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryYoZ(Tx* first, Tx* second);//�ж����������Ƿ����YoZƽ��Գ�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isSymmetryXoZ(Tx* first, Tx* second);//�ж����������Ƿ����XoZƽ��Գ�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//������3ά�������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//������3ά���������е�������ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second,	Tx* result);							//��һ��3ά���������е�������һ��������ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//������3ά���������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//������3ά���������е����������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//��3ά��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//��3ά���������е�ĳ����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, Tx* second);			//����3ά�����ĵ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(Tx* first, int index_1,
			Tx* second, int index_2);							//����3ά�������������������ĵ������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(Tx* first, Tx* second,
			Tx* result);										//������3ά�����Ĳ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(Tx* first, int index_1,
			Tx* second, int index_2, Tx* result);				//������3ά����������ĳ���������Ĳ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//��3ά������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//��3ά����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, Tx* second);			//������3ά����֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(Tx* first, int index_1,
			Tx* second, int index_2);							//������3ά����������ĳ��������֮��ļнǣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_x(Tx* in);						//��3ά������x��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_z(Tx* in);						//��3ά������z��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//��һ��3ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//��һ��3ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(Tx* in, Tx* local_z,
			Tx* result_local_x, Tx* result_local_y);			//�ɹ������䷽�����Ԫ���߷������һ���ֲ�����ϵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void projectSystem(Tx* local_x,
			Tx* local_y, Tx* local_z,
			Tx* result_a, Tx* result_b);						//�ɾֲ�����ϵ����ת���������������a��b
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void project(Tx* a, Tx* b, Tx* n, Tx* in,
			Tx* result);										//����a,b�ͷ���n���ɽ���׼����ϵ�е�����ת��Ϊ�ֲ�����ϵ�е�����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx theta(Tx* in);							//������������/�����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx phi(Tx* in);							//����������λ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//���3ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//���3ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//���3ά������������Ļ
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
		//3Ԫ�洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec3 in);						//�������3ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(vec3* in, const int index);	//���3ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const Tx x, const Tx y,
			const Tx z, vec3 in_result);						//����3ά������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3 in, vec3 result);	//��һ��3ά����������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const Tx in_x, const Tx in_y,
			const Tx in_z, vec3* result,
			const int result_index);							//��һ��3ά���������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3 in,
			vec3* result, const int result_index);				//��һ��3ά����������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(const vec3* in,
			const int in_index,	vec3* result,
			const int result_index);							//��һ��3ά���������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(vec3 first, vec3 second,
			Tx err = 0);										//�ж����������Ƿ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(const vec3 first,
			const vec3 second, vec3 result);					//������3ά�������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2,
			vec3* result, const int result_index);				//������3ά���������е�������ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(const vec3 first,
			const vec3 second, vec3 result);					//������3ά���������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2,
			vec3* result, const int result_index);				//������3ά���������е����������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec3 in);					//��3ά��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(vec3* in, const int index);	//��3ά���������е�ĳ����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(const vec3 first,
			const vec3 second);									//����3ά�����ĵ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx dot(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2);				//����3ά�������������������ĵ������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(const vec3 first,
			const vec3 second, vec3 result);					//������3ά�����Ĳ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void cross(const vec3* first,
			const int index_1,
			const vec3* second,
			const int index_2, vec3* result);					//������3ά����������ĳ���������Ĳ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(const vec3 in);					//��3ά������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(const vec3* in,
			const int index);									//��3ά����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(const vec3 first,
			const vec3 second);									//������3ά����֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle(const vec3* first,
			const int index_1,
			const vec3* second, const int index_2);				//������3ά����������ĳ��������֮��ļнǣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_x(const vec3 in);				//��3ά������x��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_y(const vec3 in);				//��3ά������y��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_z(const vec3 in);				//��3ά������z��֮��ļн� <* �춥�� *>
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoY(const vec3 in);				//��3ά������XoYƽ��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoZ(const vec3 in);				//��3ά������XoZƽ��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_YoZ(const vec3 in);				//��3ά������YoZƽ��֮��ļн�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle_XoY_x(const vec3 in);			//��3ά������XoYƽ���ϵ�ͶӰ��x��֮��ļн� <* ��λ�� *>
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec3 in);					//��һ��3ά����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(vec3* in, const int index);//��һ��3ά����������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(const Tx thi,
			const Tx fri, const vec3 local_z,
			vec3 result_local_x, vec3 result_local_y);			//�ɹ������䷽�����Ԫ���߷������һ���ֲ�����ϵ			
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void localSystem(const vec3 in,
			const vec3 local_z, vec3 result_local_x,
			vec3 result_local_y);								//�ɹ������䷽�����Ԫ���߷������һ���ֲ�����ϵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void projectSystem(const vec3 local_x,
			const vec3 local_y, const vec3 local_z,
			vec3 result_a, vec3 result_b);						//�ɾֲ�����ϵ����ת���������������a��b
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void project(const vec3 a,
			const vec3 b, const vec3 n, const vec3 in,
			vec3 result);										//����a,b�ͷ���n���ɽ���׼����ϵ�е�����ת��Ϊ�ֲ�����ϵ�е�����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(const vec3 in);				//���3ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(const vec3* in,
			const int index);									//���3ά��������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(const vec3* in,
			const int num);										//���3ά������������Ļ
	};

#ifndef NO_SIMPLE

typedef CTVec3v<float>  CTVec3vf;
typedef CTVec3v<double> CTVec3vd;

#endif /* NO_SIMPLE */

//��������

template <typename Tx>
	class CPPTOOLS_TCLASS_API CTCplx
		: public CTNoInherit<CTCplx<Tx> >
	{
	public:
		//�����洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in);						//�����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(Tx* in, int index);			//�������������ĳ��2ά��������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx real, Tx image,
			Tx* in_result);										//����������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, Tx* result);			//��һ������������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_real, Tx in_image,
			Tx* result, int result_index);						//��һ�����������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in,
			Tx* result, int result_index);						//��һ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx* in, int in_index,
			Tx* result, int result_index);						//��һ�����������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, Tx* second,
			Tx* result);										//�������������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//���������������еĸ�����ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, Tx* second,
			Tx* result);										//���������������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(Tx* first, int index_1,
			Tx* second, int index_2,
			Tx* result, int result_index);						//���������������еĸ��������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in);						//������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(Tx* in, int index);			//���������е�ĳ��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(Tx* first, Tx* second,
			Tx* result);										//���������ĳ˷�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(Tx* first, int index_1,
			Tx* second, int index_2, Tx* result);				//�����������������������ĳ˷�����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx exponent, Tx* result);		//��ʵ��Ϊָ����eΪ��������һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx* in, Tx* result);				//�Ը���Ϊָ����eΪ��������һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx* in, int in_index,
			Tx* result, int result_index);						//�Ը���������ĳ������Ϊָ����eΪ��������һ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(Tx* in, Tx* result);		//�����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(Tx* in, int in_index,
			Tx* result, int result_index);						//���������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in);						//������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(Tx* in, int index);				//����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in);					//��һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(Tx* in, int index);		//��һ������������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in);						//�����������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(Tx* in, int index);			//�����������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(Tx* in, int num);			//���������������Ļ
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
		//2Ԫ�洢����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(cplx in);						//�����������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void clear(cplx* in, int index);			//�������������ĳ��2ά��������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx real, Tx image,
			cplx in_result);									//����������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx in, cplx result);			//��һ������������һ��������ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(Tx in_real, Tx in_image,
			cplx* result, int result_index);					//��һ�����������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx in,
			cplx* result, int result_index);					//��һ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void equal(cplx* in, int in_index,
			cplx* result, int result_index);					//��һ�����������е�ĳ������������һ�������е�ĳ��������ֵ����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(cplx first, cplx second,
			cplx result);										//�������������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void add(cplx* first, int index_1,
			cplx* second, int index_2,
			cplx* result, int result_index);					//���������������еĸ�����ӣ���index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(cplx first, cplx second,
			cplx result);										//���������������vec1-vec2
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void sub(cplx* first, int index_1,
			cplx* second, int index_2,
			cplx* result, int result_index);					//���������������еĸ��������vec1-vec2����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(cplx in);					//������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void reverse(cplx* in, int index);		//���������е�ĳ��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(cplx first, cplx second,
			cplx result);										//���������ĳ˷�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void multiply(cplx* first, int index_1,
			cplx* second, int index_2, cplx result);			//�����������������������ĳ˷�����index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(Tx exponent, cplx result);		//��ʵ��Ϊָ����eΪ��������һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(cplx in, cplx result);			//�Ը���Ϊָ����eΪ��������һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void exp(cplx* in, int in_index,
			cplx* result, int result_index);					//�Ը���������ĳ������Ϊָ����eΪ��������һ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(cplx in, cplx result);		//�����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void conjugate(cplx* in, int in_index,
			cplx* result, int result_index);					//���������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(cplx in);						//������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx module(cplx* in, int index);			//����������ĳ��������ģֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(cplx in);					//��һ������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void normalize(cplx* in, int index);		//��һ������������ĳ����������index����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(cplx in);						//�����������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void print(cplx* in, int index);			//�����������Ļ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void printAll(cplx* in, int num);			//���������������Ļ
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

		//��λ��ת��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx angle2Radian(Tx angle);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx radian2Angle(Tx radian);

		//��������
		static inline Tx sumOf(int n, ...);
		static inline Tx averageOf(int n, ...);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx sumOfSquares(Tx a, Tx b);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx difOfSquares(Tx a, Tx b);

		//��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline bool isEqual(const Tx a, const Tx b, const Tx error = (Tx)1e-6);//���������ƱȽ�

		//��������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx compleAngle(Tx angle);//�������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx suppleAngle(Tx angle);//���㲹��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx distance(const Tx* point3_1, const Tx* point3_2);//��������֮��ľ���
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx distance(const ct_point3& point3_1, const ct_point3& point3_2);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void plainCenter(const point3 point_1, const point3 point_2, const point3 point_3, point3 center_point);//������������Ԫ�е�
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline void plainCenter(const point3 point_1, const point3 point_2, const point3 point_3, const point3 point_4, point3 center_point);//�����ı�����Ԫ�е�

		//�ߵ���ѧ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx Integral(const p_Tx_func_Tx func, const Tx x_start, const Tx x_end, const int n = 10000);//һ�ػ���
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx Integral2d(const p_Tx_func_Tx_Tx func, const Tx x_start, const Tx x_end, const Tx y_start, const Tx y_end, const int x_n = 100, const int y_n = 100);//���ػ���
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx sumFunc(const p_Tx_func_i func, const int start, const Tx error = (Tx)1e-3);	//��start�������func������ͣ�ֱ��func<errorʱ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx factorial(const UINT n);//�׳�

		//����ͳ��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx maxOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx minOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx sumOf(const Tx* data, const int n);
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx squareOf(const Tx* data, const int n);//ƽ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx averageOf(const Tx* data, const int n);//��ֵ
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static Tx varianceOf(const Tx* data, const int n);//����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx stdDeviationOf(const Tx* data, const int n);//��׼��
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx stdErrorOf(const Tx* data, const Tx true_value, const int n);//��׼���
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx rootMeanSquareOf(const Tx* data, const int n);//������

		//��������ص���ѧ����
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx steradian(const Tx area_on_sphere, const Tx radius);//��֪��������������
		CPPTOOLS_CLASSFUNC_HOSTDEVICE static inline Tx areaOnSphere(const Tx steradian, const Tx radius);//��֪��������������
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