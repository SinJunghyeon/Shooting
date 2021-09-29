#pragma once

#include "Config.h"
#include "Weapon.h"

class Banana : public Weapon
{
private:
	POINTFLOAT weaponPos;
	RECT weaponShape;
	int weaponBodySize;
	float weaponMoveSpeed;

protected:

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	Banana();
	~Banana();
};

