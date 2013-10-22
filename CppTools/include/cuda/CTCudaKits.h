//此文件只能用于.cu文件中，如果被.h文件包含，那么一旦使用CUDA内建变量将产生错误，
//故应避免将.cu文件包含在主程序中。

//如果定义了CCU_32，那么将强制使用32位标准乘加，而不使用CUDA内建的24位加速乘加

#ifdef CTDEFINE_H
 #error 错误(cter_201): 头文件 <CTCudaKits.h> 必须在头文件 <CTDefine.h> 前定义
#endif

#pragma once
#ifndef CTCUDAKITS_H
#define CTCUDAKITS_H

#define CCU_SURPORT
//CCU_SURPORT开关使CtCore中一些用于计算比较的函数可以在nvcc中编译，并能在显卡上执行

#define CCU_gdim_x		(gridDim.x)
#define CCU_gdim_y		(gridDim.y)
#ifndef CCU_32
 #define CCU_gdim		(__mul24(CCU_gdim_x, CCU_gdim_y))
#else
 #define CCU_gdim		(CCU_gdim_x * CCU_gdim_y)
#endif
//CCU_gdim表示一个grid的规模，即其中有多少个block

#define CCU_bid_x		(blockIdx.x)
#define CCU_bid_y		(blockIdx.y)
#define CCU_bdim_x		(blockDim.x)
#define CCU_bdim_y		(blockDim.y)
#ifndef CCU_32
 #define CCU_bdim		(__mul24(CCU_bdim_x, CCU_bdim_y))
#else
 #define CCU_bdim		(CCU_bdim_x * CCU_bdim_y)
#endif
//CCU_bdim表示一个block的规模，即其中有多少个thread

#define CCU_tid_x		(threadIdx.x)
#define CCU_tid_y		(threadIdx.y)

#ifndef CCU_32
 #define CCU_bpos		(__mul24(CCU_gdim_x, CCU_bid_y) + CCU_bid_x)
 #define CCU_tpos		(__mul24(CCU_bpos, CCU_bdim) + __mul24(CCU_bdim_x, CCU_tid_y) + CCU_tid_x)
#else
 #define CCU_bpos		(CCU_gdim_x * CCU_bid_y + CCU_bid_x)
 #define CCU_tpos		(CCU_bpos * CCU_bdim + CCU_bdim_x * CCU_tid_y + CCU_tid_x)
#endif
//CCU_bpos和CCU_tpos只适用于分配规模和任务本身正好适应的情况，当任务本身小于分配规模时，将不能得到正确的线性索引值
//CCU_bpos表示当前线程所在的block的索引值
//CCU_tpos表示当前线程在全局（整个任务，跨grid和block）中的索引值
//CCU_bpos和CCU_tpos不能计算threadDim中深度值大于1的位置

#define CCU_GridDim(var_name, grid_width, grid_height) \
	dim3 var_name((grid_width), (grid_height), 1)
#define CCU_ThreadDim(var_name, thread_width, thread_height, thread_depth) \
	dim3 var_name((thread_width), (thread_height), (thread_depth))
#define CCU_DataReady	__syncthreads()

#endif