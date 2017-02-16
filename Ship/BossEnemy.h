#pragma once
class BossEnemy : public Unit
{
private:
	Sprite* boss;

public:
	BossEnemy();
	~BossEnemy();

	void OnDraw();
	void OnUpdate();
};

