#pragma once
class Player;
class Friendly;
class Enemy;
class sea_stage : public Scene
{
private:
	Player* player;
	Friendly* friendly;
	Enemy* enemy;

public:
	sea_stage();
	~sea_stage();

	void OnUpdate() override;
	void OnDraw() override;

};