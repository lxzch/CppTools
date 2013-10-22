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
//当用户输入需要信息时，提示的默认字符
#define NO_DEFAULT "没有设置"

//以下为各异常类所需输出的字符

#endif /* 语言 */

#endif