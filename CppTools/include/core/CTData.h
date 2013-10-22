#pragma once
#ifndef CTDATA_H
#define CTDATA_H

#include <common\CTNoInherit.h>
#include <common\CTObject.h>
#include <CTBase>
#include <sstream>

_CT_DATA_BEGIN

template <typename Tx>
struct CPPTOOLS_TYPE_API CTMaxMin
{
	Tx max, min;
};

template <typename Tx>
struct CPPTOOLS_TYPE_API CTUpperLower
{
	Tx upper_limit, lower_limit;
};

typedef CTMaxMin<UINT>			CTMaxMinu;
typedef CTMaxMin<int>			CTMaxMini;
typedef CTMaxMin<long>			CTMaxMinl;
typedef CTMaxMin<float>			CTMaxMinf;
typedef CTMaxMin<double>		CTMaxMind;

typedef CTUpperLower<UINT>		CTUpperLoweru;
typedef CTUpperLower<int>		CTUpperLoweri;
typedef CTUpperLower<long>		CTUpperLowerl;
typedef CTUpperLower<float>		CTUpperLowerf;
typedef CTUpperLower<double>	CTUpperLowerd;

template <typename Tx>
class CPPTOOLS_TCLASS_API CTDataBase
	: public CppTools::CTData::CTObject
{
public:
	CTDataBase(const Tx& data = 0);
	~CTDataBase();
	std::string toString();
	const std::string toString() const;
	Tx getData() const;
	void setData(const Tx& new_data);
	const CTDataBase<Tx>& operator =(const CTDataBase& right);
	const CTDataBase<Tx>& operator +(const CTDataBase& right);
	const CTDataBase<Tx>& operator -(const CTDataBase& right);
	const CTDataBase<Tx>& operator *(const CTDataBase& right);
	const CTDataBase<Tx>& operator /(const CTDataBase& right);
	CTDataBase<Tx>& operator ++();
	CTDataBase<Tx> operator ++(int);
	CTDataBase<Tx>& operator --();
	CTDataBase<Tx> operator --(int);

protected:
	Tx data;
};

template <typename Tx,
	int div1 = 16,
	int div2 = 16,
	int div3 = 16>
class CPPTOOLS_TCLASS_API CTArrayBase
	: public CppTools::CTNoInherit<CTArrayBase<Tx, div1, div2, div3> >
{
public:
	typedef Tx p_Tx1[1];
	typedef Tx p_Tx2[2];
	typedef Tx p_Tx3[3];
	typedef Tx p_Tx1d[div1];
	typedef Tx p_Tx2d[div1][div2];
	typedef Tx p_Tx3d[div1][div2][div3];
};

template <typename Treturn = int,
	typename Tu = int,
	typename Tv = int,
	typename Tw = int,
	typename Tx = int,
	typename Ty = int,
	typename Tz = int>
class CPPTOOLS_TCLASS_API CTFuncBase
	: public CppTools::CTNoInherit<CTFuncBase<Treturn, Tu, Tv, Tw, Tx, Ty, Tz> >
{
public:
	typedef Treturn (*p_TFunc)();
	typedef Treturn (*p_TFunc_u)(Tu);
	typedef Treturn (*p_TFunc_uv)(Tu, Tv);
	typedef Treturn (*p_TFunc_uvw)(Tu, Tv, Tw);
	typedef Treturn (*p_TFunc_uvwx)(Tu, Tv, Tw, Tx);
	typedef Treturn (*p_TFunc_uvwxy)(Tu, Tv, Tw, Tx, Ty);
	typedef Treturn (*p_TFunc_uvwxyz)(Tu, Tv, Tw, Tx, Ty, Tz);
};

template <typename Tx>
class CPPTOOLS_TCLASS_API CTDataFunc
	: public CppTools::CTNoInherit<CTDataFunc<Tx> >
{
public:
	static inline Tx va_arg_in(va_list* ap);
};

typedef CTDataFunc<float>	CTDataFf;
typedef CTDataFunc<double>	CTDataFd;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTPoint2
{
	CTPoint2(const Tx x = 0, const Tx y = 0)
		: x(x), y(y)
	{
	}
	Tx x, y;
};

typedef CTPoint2<UINT>		CTPoint2u;
typedef CTPoint2<int>		CTPoint2i;
typedef CTPoint2<long>		CTPoint2l;
typedef CTPoint2<float>		CTPoint2f;
typedef CTPoint2<double>	CTPoint2d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTPoint3
{
	CTPoint3(const Tx x = 0, const Tx y = 0, const Tx z = 0)
		: x(x), y(y), z(z)
	{
	}
	Tx x, y, z;
};

typedef CTPoint3<UINT>		CTPoint3u;
typedef CTPoint3<int>		CTPoint3i;
typedef CTPoint3<long>		CTPoint3l;
typedef CTPoint3<float>		CTPoint3f;
typedef CTPoint3<double>	CTPoint3d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTLine1
{
	CTLine1(const Tx start = 0, const Tx end = 0)
		: start(start), end(end)
	{
	}
	Tx start, end;
};

typedef CTLine1<UINT>		CTLine1u;
typedef CTLine1<int>		CTLine1i;
typedef CTLine1<long>		CTLine1l;
typedef CTLine1<float>		CTLine1f;
typedef CTLine1<double>		CTLine1d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTLine2
{
	CTLine2()
		: start(), end()
	{
	}
	CTLine2(const CTPoint2<Tx>& start, const CTPoint2<Tx>& end)
		: start(start), end(end)
	{
	}
	CTPoint2<Tx> start, end;
};

typedef CTLine2<UINT>		CTLine2u;
typedef CTLine2<int>		CTLine2i;
typedef CTLine2<long>		CTLine2l;
typedef CTLine2<float>		CTLine2f;
typedef CTLine2<double>		CTLine2d;


template<typename Tx>
struct CPPTOOLS_TYPE_API CTLine3
{
	CTLine3(const CTPoint3<Tx>& start, const CTPoint3<Tx>& end)
		: start(start), end(end)
	{
	}
	CTPoint3<Tx> start, end;
};

typedef CTLine3<UINT>		CTLine3u;
typedef CTLine3<int>		CTLine3i;
typedef CTLine3<long>		CTLine3l;
typedef CTLine3<float>		CTLine3f;
typedef CTLine3<double>		CTLine3d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTSize2
{
	CTSize2(const Tx length = 0, const Tx width = 0)
		: width(width), height(height)
	{
	}
	Tx width, height;
};

typedef CTSize2<UINT>			CTSize2u;
typedef CTSize2<int>			CTSize2i;
typedef CTSize2<long>			CTSize2l;
typedef CTSize2<float>			CTSize2f;
typedef CTSize2<double>			CTSize2d;

		template<typename Tx>
struct CPPTOOLS_TYPE_API CTRect2
{
	CTRect2(const Tx left_x = 0, const Tx left_y = 0, const Tx right_x = 0, const Tx right_y = 0)
		: left(left_x, left_y), right(right_x, right_y)
	{
	}
	CTPoint2<Tx> left, right;
};

typedef CTRect2<UINT>		CTRect2u;
typedef CTRect2<int>		CTRect2i;
typedef CTRect2<long>		CTRect2l;
typedef CTRect2<float>		CTRect2f;
typedef CTRect2<double>		CTRect2d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTRect3
{
	CTPoint3<Tx> left_top, left_bottom, right_top, right_bottom;
};

typedef CTRect3<UINT>		CTRect3u;
typedef CTRect3<int>		CTRect3i;
typedef CTRect3<long>		CTRect3l;
typedef CTRect3<float>		CTRect3f;
typedef CTRect3<double>		CTRect3d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTColor3
{
	CTColor3(const Tx r = 0, const Tx g = 0, const Tx b = 0)
		: red(r), green(g), blue(b)
	{
	}
	Tx red, green, blue;
};

typedef CTColor3<UINT>			CTColor3u;
typedef CTColor3<int>			CTColor3i;
typedef CTColor3<long>			CTColor3l;
typedef CTColor3<float>			CTColor3f;
typedef CTColor3<double>		CTColor3d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTColor4
{
	CTColor4(const Tx r = 0, const Tx g = 0, const Tx b = 0, const Tx a = 0)
		: red(r), green(g), blue(b), alpha(a)
	{
	}
	Tx red, green, blue, alpha;
};

typedef CTColor4<UINT>			CTColor4u;
typedef CTColor4<int>			CTColor4i;
typedef CTColor4<long>			CTColor4l;
typedef CTColor4<float>			CTColor4f;
typedef CTColor4<double>		CTColor4d;

template<typename Tx>
struct CPPTOOLS_TYPE_API CTAngle
{
	CTAngle(const int degree, const int minute, const Tx second)
		: degree(degree), minute(minute), second(second)
	{
	}
	int   degree, //∂»
		  minute; //∑÷
	Tx	  second; //√Î
};

typedef CTAngle<float>			CTAnglef;
typedef CTAngle<double>			CTAngled;

_CT_DATA_END

#include <core\CTData.tpc>

typedef CppTools::CTData::CTDataBase<int>										CTInt;
typedef CppTools::CTData::CTDataBase<UINT>										CTUInt;
typedef CppTools::CTData::CTDataBase<char>										CTChar;
typedef CppTools::CTData::CTDataBase<UCHAR>										CTUChar;
typedef CppTools::CTData::CTDataBase<long>										CTLong;
typedef CppTools::CTData::CTDataBase<ULONG>										CTULong;
typedef CppTools::CTData::CTDataBase<float>										CTFloat;
typedef CppTools::CTData::CTDataBase<double>									CTDouble;

typedef CppTools::CTData::CTArrayBase<float>::p_Tx2								CTCplxsf;
typedef CppTools::CTData::CTArrayBase<float>::p_Tx2								CTVec2sf;
typedef CppTools::CTData::CTArrayBase<float>::p_Tx2								CTPoint2sf;
typedef CppTools::CTData::CTArrayBase<float>::p_Tx3								CTVec3sf;
typedef CppTools::CTData::CTArrayBase<float>::p_Tx3								CTPoint3sf;

typedef CppTools::CTData::CTArrayBase<double>::p_Tx2							CTCplxsd;
typedef CppTools::CTData::CTArrayBase<double>::p_Tx2							CTVec2sd;
typedef CppTools::CTData::CTArrayBase<double>::p_Tx2							CTPoint2sd;
typedef CppTools::CTData::CTArrayBase<double>::p_Tx3							CTVec3sd;
typedef CppTools::CTData::CTArrayBase<double>::p_Tx3							CTPoint3sd;

typedef CppTools::CTData::CTFuncBase<void>::p_TFunc								CTFunc_v_v;
typedef CppTools::CTData::CTFuncBase<void, int, int>::p_TFunc_uv				CTFunc_v_ii;
typedef CppTools::CTData::CTFuncBase<void, UCHAR, int, int>::p_TFunc_uvw		CTFunc_v_uii;
typedef CppTools::CTData::CTFuncBase<void, int, int, int, int>::p_TFunc_uvwx	CTFunc_v_iiii;

#endif /* CTData.h */