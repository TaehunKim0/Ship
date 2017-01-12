#pragma once


class GameObject;
class SceneMgr : public SingleTon<SceneMgr>
{
private:
	GameObject* currentScene;


public:
	SceneMgr();
	~SceneMgr();

	virtual void Update();
	virtual void Draw();

	void SetScene(GameObject* scene);
};

