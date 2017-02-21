#include"stdafx.h"
#include"Main_scene.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
RECT windowRect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
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

	WNDCLASS wc = {}; //������ Ŭ���� ����
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = "Ship";
	wc.style = NULL;

	if (RegisterClass(&wc) == NULL) //window Ŭ������ ����Ѵ�.
		return 0;

	
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

	SIZE ActualSize =
	{
		(windowRect.right - windowRect.left),
		(windowRect.bottom - windowRect.top)
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

	ShowWindow(hwindow, SW_SHOWDEFAULT); //���⼭ WM_PAINT �޼����� �߻��ؼ� ȭ�鿡 �����츦 ��Ÿ����.
	UpdateWindow(hwindow); //�ٷ� Updatewindow�� ȭ���� �����Ѵ�.

	GameMgr::GetInstance()->Init(hwindow, true);

	SceneMgr::GetInstance()->SetScene(new Main_scene()); //SetScene�� Main_Scene�� �����ϰ� ���� ����ȴ�.

	MSG msg = {};

	while (msg.message != WM_QUIT) //���� �ݺ�
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) //�޽����� ������ true ����, ������ false ����
		{
			TranslateMessage(&msg); //Ű���� �̺�Ʈ�� �����ϰ� �ٲ���
			DispatchMessage(&msg); //�޽����� ó���� ���ν����� �޽����� �Ѱ���
		}
		else
		{
			GameMgr::GetInstance()->Update();
			GameMgr::GetInstance()->Draw();
	

			GameTime::CurrentFrame++;
			if (GameTime::CurrentFrame > 60)
				GameTime::CurrentFrame = 1;

			GameTime::TotalFrame++;

			//printf("CurrentFrame : %d \n", GameTime::CurrentFrame);
			//printf("TotalFrame : %d \n", GameTime::TotalFrame);

		}
	}

	GameMgr::GetInstance()->Release();
	UnregisterClass("Ship", wc.hInstance);
	return 0;
}