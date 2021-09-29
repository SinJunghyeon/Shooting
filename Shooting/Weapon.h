#pragma once

#include "Config.h"
#include "GameObject.h"

class Weapon : public GameObject
{
private:
	POINTFLOAT weaponPos;
	RECT weaponShape;
	int weaponBodySize;
	float weaponMoveSpeed;

protected:
	bool isFire;

public:
	void Init();

	inline void SetPos(POINTFLOAT pos) { this->weaponPos = pos; }
	inline POINTFLOAT GetPos() { return this->weaponPos; }
	inline void SetMoveSpeed(float speed) { this->weaponMoveSpeed = speed; }
	inline float GetMoveSpeed() { return this->weaponMoveSpeed; }
	inline void SetIsFire(bool isFire) { this->isFire = isFire; }
	inline bool GetIsFire() { return this->isFire; }

	Weapon();
	~Weapon();
};

