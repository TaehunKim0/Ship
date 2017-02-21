#pragma once
class CollisionMgr : public SingleTon<CollisionMgr>
{
private:


public:
	CollisionMgr();
	~CollisionMgr();

	bool IsPointInRect(Sprite * sprite);
};