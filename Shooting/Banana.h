#pragma once

#include "Config.h"
#include "Weapon.h"

class ZombieLupin;

class Banana : public Weapon
{
private:
	Image* move;			//오른쪽으로 이동
	Image* mirroringMove;	//왼쪽으로 이동
	Image* hit;				//오른쪽에서 타격
	Image* mirroringHit;	//왼쪽에서 타격

	MoveDir bananaDir;

protected:
	ZombieLupin* shooting;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetDirection(MoveDir bananaDir) { this->bananaDir = bananaDir; }
	inline MoveDir GetDirection() { return this->bananaDir; }

	inline void SetShooting(ZombieLupin* shooting) { this->shooting = shooting; }

	Banana();
	~Banana();
};

