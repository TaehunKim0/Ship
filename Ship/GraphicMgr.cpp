#include "stdafx.h"
#include "GraphicMgr.h"
#include"Texture.h"

GraphicMgr::GraphicMgr()
{
}


GraphicMgr::~GraphicMgr()
{
}

void GraphicMgr::Init(HWND hwindow, BOOL windowed)
{
	RECT clientRect;
	GetClientRect(hwindow, &clientRect);
	//클라이언트의 작업 영역의 크기를 구해준다

	//D3D 객체 생성(Device를 생성하기 위함)
	if ((d3d9 = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return;

	//Device 설정
	D3DPRESENT_PARAMETERS d3dpp = {}; 
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = false;
	d3dpp.BackBufferWidth = 1280;
	d3dpp.BackBufferHeight = 720;
	//위 코드는 전체화면 설정 

	//Device 생성
	if FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &device))
		return;

	//Sprite 생성
	if FAILED(D3DXCreateSprite(device, &sprite))
		return;
}

void GraphicMgr::Release()
{
	
}

void GraphicMgr::BeginDraw()
{
	if SUCCEEDED(device->BeginScene()) //렌더링 시작, 폴리곤을 그리겠다고 D3D에게 알린다.
		device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0); //후면 버퍼를 (50,50,50)으로 지운다.(화면을 clear로 깨끗히 지운다.)
	
}

void GraphicMgr::EndDraw()
{
	if SUCCEEDED(device->EndScene()) //폴리곤을 다그렸다고 D3D에게 알린다.
		device->Present(NULL, NULL, NULL, NULL); // 후면 버퍼를 보이는 화면으로 바꾼다.(화면에 나타난다.)
}

LPDIRECT3DDEVICE9 GraphicMgr::GetDevice() const
{
	return device;
}

LPD3DXSPRITE GraphicMgr::GetSprite() const
{
	return sprite;
}

void GraphicMgr::DrawTexture(Texture * texture, LPRECT srcRect, D3DXMATRIX matrix)
{
	GraphicMgr::DrawTexture(texture, srcRect, D3DCOLOR_XRGB(255, 255, 255), matrix);
}

void GraphicMgr::DrawTexture(Texture * texture, LPRECT srcRect, D3DXCOLOR color, D3DXMATRIX matrix)
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND); //Sprite 그릴 준비
	sprite->SetTransform(&matrix); //Sprite의 행렬을 적용시킨다
	sprite->Draw(texture->GetTexture(), srcRect, NULL, NULL, color);//그린다.
}