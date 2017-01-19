#pragma once

class Player;
class Background;

class land_stage : public GameObject
{
private:
	Player* player;
	Background* background;


public:
	land_stage();
	~land_stage();

	void OnUpdate() override;
	void OnDraw() override;
};