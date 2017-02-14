#pragma once
class Scene;
class SceneMgr : public SingleTon<SceneMgr>
{
private:
	Scene* currentScene;


public:
	SceneMgr();
	~SceneMgr();

	virtual void Update();
	virtual void Draw();

	void SetScene(Scene* scene);

	Scene* GetScene();
};

