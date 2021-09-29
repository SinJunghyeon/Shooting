#pragma once

#include "Config.h"
#include "GameObject.h"

class Monster : public GameObject
{
private:
	POINTFLOAT monsterPos;
	RECT monsterShape;
	int monsterBodySize;
	float monsterMoveSpeed;

protected:

public:
	void Init();

	inline void SetPos(POINTFLOAT pos) { this->monsterPos = pos; }
	inline POINTFLOAT GetPos() { return this->monsterPos; }
	inline void SetMoveSpeed(float speed) { this->monsterMoveSpeed = speed; }

	Monster();
	~Monster();

};

