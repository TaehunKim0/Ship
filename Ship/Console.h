#pragma once
#include"stdafx.h"

namespace Console
{
	inline void Init()
	{
		AllocConsole();
		FILE *stream;
		freopen_s(&stream,"CONOUT$", "wt", stdout);
	}

	inline void Release()
	{
		FreeConsole();
	}

}