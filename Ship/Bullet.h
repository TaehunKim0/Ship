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

public:
	Bullet(string id);
	~Bullet();
	Sprite* bullet;
	bulletDirection::EnumType direction;
	

	void OnUpdate();
	void OnDraw();

	float GetSpeed();

};