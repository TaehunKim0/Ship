#pragma once
class Sprite;
class Background;
class land_stage : public GameObject
{
private:
	Background* land;

public:
	land_stage();
	~land_stage();

	void OnUpdate() override;
	void OnDraw() override;
};
