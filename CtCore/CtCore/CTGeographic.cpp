#include "stdafx.h"
#include <CTGeo>

bool CppTools::CTGeographic::CheckAngle(int degree, int minute, float second)
{
	if(degree < -180 || degree > 180 ||
	   minute < 0 || minute >= 60 ||
	   second < 0.0f || second >= 60.0f)
	   throw CppTools::CTException::CTDataException::CTAngleException(degree, minute, second);
	return true;
}

bool CppTools::CTGeographic::CheckAngle(int degree, int minute, double second)
{
	if(degree < -180 || degree > 180 ||
	   minute < 0 || minute >= 60 ||
	   second < 0.0 || second >= 60.0)
	   throw CppTools::CTException::CTDataException::CTAngleException(degree, minute, second);
	return true;
}