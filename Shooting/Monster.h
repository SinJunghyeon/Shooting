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

	bool isShoot;

protected:
	enum class MonsterState { Idle, Move, Attack, Damaged, End };

public:
	void Init();

	inline void SetPos(POINTFLOAT pos) { this->monsterPos = pos; }
	inline POINTFLOAT GetPos() { return this->monsterPos; }
	inline void SetMoveSpeed(float speed) { this->monsterMoveSpeed = speed; }
	inline void SetIsShoot(bool isShoot) { this->isShoot = isShoot; }
	inline bool GetIsShoot() { this->isShoot; }

	Monster();
	~Monster();

};

