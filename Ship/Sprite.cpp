#include "stdafx.h"
#include "Sprite.h"

#include"Texture.h"


using namespace std;
Sprite::Sprite() : color(D3DCOLOR_XRGB(255,2552,255)) , is(true)
{
	
}

Sprite::Sprite(std::string fileName)
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
	sprite->Setting();

	return sprite;
	
}


Texture * Sprite::GetTexture() const
{
	return texture;
}

void Sprite::SetTexture(Texture * texture)
{
	this->texture = texture;
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

void Sprite::Resize(float width, float height)
{
	SetScale({
		width / size.x,
		height / size.y
	}
	);
	
	this->SetCenter({
		scale.x / 2,
		scale.y / 2
	});


}

void Sprite::Setting()
{
	this->position.x += this->texture->GetWidth() / 2;
	this->position.y += this->texture->GetHeight() / 2;

	
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
	//if (!visible || !IsLoaded) return;


	GraphicMgr::GetInstance()->DrawTexture(texture, &sourceRect, color, matrix);


	//RECT srcRect;
	//SetRect
	//(
	//	&srcRect,
	//	0,0,
	//	static_cast<int>(size.x),
	//	static_cast<int>(size.y)
	//);

	//m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//m_sprite->SetTransform(&matrix);
	//m_sprite->Draw(
	//	texture->GetTexture(),
	//	&srcRect, NULL, &D3DXVECTOR3(this->position.x , this->position.y, .0f), //-m_ImageWidth / 2, -m_ImageHeight / 2
	//	D3DCOLOR_ARGB(255, 255, 255, 255));

	//m_sprite->End();
}