#pragma once

class MonsterSpawner : public GameObject
{
private:

	std::vector<GameObject*> mobList;




public:
	MonsterSpawner();
	~MonsterSpawner();

	void OnUpdate();
	void OnDraw();

};

