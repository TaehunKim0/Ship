#pragma once

namespace TurtleShipForm
{
	enum Enum
	{
		Form1,
		Form2,
		Form3
	};
}


class TurtleShip : public GameObject
{
private:
	Sprite* form1;
	Sprite* form2;
	Sprite* form3;


public:
	TurtleShip();
	~TurtleShip();

	void OnUpdate();
	void OnDraw();

	void SetTurtleShipForm(TurtleShipForm::Enum form);

};

