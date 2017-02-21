#pragma once

class Friendly;
class Enemy;
class Unit;

class UnitSpawner : public GameObject, public SingleTon<UnitSpawner>
{
private:

	std::vector<Unit*> unitList;


public:
	UnitSpawner();
	~UnitSpawner();

	void OnUpdate();
	void OnDraw();


	void SpawnFriendly(int x , int y);
	void SpawnEnemy(int x, int y);
	void SpawnArrowTurret(int x, int y);


};