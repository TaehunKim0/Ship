#pragma once

class Texture;
class GraphicMgr : public SingleTon<GraphicMgr>
{
private:
	LPDIRECT3D9 d3d9; //D3D 디바이스를 생성할 D3D 객체
	LPDIRECT3DDEVICE9 device; // 렌더링에 사용될 D3D 디바이스
	
	LPD3DXSPRITE sprite; // 2D이미지를 그리기 편하게 해줌



	
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

