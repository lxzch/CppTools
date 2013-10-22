#pragma once
#ifndef CTINTERPOLATION_H
#define CTINTERPOLATION_H

#include <common\CTObject.h>
#include <CTData>
#include <exception\CTFileException.h>

_CT_MATH_BEGIN

template <typename Tx,
	typename Ty>
	class CTInterPolation
		: public _CT_DATA__ CTObject
	{
	public:
		typedef _STD__ pair<Tx, Ty>					_pair_x_y;
		typedef _STD__ map<Tx, Ty>					_map;
		typedef typename _map::iterator				_map_it;
		typedef _CT_DATA__ CTMaxMin<Tx>				_maxmin;

	public:
		CTInterPolation(const _STD__ string& file = "");
		~CTInterPolation();

	public:
		Ty value(Tx key);
		virtual void readFrom(const _STD__ string& file = "");
		void dispose();
		Tx keyMax() const;
		Tx keyMin() const;
		_maxmin maxmin() const;

	private:
		_STD__ string* file;
		_STD__ map<Tx, Ty>* data;
		_maxmin mm;
	};

_CT_MATH_END

#include <core\CTInterPolation.tpc>

#endif