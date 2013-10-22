#pragma once
#ifndef CTPHYSICS_H
#define CTPHYSICS_H

#include <CTMath>

//光学物理量
#define CT_C_C					(299792458.0)
#define CT_C_C_F				(299792458.0f)
#define CT_C_N_WATER			(1.333)
#define CT_C_N_WATER_F			(1.333f)

const double	ct_c			= CT_C_C;		//真空中光速  m/s2
const float		ct_c_f			= CT_C_C_F;
const double	ct_n_water		= CT_C_N_WATER;			//水的折射率  -
const float		ct_n_water_f	= CT_C_N_WATER_F;

//电磁学物理量
const double	ct_u0			= 4.0e-7;			//真空磁导率
const float		ct_u0_f			= 4.0e-7f;
const double	ct_ep0			= 8.854187817e-12;	//真空介电常数
const float		ct_ep0_f		= 8.854187817e-12f;
const double	ct_e			= 1.60217733e-19;	//电荷常量
const float		ct_e_f			= 1.60217733e-19f;
const double	ct_me			= 0.91093897;		//电子质量x
const float		ct_me_f			= 0.91093897f;
const double	ct_e_me			= 1.75881962e11;	//荷质比
const float		ct_e_me_f		= 1.75881962e11f;
const double	ct_mp			= 1.6726231;		//质子质量x
const float		ct_mp_f			= 1.6726231f;

//力学物理量
const double	ct_g			= 9.80;				//重力经典值
const float		ct_g_f			= 9.80f;
const double	ct_G			= 6.67259e-11;		//引力常量
const float		ct_G_f			= 6.67259e-11f;


//量子物理量
const double	ct_h			= 6.6260755e-34;	//普朗克常量  W·s2
const float		ct_h_f			= 6.6260755e-34f;

//热学物理量
const double	ct_abs_zero		= 273.15;			//摄氏0°在绝对温标下的温度值  K
const float		ct_abs_zero_f	= 273.15f;
const double	ct_atm			= 101325.0;			//标准大气压 Pa
const float		ct_atm_f		= 101325.0f;
const double	ct_NA			= 6.0221367;		//阿伏伽德罗常数x
const float		ct_NA_f			= 6.0221367f;
const double	ct_R			= 8.314510;			//气体常量x
const float		ct_R_f			= 8.314510f;
const double	ct_k			= 1.380658e-23;			//玻尔兹曼常量  J/K
const float		ct_k_f			= 1.380658e-23f;
const double	ct_c1			= 2 * ct_pi * ct_h * ct_c * ct_c;			//第一辐射常数  W·m2（瓦·平方米）
const float		ct_c1_f			= 2 * ct_pi_f * ct_h_f * ct_c_f * ct_c_f;
const double	ct_c2			= ct_c * ct_h / ct_k;						//第二辐射常数  m·K（米·开尔文）
const float		ct_c2_f			= ct_c_f * ct_h_f / ct_k_f;
const double	ct_c2__um		= ct_c2 * ct_m__um;							//第二辐射常数  μm·K（微米·开尔文）
const float		ct_c2__um_f		= ct_c2_f * ct_m__um_f;

namespace CppTools
{
	namespace CTPhysics
	{
		CPPTOOLS_API float Gravityf(float latitude);//返回某纬度的重力加速度
		CPPTOOLS_API double Gravity(double latitude);

		CPPTOOLS_API float BlackBodyRadiationLambda(float lambda, float temperature);//黑体辐射  单位W/(cm2·μm)

		CPPTOOLS_API float BlackBodyRadiation(float lambda_start, float lambda_end, float temperature);//返回某一（波段乘以温度）的黑体辐射
		CPPTOOLS_API float AveragerEmissionRateOfSea(float w);//海面平均发射率

		CPPTOOLS_API float FresnelReflectionCoefficientv(const float n1, const float n2, const float cos_theta);
		CPPTOOLS_API float FresnelReflectionCoefficienth(const float n1, const float n2, const float cos_theta);
		CPPTOOLS_API float SeaFresnelReflectionCoefficientv(const float n2, const float cos_theta);
		CPPTOOLS_API float SeaFresnelReflectionCoefficienth(const float n2, const float cos_theta);

		CPPTOOLS_API double BlackBodyRadiationLambda(double lambda, double temperature);
		CPPTOOLS_API double BlackBodyRadiation(double lambda_start, double lambda_end, double temperature = 20.0);
		CPPTOOLS_API double AveragerEmissionRateOfSea(double w);
	}
}

#endif