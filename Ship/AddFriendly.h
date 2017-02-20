#pragma once

namespace AddActivation
{
	enum Enum
	{
		Can,
		Cannot
	};
}

class AddFriendly : public GameObject
{
private:
	Sprite* Plus;
	Sprite* CanPlus;
	Sprite* CannotPlus;

	AddActivation::Enum addActivation;
public:

	AddFriendly();
	~AddFriendly();

	void OnUpdate();
	void OnDraw();

	void SetActivation(AddActivation::Enum activation);
	
	AddActivation::Enum GetActivation();
};

