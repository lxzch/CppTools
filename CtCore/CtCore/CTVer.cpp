#include "stdafx.h"
#include <common\CTVer.h>

//CppTools�汾��
#define CT_VERSION "1"
#define CT_SECOND_VERSION "01"

std::string CppTools::Ver()
{
	std::string inf;
	inf += CT_VERSION;
	inf += ".";
	inf += CT_SECOND_VERSION;	
	return inf;
}