#pragma once
#ifndef CTCONSTANT_H
#define CTCONSTANT_H

#define CT_MATH_SQUARE( number )		( number * number )

//宏定义
//常用常数
#define CT_PI							( 3.1415926535897931e+0 )
#define CT_PI_F							( 3.141592654f )
#define CT_2PI							( CT_PI * 2.0 )
#define CT_2PI_F						( CT_PI_F * 2.0f )
#define CT_PI_2							( CT_PI * 0.5 )
#define CT_PI_2_F						( CT_PI_F * 0.5f )
#define CT_SQRT_1_2						( 7.0710678118654757e-1 )
#define CT_SQRT_1_2_F					( 0.707106781f)
#define CT_SQRT_2						( 1.4142135623730951e+0 )
#define CT_SQRT_2_F						( 1.414213562f )

//进制转换
#define CT_TR_10						( 10.0 )
#define CT_TR_10_F						( 10.0f )
#define CT_TR_01						( 0.1 )
#define CT_TR_01_F						( 0.1f )

#define CT_TR_100						( 100.0 )
#define CT_TR_100_F						( 100.0f )
#define CT_TR_001						( 0.01 )
#define CT_TR_001_F						( 0.01f )


#define CT_TR_1000						( 1000.0 )
#define CT_TR_1000_F					( 1000.0f )
#define CT_TR_0001						( 0.001 )
#define CT_TR_0001_F					( 0.001f )

//单位转换
#define CT_TR_KM__M						CT_TR_1000
#define CT_TR_M__MM						CT_TR_1000
#define CT_TR_MM__UM					CT_TR_1000
#define CT_TR_UM__NM					CT_TR_1000
#define CT_TR_NM__PM					CT_TR_1000
#define CT_TR_M__CM						CT_TR_100
#define CT_TR_CM__MM					CT_TR_10
#define CT_TR_KM__M_F					CT_TR_1000_F
#define CT_TR_M__MM_F					CT_TR_1000_F
#define CT_TR_MM__UM_F					CT_TR_1000_F
#define CT_TR_UM__NM_F					CT_TR_1000_F
#define CT_TR_NM__PM_F					CT_TR_1000_F
#define CT_TR_M__CM_F					CT_TR_100_F
#define CT_TR_CM__MM_F					CT_TR_10_F

#define CT_TR_PM__NM					CT_TR_0001
#define CT_TR_NM__UM					CT_TR_0001
#define CT_TR_UM__MM					CT_TR_0001
#define CT_TR_MM__M						CT_TR_0001
#define CT_TR_M__KM						CT_TR_0001
#define CT_TR_MM__CM					CT_TR_01
#define CT_TR_CM__M						CT_TR_001
#define CT_TR_PM__NM_F					CT_TR_0001_F
#define CT_TR_NM__UM_F					CT_TR_0001_F
#define CT_TR_UM__MM_F					CT_TR_0001_F
#define CT_TR_MM__M_F					CT_TR_0001_F
#define CT_TR_M__KM_F					CT_TR_0001_F
#define CT_TR_MM__CM_F					CT_TR_01_F
#define CT_TR_CM__M_F					CT_TR_001_F

#define CT_TR_M__UM						( CT_TR_M__MM * CT_TR_MM__UM )
#define CT_TR_M__NM						( CT_TR_M__UM * CT_TR_UM__NM )
#define CT_TR_M__PM						( CT_TR_M__NM * CT_TR_NM__PM )
#define CT_TR_M__UM_F					( CT_TR_M__MM_F * CT_TR_MM__UM_F )
#define CT_TR_M__NM_F					( CT_TR_M__UM_F * CT_TR_UM__NM_F )
#define CT_TR_M__PM_F					( CT_TR_M__NM_F * CT_TR_NM__PM_F )

#define CT_TR_M2__CM2					CT_MATH_SQUARE( CT_TR_M__CM )
#define CT_TR_CM2__M2					CT_MATH_SQUARE( CT_TR_CM__M )
#define CT_TR_M2__CM2_F					CT_MATH_SQUARE( CT_TR_M__CM_F )
#define CT_TR_CM2__M2_F					CT_MATH_SQUARE( CT_TR_CM__M_F )

//角度转换
#define CT_TR_ANGLE__RADIUS				( CT_PI / 180.0 )
#define CT_TR_RADIUS__ANGLE				( 180.0 / CT_PI )
#define CT_TR_ANGLE__RADIUS_F			( CT_PI_F / 180.0f )
#define CT_TR_RADIUS__ANGLE_F			( 180.0f / CT_PI_F )

#define CT_TR_ANG__RAD( angle )			( angle * CT_TR_ANGLE__RADIUS )
#define CT_TR_RAD__ANG( radius )		( radius * CT_TR_RADIUS__ANGLE )
#define CT_TR_ANG__RAD_F( angle )		( angle * CT_TR_ANGLE__RADIUS_F )
#define CT_TR_RAD__ANG_F( radius )		( radius * CT_TR_RADIUS__ANGLE_F )

#ifndef CCU_SUPPORT
//常量定义
//常用常数
const double ct_pi						= CT_PI;
const float ct_pi_f						= CT_PI_F;
const double ct_sqrt_1_2				= CT_SQRT_1_2;
const float ct_sqrt_1_2_f				= CT_SQRT_1_2_F;
const double ct_sqrt_2					= CT_SQRT_2;
const float ct_sqrt_2_f					= CT_SQRT_2_F;

//进制转换
const double ct_10						= CT_TR_10;
const float ct_10_f						= CT_TR_10_F;
const double ct_01						= CT_TR_01;
const float ct_01_f						= CT_TR_01_F;

const double ct_100						= CT_TR_100;
const float ct_100_f					= CT_TR_100_F;
const double ct_001						= CT_TR_001;
const float ct_001_f					= CT_TR_001_F;

const double ct_1000					= CT_TR_1000;
const float ct_1000_f					= CT_TR_1000_F;
const double ct_0001					= CT_TR_0001;
const float ct_0001_f					= CT_TR_0001_F;

const double ct_km__m					= CT_TR_KM__M;
const double ct_m__mm					= CT_TR_M__MM;
const double ct_mm__um					= CT_TR_MM__UM;
const double ct_um__nm					= CT_TR_UM__NM;
const double ct_nm__pm					= CT_TR_NM__PM;
const double ct_m__cm					= CT_TR_M__CM;
const double ct_cm__mm					= CT_TR_CM__MM;

const float ct_km__m_f					= CT_TR_KM__M_F;
const float ct_m__mm_f					= CT_TR_M__MM_F;
const float ct_mm__um_f					= CT_TR_MM__UM_F;
const float ct_um__nm_f					= CT_TR_UM__NM_F;
const float ct_nm__pm_f					= CT_TR_NM__PM_F;
const float ct_m__cm_f					= CT_TR_M__CM_F;
const float ct_cm__mm_f					= CT_TR_CM__MM_F;

const double ct_pm__nm					= CT_TR_PM__NM;
const double ct_nm__um					= CT_TR_NM__UM;
const double ct_um__mm					= CT_TR_UM__MM;
const double ct_mm__m					= CT_TR_MM__M;
const double ct_m__km					= CT_TR_M__KM;
const double ct_mm__cm					= CT_TR_MM__CM;
const double ct_cm__m					= CT_TR_CM__M;

const float ct_pm__nm_f					= CT_TR_PM__NM_F;
const float ct_nm__um_f					= CT_TR_NM__UM_F;
const float ct_um__mm_f					= CT_TR_UM__MM_F;
const float ct_mm__m_f					= CT_TR_MM__M_F;
const float ct_m__km_f					= CT_TR_M__KM_F;
const float ct_mm__cm_f					= CT_TR_MM__CM_F;
const float ct_cm__m_f					= CT_TR_CM__M_F;

const double ct_m__um					= CT_TR_M__UM;
const double ct_m__nm					= CT_TR_M__NM;
const double ct_m__pm					= CT_TR_M__PM;

const float ct_m__um_f					= CT_TR_M__UM_F;
const float ct_m__nm_f					= CT_TR_M__NM_F;
const float ct_m__pm_f					= CT_TR_M__PM_F;

const double ct_m2__cm2					= CT_TR_M2__CM2;
const double ct_cm2__m2					= CT_TR_CM2__M2;
const float ct_m2__cm2_f				= CT_TR_M2__CM2_F;
const float ct_cm2__m2_f				= CT_TR_CM2__M2_F;

const double ct_ang__rad				= CT_TR_ANGLE__RADIUS;
const float ct_ang__rad_f				= CT_TR_ANGLE__RADIUS_F;

const double ct_rad__ang				= CT_TR_RADIUS__ANGLE;
const float ct_rad__ang_f				= CT_TR_RADIUS__ANGLE_F;

const double ct_2pi						= CT_2PI;
const float ct_2pi_f					= CT_2PI_F;

#endif /* CCU_SUPPORT */

#endif /* CTConstant */