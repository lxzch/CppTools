#include "stdafx.h"
#include <core\CTPhysics.h>

template <typename Tx>
inline Tx TFunc_Gravity(Tx latitude)
{
	return (Tx)9.78049 * ((Tx)1.0 + (Tx)0.005288 * sin(latitude) - (Tx)0.000006 * sin(latitude));
}

float CppTools::CTPhysics::Gravityf(float latitude)
{
	return TFunc_Gravity(latitude);
}

double CppTools::CTPhysics::Gravity(double latitude)
{
	return TFunc_Gravity(latitude);
}

float CppTools::CTPhysics::BlackBodyRadiationLambda(float lambda, float temperature)
{
	return 1.0e20f * (ct_c1_f / (pow(lambda, 5.0f) * (exp(ct_c2__um_f / (lambda * temperature)) - 1.0f)));
}

double CppTools::CTPhysics::BlackBodyRadiationLambda(double lambda, double temperature)
{
	return 1.0e20 * (ct_c1 / (pow(lambda, 5.0) * (exp(ct_c2__um / (lambda * temperature)) - 1.0)));
}

double sea_temperature = 20.0;

template <typename Tx>
inline Tx TFunc_BlackBodyRadiationLambdaInner(Tx lambda)
{
	return (2 * (Tx)ct_pi * (Tx)ct_h * (Tx)ct_c * (Tx)ct_c * pow(lambda, (Tx)-5.0)) / (exp((Tx)ct_h * (Tx)ct_c /(lambda * (Tx)ct_k * (Tx)sea_temperature)) - (Tx)1.0);
}

float CppTools::CTPhysics::BlackBodyRadiation(float lambda_start, float lambda_end, float temperature)
{
	sea_temperature = temperature;
	return CTMath::CTCalculate<float>::Integral(TFunc_BlackBodyRadiationLambdaInner<float>, lambda_start, lambda_end);
}

double CppTools::CTPhysics::BlackBodyRadiation(double lambda_start, double lambda_end, double temperature)
{
	sea_temperature = temperature;
	return CTMath::CTCalculate<double>::Integral(TFunc_BlackBodyRadiationLambdaInner<double>, lambda_start, lambda_end);
}

float CppTools::CTPhysics::AveragerEmissionRateOfSea(float w)
{
	return 0.98f * (1.0f - (powf(1.0f - cosf(w), 5.0f)));
}

double CppTools::CTPhysics::AveragerEmissionRateOfSea(double w)
{
	return 0.98 * (1.0 - (pow(1.0f - cos(w), 5.0)));
}

float CppTools::CTPhysics::FresnelReflectionCoefficientv(const float n1, const float n2, const float cos_theta)
{
	float t1, t2;
	t1 = n2 * cos_theta;
	t2 = n1 * sqrt(1 - (n1 * n1) * (1 - cos_theta * cos_theta) / (n2 * n2));
	return ((t1 - t2) / (t1 + t2));
}

float CppTools::CTPhysics::FresnelReflectionCoefficienth(const float n1, const float n2, const float cos_theta)
{
	float t1, t2;
	t1 = n1 * cos_theta;
	t2 = n2 * sqrt(1 - (n1 * n1) * (1 - cos_theta * cos_theta) / (n2 * n2));
	return ((t1 - t2) / (t1 + t2));
}

float CppTools::CTPhysics::SeaFresnelReflectionCoefficientv(const float n2, const float cos_theta)
{
	float t1, t2;
	t1 = n2 * cos_theta;
	t2 = sqrt(1 - (1 - cos_theta * cos_theta) / (n2 * n2));
	return ((t1 - t2) / (t1 + t2));
}

float CppTools::CTPhysics::SeaFresnelReflectionCoefficienth(const float n2, const float cos_theta)
{
	float t1, t2;
	t1 = cos_theta;
	t2 = n2 * sqrt(1 - (1 - cos_theta * cos_theta) / (n2 * n2));
	return ((t1 - t2) / (t1 + t2));
}