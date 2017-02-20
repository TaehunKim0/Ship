#pragma once
class CircleCollider;
class Collider : public GameObject
{
public:
	virtual bool IsCollideWith(Collider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	Collider();
	~Collider();

	void OnUpdate();
	void OnDraw();
};

