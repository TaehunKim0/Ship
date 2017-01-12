#pragma once

using namespace std;
class Texture
{
private:
	LPDIRECT3DTEXTURE9 texture;
	float width;
	float height;

	string filename;

public:
	Texture();
	~Texture();

public:
	void SetTexture(string filename, LPDIRECT3DTEXTURE9 texture);

	LPDIRECT3DTEXTURE9 GetTexture() const;

	float GetWidth() const;
	float GetHeight() const;

	D3DXVECTOR2 GetCentor();

	string GetFileName() const;
};

