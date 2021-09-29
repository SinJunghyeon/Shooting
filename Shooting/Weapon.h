#pragma once

#include "Config.h"
#include "GameObject.h"

class Weapon : public GameObject
{
private:
	POINTFLOAT weaponPos;
	RECT shape;
	int bodySize;
	float moveSpeed;

protected:

public:
	inline void SetPos(POINTFLOAT pos) { this->weaponPos = pos; }
	inline POINTFLOAT GetPos() { return this->weaponPos; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }

};

