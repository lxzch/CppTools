#pragma once
#ifndef CTGEOGRAPHIC_H
#define CTGEOGRAPHIC_H

#include <CTData>
#include <exception\CTDataException.h>

_CT_GEOGRAPHIC_BEGIN

template <typename Tx>
struct CPPTOOLS_TYPE_API CTGeoCoordSystem_r
{
	CTGeoCoordSystem_r(const Tx longitude = 0, const Tx latitude = 0)
		: longitude(longitude), latitude(latitude)
	{
	}
	Tx	longitude,	//经度
		latitude;	//纬度
};

template <typename Tx>
struct CPPTOOLS_TYPE_API CTSunPositionFromEarth
{
	CTSunPositionFromEarth(const Tx theta = 0, const Tx phi = 0)
		: theta(theta), phi(phi)
	{
	}
	Tx	theta,		//天顶角
		phi;		//方位角
};

template <typename Tx>
struct CPPTOOLS_TYPE_API CTGeoCoordSystem_a
{
	CTGeoCoordSystem_a(const CppTools::CTData::CTAngle<Tx>& longitude, const CppTools::CTData::CTAngle<Tx>& latitude)
		: longitude(longitude), latitude(latitude)
	{
	}
	CTGeoCoordSystem_a(const int longitude_degree = 0, const int longitude_minute = 0, const Tx longitude_second = 0,
		const int latitude_degree = 0, const int latitude_minute = 0, const Tx latitude_second = 0)
		: longitude(longitude_degree, longitude_minute, longitude_second), latitude(latitude_degree, latitude_minute, latitude_second)
	{
	}
	CppTools::CTData::CTAngle<Tx>	longitude,	//经度
		latitude;								//维度
};

#ifndef NO_SIMPLE

typedef CTGeoCoordSystem_r<float>	CTGCSrf;
typedef CTGeoCoordSystem_r<double>	CTGCSrd;
typedef CTGeoCoordSystem_a<float>	CTGCSaf;
typedef CTGeoCoordSystem_a<double>	CTGCSad;
typedef CTGCSaf CTGCS;

#endif /* NO_SIMPLE */

bool CPPTOOLS_TFUNC_API CheckAngle(int degree, int minute, float second);
bool CPPTOOLS_TFUNC_API CheckAngle(int degree, int minute, double second);

inline bool CPPTOOLS_INLINEFUNC_API CheckAngle(CppTools::CTData::CTAnglef& angle)
{
	return CheckAngle(angle.degree, angle.minute, angle.second);
}
inline bool CPPTOOLS_INLINEFUNC_API CheckAngle(CppTools::CTData::CTAngled& angle)
{
	return CheckAngle(angle.degree, angle.minute, angle.second);
}

_CT_GEOGRAPHIC_END

#endif /* CTGeographic.h */