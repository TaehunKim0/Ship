#pragma once

class Player;
class Background;
class Friendly;
class Enemy;
class UnitSpawner;

class land_stage : public Scene
{
private:
	Player* player;
	Background* background;

	UnitSpawner* unitSpawner;

	Friendly* friendly;
	Enemy* enemy;


public:
	land_stage();
	~land_stage();

	void OnUpdate() override;
	void OnDraw() override;
};