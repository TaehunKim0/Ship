#pragma once
class ArrowTurret : public Unit
{
private:
	Sprite* turret;


public:
	ArrowTurret();
	~ArrowTurret();

	void OnUpdate();
	void OnDraw();

	void Move();
	void Attack();

};

