#include "stdafx.h"
#include "Sprite.h"
#include"Texture.h"

Sprite::Sprite() : color(D3DCOLOR_XRGB(255,2552,255))
{
}


Sprite::~Sprite()
{
}

Sprite * Sprite::Create(std::string filename)
{
	return Sprite::Create(filename, 0, 0, 0, 0);
}

Sprite * Sprite::Create(std::string filename, int x, int y, int width, int height)
{
	auto texture = TextureMgr::GetInstance()->LoadTexture(filename);

	if (texture == nullptr)
		return nullptr;

	auto sprite = new Sprite();
	sprite->SetTexture(texture);

	RECT sourceRect;
	SetRect(&sourceRect, x, y, (width > 0) ? (x + width) : texture->GetWidth(), (height > 0) ? (y + height) : texture->GetHeight());

	sprite->SetSourceRect(sourceRect);

	return sprite;
}

D3DXVECTOR2 Sprite::GetPivot() const
{
	return D3DXVECTOR2();
}

void Sprite::SetPivot(int x, int y)
{
}

Texture * Sprite::GetTexture() const
{
	return texture;
}

void Sprite::SetTexture(Texture * texture)
{
	this->texture = texture;
}

D3DXVECTOR2 Sprite::GetSize() const
{
	return D3DXVECTOR2(texture->GetWidth(), texture->GetHeight());
}

D3DXVECTOR2 Sprite::GetColor() const
{
	return color;
}

void Sprite::SetColor(D3DXCOLOR color)
{
	this->color = color;
}

RECT Sprite::GetSourceRect()
{
	return sourceRect;
}

void Sprite::SetSourceRect(RECT rect)
{
	this->sourceRect = rect;
}

void Sprite::FlipX()
{
	scaleCenter = texture->GetCentor();
	scale.x *= -1.0f;
}

void Sprite::OnUpdate()
{
}

void Sprite::OnDraw()
{
	GraphicMgr::GetInstance()->DrawTexture(texture, &sourceRect, color, matrix);
}
