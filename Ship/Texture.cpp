#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
	texture = NULL;
	width = 0.0f;
	height = 0.0f;
}


Texture::~Texture()
{
}

void Texture::SetTexture(string filename, LPDIRECT3DTEXTURE9 texture)
{
	D3DSURFACE_DESC desc;//2D �̹��� ������ ������
	texture->GetLevelDesc(0, &desc); //�ؽ����� ǥ�������� ��´�.

	this->filename = filename;

	this->width = desc.Width;
	this->height = desc.Height;

	this->texture = texture;
}

LPDIRECT3DTEXTURE9 Texture::GetTexture() const
{
	return texture;
}

float Texture::GetWidth() const
{
	return width;
}

string Texture::GetFileName() const
{
	return filename;
}


