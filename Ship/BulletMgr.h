#pragma once
class Bullet;
class BulletMgr : public GameObject, public SingleTon<BulletMgr>
{
private:
	std::vector<Bullet*> bulletList;

public:
	BulletMgr();
	~BulletMgr();

	void RegisterBullet(Bullet * bullet);

	void OnUpdate();
	void OnDraw();
};