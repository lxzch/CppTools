#pragma once
#ifndef CTEXCDEFINE_H
#define CTEXCDEFINE_H

#include <string>
#include <exception>
#include <common\CTComDefine.h>
#include <common\CTCString.h>

typedef CTSize_t CTExcCode_t;

#if (CT_LANGUAGE == CT_USA)
#define NO_DEFAULT "no default"
#else
//���û�������Ҫ��Ϣʱ����ʾ��Ĭ���ַ�
#define NO_DEFAULT "û������"

//����Ϊ���쳣������������ַ�

#endif /* ���� */

#endif