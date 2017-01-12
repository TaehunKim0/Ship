#pragma once
using namespace std;

class Texture;
class TextureMgr : public SingleTon<TextureMgr>
{
private:
	unordered_map<string, Texture*> textureMap;


public:
	TextureMgr();
	~TextureMgr();

	void Init();
	void Release();

public:
	Texture* LoadTexture(string filename);
	void UnLoadTexture(string filename);
};

