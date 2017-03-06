#pragma once


class Texture;
class Sprite : public GameObject
{
private:
	Texture* texture;
	D3DXCOLOR color;

	RECT sourceRect;

	string filename;

	LPD3DXSPRITE m_sprite;

	bool IsLoaded;

public:
	Sprite();
	Sprite(std::string fileName);
	virtual ~Sprite();

	static Sprite* Create(std::string filename);
	static Sprite* Create(std::string filename, int x, int y, int width, int height);

	Texture* GetTexture() const;
	void SetTexture(Texture* texture);

	D3DXVECTOR2 GetColor() const;
	void SetColor(D3DXCOLOR color);

	RECT GetSourceRect();
	void SetSourceRect(RECT rect);

	void Resize(float width, float height);

	void Setting();

	virtual void FlipX();

	void OnUpdate() override;
	void OnDraw() override; //오버라이딩 제약

	bool On;
	bool is;
};
