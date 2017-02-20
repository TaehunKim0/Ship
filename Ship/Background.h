#pragma once
class Sprite;
class Player;
class Background : public GameObject
{
private:
	Sprite* background;
	Player* player;

	std::vector<Sprite*> backgroundList;
public:
	
	Background();
	~Background();

	void OnUpdate() override;
	void OnDraw() override;


	void SetBackGround(Sprite* sprite);
};