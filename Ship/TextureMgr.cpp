#include "stdafx.h"
#include "TextureMgr.h"
#include"Texture.h"

TextureMgr::TextureMgr()
{
}


TextureMgr::~TextureMgr()
{
}

void TextureMgr::Init()
{
}

void TextureMgr::Release()
{
	for (auto& texture : textureMap)
		SAFE_DELETE(texture.second);

	textureMap.clear();
		
}

Texture * TextureMgr::LoadTexture(string filename)
{
	if (textureMap.find(filename) != textureMap.end())
		return textureMap[filename];

	LPDIRECT3DTEXTURE9 nativeTexture;

	devicess = GraphicMgr::GetInstance()->GetDevice();

	if (devicess == nullptr)
		printf("TextureMgr���� Device�� �������� ���ߴ�.");

	//������ �⺻���� �� �ؽ��ĸ� �����Ѵ�.
	if FAILED(D3DXCreateTextureFromFileEx(
		GraphicMgr::GetInstance()->GetDevice(), filename.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8B8G8R8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &nativeTexture
	))
	{
		printf("�� �ؽ��� �Ҵ� ����(%s)\n", filename.c_str());
		return nullptr;
	}
	
	Texture* texture = new Texture();
	texture->SetTexture(filename, nativeTexture);

	printf("�� �ؽ��� �Ҵ�(%s)\n", filename.c_str());

	return texture;

}

void TextureMgr::UnLoadTexture(string filename)
{
}
