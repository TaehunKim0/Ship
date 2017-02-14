#pragma once

class Friendly;
class Enemy;
class Unit;

class UnitSpawner : public GameObject
{
private:

	std::vector<Unit*> unitList;


public:
	UnitSpawner();
	~UnitSpawner();

	void OnUpdate();
	void OnDraw();


	void SpawnFriendly();
	void SpawnEnemy();

};