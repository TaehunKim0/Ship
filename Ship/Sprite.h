#pragma once


class Texture;
class Sprite : public GameObject
{
private:
	Texture* texture;
	D3DXCOLOR color;

	D3DXVECTOR2 pivot;



public:
	Sprite();
	~Sprite();
};

