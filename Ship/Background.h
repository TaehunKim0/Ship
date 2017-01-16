#pragma once
class Sprite;
class Background : public GameObject
{
private:
	std::vector<Sprite*> BackgroundList;

public:
	Background();
	~Background();

	void AddBackground(Sprite* background);

	void RemoveBackground();

	void OnUpdate() override;
	void OnDraw() override;
};

