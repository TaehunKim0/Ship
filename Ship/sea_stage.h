#pragma once

class Background;
class UnitSpawner;
class UI;

class sea_stage : public Scene
{
private:
	Player* player;
	Background* background;
	UnitSpawner* unitSpawner;
	UI* ui;


public:
	sea_stage(string id);
	~sea_stage();

	void OnUpdate() override;
	void OnDraw() override;

};