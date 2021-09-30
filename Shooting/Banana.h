#pragma once

#include "Config.h"
#include "Weapon.h"

class ZombieLupin;

class Banana : public Weapon
{
private:
	Image* move;			//���������� �̵�
	Image* mirroringMove;	//�������� �̵�
	Image* hit;				//�����ʿ��� Ÿ��
	Image* mirroringHit;	//���ʿ��� Ÿ��

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

