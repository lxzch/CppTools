//���ļ�ֻ������.cu�ļ��У������.h�ļ���������ôһ��ʹ��CUDA�ڽ���������������
//��Ӧ���⽫.cu�ļ��������������С�

//���������CCU_32����ô��ǿ��ʹ��32λ��׼�˼ӣ�����ʹ��CUDA�ڽ���24λ���ٳ˼�

#ifdef CTDEFINE_H
 #error ����(cter_201): ͷ�ļ� <CTCudaKits.h> ������ͷ�ļ� <CTDefine.h> ǰ����
#endif

#pragma once
#ifndef CTCUDAKITS_H
#define CTCUDAKITS_H

#define CCU_SURPORT
//CCU_SURPORT����ʹCtCore��һЩ���ڼ���Ƚϵĺ���������nvcc�б��룬�������Կ���ִ��

#define CCU_gdim_x		(gridDim.x)
#define CCU_gdim_y		(gridDim.y)
#ifndef CCU_32
 #define CCU_gdim		(__mul24(CCU_gdim_x, CCU_gdim_y))
#else
 #define CCU_gdim		(CCU_gdim_x * CCU_gdim_y)
#endif
//CCU_gdim��ʾһ��grid�Ĺ�ģ���������ж��ٸ�block

#define CCU_bid_x		(blockIdx.x)
#define CCU_bid_y		(blockIdx.y)
#define CCU_bdim_x		(blockDim.x)
#define CCU_bdim_y		(blockDim.y)
#ifndef CCU_32
 #define CCU_bdim		(__mul24(CCU_bdim_x, CCU_bdim_y))
#else
 #define CCU_bdim		(CCU_bdim_x * CCU_bdim_y)
#endif
//CCU_bdim��ʾһ��block�Ĺ�ģ���������ж��ٸ�thread

#define CCU_tid_x		(threadIdx.x)
#define CCU_tid_y		(threadIdx.y)

#ifndef CCU_32
 #define CCU_bpos		(__mul24(CCU_gdim_x, CCU_bid_y) + CCU_bid_x)
 #define CCU_tpos		(__mul24(CCU_bpos, CCU_bdim) + __mul24(CCU_bdim_x, CCU_tid_y) + CCU_tid_x)
#else
 #define CCU_bpos		(CCU_gdim_x * CCU_bid_y + CCU_bid_x)
 #define CCU_tpos		(CCU_bpos * CCU_bdim + CCU_bdim_x * CCU_tid_y + CCU_tid_x)
#endif
//CCU_bpos��CCU_tposֻ�����ڷ����ģ��������������Ӧ���������������С�ڷ����ģʱ�������ܵõ���ȷ����������ֵ
//CCU_bpos��ʾ��ǰ�߳����ڵ�block������ֵ
//CCU_tpos��ʾ��ǰ�߳���ȫ�֣��������񣬿�grid��block���е�����ֵ
//CCU_bpos��CCU_tpos���ܼ���threadDim�����ֵ����1��λ��

#define CCU_GridDim(var_name, grid_width, grid_height) \
	dim3 var_name((grid_width), (grid_height), 1)
#define CCU_ThreadDim(var_name, thread_width, thread_height, thread_depth) \
	dim3 var_name((thread_width), (thread_height), (thread_depth))
#define CCU_DataReady	__syncthreads()

#endif