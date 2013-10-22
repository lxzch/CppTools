#pragma once
#ifndef CTTIMER_H
#define CTTIMER_H

#include <CTBase>
#include <stdlib.h>
#include <mmsystem.h>
#include <exception\CTTimerException.h>

#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"winmm.lib")

typedef UINT CTTimerHandle;
typedef void (__stdcall *p_func_u_u_d_d_d)(UINT, UINT, DWORD, DWORD, DWORD);
typedef p_func_u_u_d_d_d ctTimerFunc;

namespace CppTools
{
	namespace CTTime
	{
		enum CPPTOOLS_API CTTimerMode
		{
			onlyonce = TIME_ONESHOT,
			repeat = TIME_PERIODIC,
		};

		class CPPTOOLS_API CTTimer
		{
		public:

			CTTimer(ctTimerFunc timerFunc = NULL, UINT delay = 1000, CTTimerMode mode = repeat, UINT precision = 1);
			~CTTimer();

			void setTime(UINT delay);
			void setPrecision(UINT precision);
			void setCallbackFunc(ctTimerFunc timerFunc);
			void setMode(CTTimerMode mode);
			void start();
			void stop();
			bool isActive() const;

		protected:

			void killTimer();

			static UINT num;
			UINT _delay, _precision;
			ctTimerFunc _timerFunc;
			CTTimerMode _mode;

			CTTimerHandle id;
			bool active;
		};
	}
}

#endif