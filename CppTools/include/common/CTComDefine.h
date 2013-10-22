#ifndef CTCOMDEFINE_H
#define CTCOMDEFINE_H

#pragma warning(disable:4996)

#include <common\cpptools.h>

//语言
//language section
#define CT_CHN			0x00
#define CT_USA			0x01
#define CT_RUS			0x02
#define CT_GER			0x03
#define CT_FRA			0x04
#define CT_ITA			0x05
#define CT_GBR			CT_USA
#define CT_AUS			CT_USA
#define CT_CAN			CT_USA
#define CT_JPN			0x0B
#define CT_IND			0x22

//类型再定义

#ifndef NULL
#define NULL 0
#endif

#ifndef UINT
typedef unsigned int	UINT;
#endif

#ifndef UCHAR
typedef unsigned char	UCHAR;
#endif

#ifndef byte
typedef UCHAR			byte;
#endif

#ifndef ULONG
typedef unsigned long	ULONG;
#endif

typedef int				CTType_i;
typedef unsigned int	CTType_ui;
typedef long			CTType_l;
typedef unsigned long	CTType_ul;
typedef float			CTType_f;
typedef double			CTType_d;

typedef CTType_i		CTSize_t;

typedef CTSize_t		CTDate_i;
typedef CTType_d		CTDate_d;

typedef CTType_i		CTData_i;
typedef CTType_ui		CTData_ui;
typedef CTType_l		CTData_l;
typedef CTType_ul		CTData_ul;
typedef CTType_f		CTData_f;
typedef CTType_d		CTData_d;

typedef size_t			CTSTDSize_t;

#endif