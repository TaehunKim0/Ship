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
	GetCursorPos(&point); //���� Ŀ�� ��ġ������ ������.

	ScreenToClient(hWindow, &point);// �۾� ������ ��ǥ�� �޾� GetCurosrPos, MoveWindow ��� ���� ȭ�� ��ǥ�� �䱸�ϴ� �Լ��� ��ǥ�� �����ϱ� ���� �� �Լ��� ����Ѵ�.

	this->mousePosition.x = static_cast<float>(point.x);
	this->mousePosition.y = static_cast<float>(point.y);

}

D3DXVECTOR2 InputMgr::GetMousePosition()
{
	return mousePosition;
}

bool InputMgr::IsKeyDown(int key)
{
	return static_cast<bool>(GetAsyncKeyState(key) & 0x8000); //Ű������ Ű�� ���ȴ����� üũ.
}

bool InputMgr::IsKeyPress(int key)
{
	return static_cast<bool>(GetAsyncKeyState(key) & 0x0001);
}