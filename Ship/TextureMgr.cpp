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
		printf("TextureMgr에서 Device를 가져오지 못했다.");

	//파일을 기본으로 해 텍스쳐를 생성한다.
	if FAILED(D3DXCreateTextureFromFileEx(
		GraphicMgr::GetInstance()->GetDevice(), filename.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8B8G8R8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &nativeTexture
	))
	{
		printf("새 텍스쳐 할당 실패(%s)\n", filename.c_str());
		return nullptr;
	}
	
	Texture* texture = new Texture();
	texture->SetTexture(filename, nativeTexture);

	printf("새 텍스쳐 할당(%s)\n", filename.c_str());

	return texture;

}

void TextureMgr::UnLoadTexture(string filename)
{
}
