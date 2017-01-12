#pragma once

class InputMgr : public SingleTon<InputMgr>
{
private:
	D3DXVECTOR2 mousePosition;

	HWND hWindow;

public:
	InputMgr();
	~InputMgr();

	void Init(HWND hWindow);
	void Update();

public:
	D3DXVECTOR2 GetMousePosition();

	bool IsKeyDown(int key);

	bool IsKeyPress(int key);

};

