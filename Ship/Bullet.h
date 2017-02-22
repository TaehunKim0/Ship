#pragma once
namespace bulletDirection
{
	enum EnumType
	{
		left = 0,
		right = 1
	};
}

class Sprite;
class Bullet : public GameObject
{
private:
	float speed;
	float Demage;


public:
	Bullet(string id);
	~Bullet();
	Sprite* bullet;
	bulletDirection::EnumType direction;
	int LifeTime;

	void OnUpdate();
	void OnDraw();

	float GetSpeed();

};