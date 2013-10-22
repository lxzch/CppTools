#pragma once
#ifndef CTUNIFORM_H
#define CTUNIFORM_H

#define _USI( what )				using what;
#define _USN( what )				using namespace what;

//将std的宏定义统一到CT中
#define _STD__						_STD
#define _USN_STD					_USN( std );

//命名空间CppTools
#define _CT_BEGIN					namespace CppTools {
#define _CT_END						}
#define _CT							::CppTools
#define _CT__						_CT::
#define _USN_CT						_USN( CppTools );

//命名空间CppTools::CTData
#define _CT_DATA_BEGIN				_CT_BEGIN namespace CTData {
#define _CT_DATA_END				} _CT_END
#define _CT_DATA					::CppTools::CTData
#define _CT_DATA__					_CT_DATA::
#define _USN_CT_DATA				_USN( CppTools::CTData )

//命名空间CppTools::CTMath
#define _CT_MATH_BEGIN				_CT_BEGIN namespace CTMath {
#define _CT_MATH_END				} _CT_END
#define _CT_MATH					::CppTools::CTMath
#define _CT_MATH__					_CT_MATH::
#define _USN_CT_MATH				_USN( CppTools::CTMath )

//命名空间CppTools::CTMemory
#define _CT_MEMORY_BEGIN			_CT_BEGIN namespace CTMemory {
#define _CT_MEMORY_END				} _CT_END
#define _CT_MEMORY					::CppTools::CTMEMORY
#define _CT_MEMORY__				_CT_MEMORY::
#define _USN_CT_MEMORY				_USN( CppTools::CTMemory )

//命名空间CppTools::CTDate
#define _CT_DATE_BEGIN				_CT_BEGINE namespace CTDate {
#define _CT_DATE_END				} _CT_END
#define _CT_DATE					::CppTools::CTDate
#define _CT_DATE__					_CT_DATE::
#define _USN_CT_DATE				_USN( CppTools::CTDate );

//命名空间CppTools::CTException
#define _CT_EXC_BEGIN				_CT_BEGIN namespace CTException {
#define _CT_EXC_END					} _CT_END
#define _CT_EXC						_CT::CTException
#define _CT_EXC__					_CT_EXC::
#define _USN_CT_EXC					_USN( CppTools::CTException )

//命名空间CppTools::CTAlgorithm
#define _CT_ALGORITHM_BEGIN			_CT_BEGIN namespace CTAlgorithm {
#define _CT_ALGORITHM_END			} _CT_END
#define _CT_ALGORITHM				::CppTools::CTAlgorithm
#define _CT_ALGORITHM__				_CT_ALGORITHM::
#define _USN_CT_ALGORITHM			_USN( CppTools::CTAlgorithm )

//命名空间CppTools::CTGeographic
#define _CT_GEOGRAPHIC_BEGIN		_CT_BEGIN namespace CTGeographic {
#define _CT_GEOGRAPHIC_END			} _CT_END
#define _CT_GEOGRAPHIC				::CppTools::CTGeographic
#define _CT_GEOGRAPHIC__			_CT_GEOGRAPHIC::
#define _USN_CT_GEOGRAPHIC			_USN( CppTools::CTGeographic )

//命名空间CppTools::CTTime
#define _CT_TIME_BEGIN				_CT_BEGIN namespace CTTime {
#define _CT_TIME_END				} _CT_END
#define _CT_TIME					::CppTools::CTTime
#define _CT_TIME__					_CT_TIME::
#define _USN_CT_TIME				_USN( CppTools::CTTime )

//命名空间CppTools::CTWindows
#define _CT_WINDOWS_BEGIN			_CT_BEGIN namespace CTWindows {
#define _CT_WINDOWS_END				} _CT_END
#define _CT_WINDOWS					::CppTools::CTWindows
#define _CT_WINDOWS__				_CT_WINDOWS::
#define _USN_CT_WINDOWS				_USN( CppTools::CTWindows )

//命名空间CppTools::CTGraphic
#define _CT_GRAPHIC_BEGIN			_CT_BEGIN namespace CTGraphic {
#define _CT_GRAPHIC_END				} _CT_END
#define _CT_GRAPHIC					::CppTools::CTGraphic
#define _CT_GRAPHIC__				_CT_GRAPHIC::
#define _USN_CT_GRAPHIC				_USN( CppTools::CTGraphic )




//子空间

//命名空间CppTools::CTData::CTStr
#define _CT_STR_BEGIN				_CT_DATA_BEGIN namespace CTStr {
#define _CT_STR_END					} _CT_DATA_END
#define _CT_STR						_CT_DATA::CTStr
#define _CT_STR__					_CT_STR::
#define _USN_CT_STR					_USN( CppTools::CTData::CTStr )

#endif