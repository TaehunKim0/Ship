#pragma once


class Texture;
class Sprite : public GameObject
{
private:
	Texture* texture;
	D3DXCOLOR color;

	D3DXVECTOR2 pivot;

	RECT sourceRect;

	bool isFlippedx;
	bool isFlippedy;

public:
	Sprite();
	virtual ~Sprite();

	static Sprite* Create(std::string filename);
	static Sprite* Create(std::string filename, int x, int y, int width, int height);

	D3DXVECTOR2 GetPivot() const;
	void SetPivot(int x, int y);

	Texture* GetTexture() const;
	void SetTexture(Texture* texture);

	D3DXVECTOR2 GetSize() const;

	D3DXVECTOR2 GetColor() const;
	void SetColor(D3DXCOLOR color);

	RECT GetSourceRect();
	void SetSourceRect(RECT rect);

	virtual void FlipX();

	void OnUpdate() override;
	void OnDraw() override; //오버라이딩 제약



};

