#pragma once
class Player;
class sea_stage : public GameObject
{
private:
	Player* player;


public:
	sea_stage();
	~sea_stage();

	void OnUpdate() override;
	void OnDraw() override;

};