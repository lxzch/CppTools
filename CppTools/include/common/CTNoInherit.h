#pragma once
#ifndef CTNOINHERIT_H
#define CTNOINHERIT_H

#include <common\CTObject.h>

_CT_BEGIN

template <typename Tx>
	class CTNoInstance
		//���дӴ���̳е����� <! ��ֹ !> ��ʵ����
	{
#ifdef _DEBUG
		//Debugʱ������Ƿ�ᱻʵ����
	private:
		explicit CTNoInstance();
		explicit CTNoInstance(const CppTools::CTNoInstance<Tx>&);
#else
		//Releaseʱ�����ټ�飬���Ա��������Ż�
#endif /* _DEBUG */
	};

template <typename Tx>
	class CTNoInherit
		: private CTNoInstance<Tx>
		//���дӴ���̳е����� <! ��ֹ !> ���̳�
	{
#ifdef _DEBUG
		friend typename Tx;
#else
#endif /* _DEBUG */
	};

_CT_END

#endif /* CTNoInherit.h */