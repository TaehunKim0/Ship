#pragma once
class Timer
{
private:
	typedef void(*func)(void);

	HANDLE handle;

	func function;
	int milliseconds;

public:
	Timer(func function, int milliseconds);
	virtual ~Timer();

	void Run();

private:
	static DWORD CALLBACK ThreadFunc(LPVOID p);

};

