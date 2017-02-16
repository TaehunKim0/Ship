#pragma once
class Background;
class UnitSpawner;
class TurtleShip;
class UI;

class land_stage : public Scene
{
private:
	Player* player;
	Background* background;

	UnitSpawner* unitSpawner;

	TurtleShip* turtleShip;

	UI* ui;
	bool spawn;

	
public:
	land_stage(string id);
	~land_stage();

	void OnUpdate() override;
	void OnDraw() override;
};