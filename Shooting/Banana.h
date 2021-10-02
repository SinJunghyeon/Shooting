#pragma once

#include "Config.h"
#include "Weapon.h"

class Banana : public Weapon
{
private:
	Image* move;			//���������� �̵�
	Image* mirroringMove;	//�������� �̵�
	Image* hit;				//�����ʿ��� Ÿ��
	Image* mirroringHit;	//���ʿ��� Ÿ��

	MoveDir bananaDir;

protected:

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetDirection(MoveDir bananaDir) { this->bananaDir = bananaDir; }
	inline MoveDir GetDirection() { return this->bananaDir; }

	Banana();
	~Banana();
};

