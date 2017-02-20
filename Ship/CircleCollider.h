#pragma once
#include"Collider.h"

class CircleCollider : public Collider
{
private:
	float Radius;

public:
	float GetRadius() { return Radius; }

public:
	bool IsCollidewith(Collider* other);
	bool IsCollidewith(CircleCollider* other);

public:
	CircleCollider(float radius);
	CircleCollider();
	~CircleCollider();

public:
	void OnUpdate();
	void OnDraw();
};

