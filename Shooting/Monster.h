#pragma once

#include "Config.h"
#include "GameObject.h"

class Monster : public GameObject
{
private:
	POINTFLOAT monsterPos;
	RECT shape;
	int bodySize;
	float moveSpeed;

protected:

public:
	inline void SetPos(POINTFLOAT pos) { this->monsterPos = pos; }
	inline POINTFLOAT GetPos() { return this->monsterPos; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }

};

