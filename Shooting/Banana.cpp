#include "Banana.h"

void Banana::Init()
{
	weaponPos.x = WIN_SIZE_X / 2.0f + 10.0f;
	weaponPos.y = WIN_SIZE_Y - 100.0f;
	weaponBodySize = 27;
	weaponMoveSpeed = 10.0f;

	weaponShape.left = 0;
	weaponShape.top = 0;
	weaponShape.right = 0;
	weaponShape.bottom = 0;

	isFire = false;
}

void Banana::Update()
{
	if (isFire) {
		cout << "weaponPos.x : " << weaponPos.x << endl;
		cout << "weaponPos.y : " << weaponPos.y << endl;
		cout << endl;

		weaponPos.x += weaponMoveSpeed;

		weaponShape.left = weaponPos.x - (weaponBodySize / 2);
		weaponShape.top = weaponPos.y - (weaponBodySize / 2);
		weaponShape.right = weaponPos.x + (weaponBodySize / 2);
		weaponShape.bottom = weaponPos.y + (weaponBodySize / 2);

		if (weaponShape.left > WIN_SIZE_X || weaponShape.right < 0 || weaponShape.top > WIN_SIZE_Y || weaponShape.bottom < 0) {
			isFire = false;
			weaponPos.x = WIN_SIZE_X / 2.0f + 10.0f;
		}
	}
}

void Banana::Render(HDC hdc)
{
	if (isFire) {
		Ellipse(hdc, weaponShape.left, weaponShape.top, weaponShape.right, weaponShape.bottom);
	}
}

void Banana::Release()
{
}

Banana::Banana()
{
	Banana::Init();
}

Banana::~Banana()
{
}
