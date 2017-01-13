#pragma once
class Background : public GameObject
{
private:
	

public:
	Background();
	~Background();

	void OnUpdate() override;
	void OnDraw() override;
};

