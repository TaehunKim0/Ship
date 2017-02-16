#include "stdafx.h"
#include "InputMgr.h"


InputMgr::InputMgr()
{
}


InputMgr::~InputMgr()
{
}

void InputMgr::Init(HWND hWindow)
{
	this->hWindow = hWindow;
}

void InputMgr::Update()
{
	POINT point;
	GetCursorPos(&point); //현재 커서 위치정보를 가져옴.

	ScreenToClient(hWindow, &point);// 작업 영역의 좌표를 받아 GetCurosrPos, MoveWindow 등과 같이 화면 좌표를 요구하는 함수로 좌표를 전달하기 위해 이 함수를 사용한다.

	this->mousePosition.x = static_cast<float>(point.x);
	this->mousePosition.y = static_cast<float>(point.y);

}

D3DXVECTOR2 InputMgr::GetMousePosition()
{
	return mousePosition;
}

bool InputMgr::IsKeyDown(int key)
{
	return static_cast<bool>(GetAsyncKeyState(key) & 0x8000); //키보드의 키가 눌렸는지를 체크.
}

bool InputMgr::IsKeyPress(int key)
{
	return static_cast<bool>(GetAsyncKeyState(key) & 0x0001);
}