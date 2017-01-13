#include"stdafx.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

HWND hwindow;

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_MOUSEMOVE:
		break;

	case WM_DESTROY:
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	WNDCLASS wc = {}; //윈도우 클래스 생성
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = "Ship";
	wc.style = NULL;

	if (RegisterClass(&wc) == NULL) //window 클래스를 등록한다.
		return 0;

	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	SIZE ActualSize =
	{
		(rect.right - rect.left),
		(rect.bottom - rect.top)
	};

	hwindow = CreateWindow(
		"Ship",
		"Ship",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		ActualSize.cx, ActualSize.cy,
		NULL, NULL, NULL, NULL);

	if (hwindow == NULL)
		return 0;

	ShowWindow(hwindow, SW_SHOWDEFAULT); //여기서 WM_PAINT 메세지가 발생해서 화면에 윈도우를 나타낸다.
	UpdateWindow(hwindow); //바로 Updatewindow로 화면을 갱신한다.

	GameMgr::GetInstance()->Init(hwindow, false);
	//SceneMgr::GetInstance()->SetScene(new )

	MSG msg = {};

	while (msg.message != WM_QUIT) //무한 반복
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) //메시지가 있으면 true 리턴, 없으면 false 리턴
		{
			TranslateMessage(&msg); //키보드 이벤트를 적절하게 바꿔줌
			DispatchMessage(&msg); //메시지를 처리할 프로시저에 메시지를 넘겨줌
		}
		else
		{
			GameMgr::GetInstance()->Update();
			GameMgr::GetInstance()->Draw();

			GameTime::CurrentFrame++;
			if (GameTime::CurrentFrame > 60)
				GameTime::CurrentFrame = 1;

			GameTime::TotalFrame++;
		}
	}

	GameMgr::GetInstance()->Release();
	UnregisterClass("Ship", wc.hInstance);
	return 0;
}