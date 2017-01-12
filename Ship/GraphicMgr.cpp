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
	//Ŭ���̾�Ʈ�� �۾� ������ ũ�⸦ �����ش�

	//D3D ��ü ����(Device�� �����ϱ� ����)
	if ((d3d9 = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return;

	//Device ����
	D3DPRESENT_PARAMETERS d3dpp = {}; 
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = false;
	d3dpp.BackBufferWidth = 1280;
	d3dpp.BackBufferHeight = 720;
	//�� �ڵ�� ��üȭ�� ���� 

	//Device ����
	if FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &device))
		return;

	//Sprite ����
	if FAILED(D3DXCreateSprite(device, &sprite))
		return;
}

void GraphicMgr::Release()
{
	
}

void GraphicMgr::BeginDraw()
{
	if SUCCEEDED(device->BeginScene()) //������ ����, �������� �׸��ڴٰ� D3D���� �˸���.
		device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0); //�ĸ� ���۸� (50,50,50)���� �����.(ȭ���� clear�� ������ �����.)
	
}

void GraphicMgr::EndDraw()
{
	if SUCCEEDED(device->EndScene()) //�������� �ٱ׷ȴٰ� D3D���� �˸���.
		device->Present(NULL, NULL, NULL, NULL); // �ĸ� ���۸� ���̴� ȭ������ �ٲ۴�.(ȭ�鿡 ��Ÿ����.)
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
	sprite->Begin(D3DXSPRITE_ALPHABLEND); //Sprite �׸� �غ�
	sprite->SetTransform(&matrix); //Sprite�� ����� �����Ų��
	sprite->Draw(texture->GetTexture(), srcRect, NULL, NULL, color);//�׸���.
}