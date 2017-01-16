#pragma once
class Sprite;
class Player;
class land_stage : public GameObject
{
private:
	Sprite* land;
	Player* player;
	int x;
	int y;


	int lx;
public:
	land_stage();
	~land_stage();

	void OnUpdate() override;
	void OnDraw() override;
};