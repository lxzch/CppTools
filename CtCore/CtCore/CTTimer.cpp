#include "stdafx.h"
#include <CTTimer>

UINT CppTools::CTTime::CTTimer::num = 0;

CppTools::CTTime::CTTimer::CTTimer(ctTimerFunc timerFunc, UINT delay, CTTimerMode mode, UINT precision)
			:_timerFunc(timerFunc), _delay(delay), _mode(mode), _precision(precision), active(false)
{
	++num;
}

CppTools::CTTime::CTTimer::~CTTimer()
{
	if(active)
		killTimer();
	--num;
}

void CppTools::CTTime::CTTimer::setTime(UINT delay)
{
	_delay = delay;
}

void CppTools::CTTime::CTTimer::setPrecision(UINT precision)
{
	_precision = precision;
}

void CppTools::CTTime::CTTimer::setCallbackFunc(ctTimerFunc timerFunc)
{
	_timerFunc = timerFunc;
}

void CppTools::CTTime::CTTimer::setMode(CTTimerMode mode)
{
	_mode = mode;
}

void CppTools::CTTime::CTTimer::start()
{
	if(!_timerFunc)
		throw CppTools::CTException::CTTimerException::CTTimerErrNoCallbackFunction();
	UINT wAccuracy;
	TIMECAPS tc;
	if(timeGetDevCaps(&tc, sizeof(TIMECAPS)) == TIMERR_NOERROR)
	{
		wAccuracy = Min(Max(tc.wPeriodMin, _precision), tc.wPeriodMax);
		timeBeginPeriod(wAccuracy);
	}
	else
		throw CppTools::CTException::CTTimerException::CTTimerErrGetAccracy();
	if(!active)
	{		
		id = timeSetEvent(_delay, _precision, _timerFunc, (DWORD)this, _mode);
	}
	else
	{
		stop();
		id = timeSetEvent(_delay, _precision, _timerFunc, (DWORD)this, _mode);
	}
	if (!id)
		throw CppTools::CTException::CTTimerException::CTTimerErrStart();
	active = true;
}

void CppTools::CTTime::CTTimer::stop()
{
	if(active)
	{
		killTimer();
		active = false;
		id = NULL;
	}
}

bool CppTools::CTTime::CTTimer::isActive() const
{
	return active;
}

void CppTools::CTTime::CTTimer::killTimer()
{
	timeKillEvent(id);
}