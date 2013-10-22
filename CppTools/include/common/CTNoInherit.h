#pragma once
#ifndef CTNOINHERIT_H
#define CTNOINHERIT_H

#include <common\CTObject.h>

_CT_BEGIN

template <typename Tx>
	class CTNoInstance
		//所有从此类继承的子类 <! 禁止 !> 被实例化
	{
#ifdef _DEBUG
		//Debug时，检查是否会被实例化
	private:
		explicit CTNoInstance();
		explicit CTNoInstance(const CppTools::CTNoInstance<Tx>&);
#else
		//Release时，不再检查，可以被编译器优化
#endif /* _DEBUG */
	};

template <typename Tx>
	class CTNoInherit
		: private CTNoInstance<Tx>
		//所有从此类继承的子类 <! 禁止 !> 被继承
	{
#ifdef _DEBUG
		friend typename Tx;
#else
#endif /* _DEBUG */
	};

_CT_END

#endif /* CTNoInherit.h */