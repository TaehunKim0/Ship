#pragma once
class AddFriendly;
class UI : public GameObject
{
private:
	AddFriendly* addFriendly;

public:
	UI();
	~UI();

	void OnUpdate();
	void OnDraw();
};

