#include "stdafx.h"
#include "Timer.h"


Timer::Timer(func function, int milliseconds) : function(function), milliseconds(milliseconds)
{
}


Timer::~Timer()
{
}

void Timer::Run()
{
	handle = CreateThread(NULL, 0, ThreadFunc, this, 0, 0);
}

DWORD Timer::ThreadFunc(LPVOID p)
{
	auto timer = static_cast<Timer*>(p);

	SleepEx(timer->milliseconds, false);
	timer->function();

	return 0;
}
