#include "stdafx.h"
#include "CircleCollider.h"


bool CircleCollider::IsCollidewith(Collider * other)
{
	return other->IsCollideWith(this);
}

bool CircleCollider::IsCollidewith(CircleCollider * other)
{
	auto delta = GetParent()->GetPosition() - other->GetParent()->GetPosition();
	auto distance = sqrt(pow(delta.x, 2) + pow(delta.y, 2));

	printf("°Å¸® : %f \n", distance);

	if (distance > (GetRadius() + other->GetRadius()))
		return false;

	return true;
}

CircleCollider::CircleCollider(float radius)
{
	this->Radius = radius;
}

CircleCollider::CircleCollider()
{
	
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::OnUpdate()
{
}

void CircleCollider::OnDraw()
{
}
