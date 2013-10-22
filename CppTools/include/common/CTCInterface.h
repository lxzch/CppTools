#ifndef CTCINTERFACE_H
#define CTCINTERFACE_H

#define CTCIF_ON

//请不要修改或反定义下述定义语句，随意修改将导致代码无法编译
#define CTInterface class

//接口定义

//常用接口

CTInterface CTCIFInit
{
public:
	virtual void init() = 0;
};

CTInterface CTCIFDispose
{
public:
	virtual void dispose() = 0;
};

CTInterface CTCIFClose
{
public:
	virtual void close() = 0;
};

CTInterface CTCIFClear
{
public:
	virtual void clear() = 0;
};

CTInterface CTCIFCopy
{
public:
	virtual void copy() = 0;
};

CTInterface CTCIFMove
{
public:
	virtual void move() = 0;
};

CTInterface CTCIFNext
{
public:
	virtual void next() = 0;
};

CTInterface CTCIFBack
{
public:
	virtual void back() = 0;
};

template <typename Tx>
CTInterface CTCIFSize
{
public:
	virtual Tx size() const = 0;
};

//数据接口

template <typename Tx>
CTInterface CTCIFSetData
{
public:
	virtual void setData(Tx) = 0;
};

template <typename Tx>
CTInterface CTCIFGetData
{
public:
	virtual Tx getData() const = 0;
};

template <typename Tx,
	typename p_Tx = Tx*>
CTInterface CTCIFSetServer
{
public:
	virtual void setServer(const p_Tx) = 0;
};

template <typename Tx,
	typename p_Tx = Tx*>
CTInterface CTCIFGetServer
{
public:
	virtual p_Tx getServer() const = 0;
};

template <typename Tx,
	typename p_Tx = Tx*>
CTInterface CTCIFSetClient
{
public:
	virtual void setClient(const p_Tx) = 0;
};

template <typename Tx,
	typename p_Tx = Tx*>
CTInterface CTCIFGetClient
{
public:
	virtual p_Tx getClient() const = 0;
};

//计算接口

template <typename Tx>
CTInterface CTCIFCal_t
{
public:
	virtual void calculate(const Tx t) = 0;
};

template <typename Tx>
CTInterface CTCIFCal_x
{
public:
	virtual void calculate(const Tx x) = 0;
};

template <typename Tx,
	typename Ty = Tx>
CTInterface CTCIFCal_xy
{
public:
	virtual void calculate(const Tx x, const Tx y) = 0;
};

template <typename Tx,
	typename Ty = Tx,
	typename Tz = Tx>
CTInterface CTCIFCal_xyz
{
public:
	virtual void calculate(const Tx x, const Tx y, const Tz z) = 0;
};

//图形接口

CTInterface CTCIFDraw
{
public:
	virtual void draw() = 0;
};

#endif