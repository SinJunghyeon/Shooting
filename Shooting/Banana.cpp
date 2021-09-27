#include "Banana.h"

#include "ZombieLupin.h"
#include "Image.h"
#include "KeyManager.h"

void Banana::Init()
{
	zombieLupin = new ZombieLupin;
	zombieLupin->Init();
	//POINTFLOAT zombieLupinPos = zombieLupin->GetPos();
	pos.x = zombieLupin->GetPos().x + 20;	//pos.x = zombieLupinPos.x + 20;
	pos.y = zombieLupin->GetPos().y;		//pos.y = zombieLupinPos.y;

	bodySize = 27;
	moveSpeed = 10.0f;

	shape.left = pos.x - (bodySize / 2);
	shape.top = pos.y - (bodySize / 2);
	shape.right = shape.left + bodySize;
	shape.bottom = shape.top + bodySize;

	move = new Image;
	move->Init("Image/ZombieLupin/Banana/Banana_move.bmp", 540, 54, 10, 1, true, RGB(255, 0, 255));
	attack = new Image;
	attack->Init("Image/ZombieLupin/Banana/Banana_attack.bmp", 164, 54, 3, 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;

	isFire = false;
}

void Banana::Update()
{
	if (isFire)
	{
		pos.x += moveSpeed / 3;
		pos.y = pos.y;

		shape.left = pos.x - (bodySize / 2);
		shape.top = pos.y - (bodySize / 2);
		shape.right = shape.left + bodySize;
		shape.bottom = shape.top + bodySize;
	}
}

void Banana::Render(HDC hdc)
{
	if (isFire)
	{
		cout << "Banana pos.x : " << pos.x << endl;
		cout << "Banana pos.y : " << pos.y << endl;
		cout << endl;

		Ellipse(hdc, shape.left, shape.top, shape.right, shape.bottom);

		cout << "Banana : " << frameX << endl;
		move->Render(hdc, pos.x, pos.y, frameX, frameY);
		elapsedCount++;
		if (elapsedCount == 5)
		{
			elapsedCount = 0;
			frameX++;
			if (frameX >= 9)
			{
				frameX = 0;
				isFire = false;
			}
		}

		if (shape.left >= 1280)
		{
			pos.x = zombieLupin->GetPos().x + 20;
		}
	}
}

void Banana::Release()
{
	SAFE_RELEASE(move);
	SAFE_RELEASE(attack);
}

void Banana::SetIsFire(bool fire)
{
	this->isFire = fire;
}

Banana::Banana()
{
	Banana::Init();
}

Banana::~Banana()
{
}
