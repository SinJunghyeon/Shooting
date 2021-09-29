#pragma once

#include "Config.h"
#include "GameObject.h"

//class ZombieLupin;
class Image;

class Banana : public GameObject
{
private:
	Image* move;
	Image* attack;

	int frameX, frameY;
	int elapsedCount;

	bool isFire;

protected:
	//ZombieLupin* zombieLupin;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void SetIsFire(bool fire);
	inline bool GetIsFire() { return this->isFire; }

	Banana();
	~Banana();
};

