#pragma once

class Texture;
class GraphicMgr : public SingleTon<GraphicMgr>
{
private:
	LPDIRECT3D9 d3d9; //D3D ����̽��� ������ D3D ��ü
	LPDIRECT3DDEVICE9 device; // �������� ���� D3D ����̽�
	
	LPD3DXSPRITE sprite; // 2D�̹����� �׸��� ���ϰ� ����



	
public:
	GraphicMgr();
	~GraphicMgr();

	void Init(HWND hwindow, BOOL windowed);
	void Release();
	int width;

	int height;
public:
	void BeginDraw();
	void EndDraw();

	LPDIRECT3DDEVICE9 GetDevice() const;
	LPD3DXSPRITE GetSprite() const;

	void DrawTexture(Texture* texture, LPRECT srcRect, D3DXMATRIX matrix);
	void DrawTexture(Texture * texture, LPRECT srcRect, D3DXCOLOR color, D3DXMATRIX matrix);
};

