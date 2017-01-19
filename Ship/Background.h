#pragma once
class Sprite;
class Player;
class Background : public GameObject
{
private:
	Sprite* background;
	Player* player;

public:
	Background(string background);
	~Background();

	void OnUpdate() override;
	void OnDraw() override;
};