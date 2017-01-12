#pragma once
class GameMgr : public SingleTon<GameMgr>
{
private:



public:
	GameMgr();
	~GameMgr();

	void Init(HWND hWindow, bool windowed);
	void Release();

	void Update();
	void Draw();
};

