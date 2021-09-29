#include "Banana.h"

#include "Image.h"

void Banana::Init()
{
	weaponPos.x = 0.0f;
	weaponPos.y = 100.0f;
	weaponBodySize = 27;
	weaponMoveSpeed = 5.0f;

	weaponShape.left = 0;
	weaponShape.top = 0;
	weaponShape.right = 0;
	weaponShape.bottom = 0;

	move = new Image;
	move->Init("Image/ZombieLupin/Banana/Banana_move.bmp", 540, 54, 10, 1, true, RGB(255, 0, 255));
	mirroringMove = new Image;
	mirroringMove->Init("Image/ZombieLupin/Banana/Banana_mirroringMove.bmp", 540, 54, 10, 1, true, RGB(255, 0, 255));
	hit = new Image;
	hit->Init("Image/ZombieLupin/Banana/Banana_hit.bmp", 162, 54, 3, 1, true, RGB(255, 0, 255));
	mirroringHit = new Image;
	mirroringHit->Init("Image/ZombieLupin/Banana/Banana_mirroringHit.bmp", 162, 54, 3, 1, true, RGB(255, 0, 255));

	elapsedCount = 0;
	frameX = frameY = 0;

	isFire = false;
}

void Banana::Update()
{
	//cout << "Banana isFire : " << boolalpha << isFire << endl;
	//cout << "weaponPos.x : " << weaponPos.x << endl;
	//cout << "weaponPos.y : " << weaponPos.y << endl;
	//cout << endl;

	if (isFire) {
		weaponPos.x += weaponMoveSpeed;

		weaponShape.left = weaponPos.x - (weaponBodySize / 2);
		weaponShape.top = weaponPos.y - (weaponBodySize / 2);
		weaponShape.right = weaponPos.x + (weaponBodySize / 2);
		weaponShape.bottom = weaponPos.y + (weaponBodySize / 2);

		if (weaponShape.left > WIN_SIZE_X || weaponShape.right < 0 || weaponShape.top > WIN_SIZE_Y || weaponShape.bottom < 0) {
			isFire = false;
			weaponPos.x = WIN_SIZE_X / 2.0f + 10.0f;
			frameX = 0;
		}
	}
}

void Banana::Render(HDC hdc)
{
	if (isFire) {
		Ellipse(hdc, weaponShape.left, weaponShape.top, weaponShape.right, weaponShape.bottom);
		cout << "Banana FrameX : " << frameX << endl;
		cout << endl;
		INSERT_WEAPON_IMAGE(move);					//move->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
		ChangeSceneX(10, 9);						//프레임X 변화
		//INSERT_WEAPON_IMAGE(mirroringMove);		//mirroringMove->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
		//ChangeSceneX(10, 9);						//프레임X 변화
		//INSERT_WEAPON_IMAGE(hit);					//hit->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
		//ChangeSceneX(10, 2);						//프레임X 변화
		//INSERT_WEAPON_IMAGE(mirroringHit);		//mirroringHit->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
		//ChangeSceneX(10, 2);						//프레임X 변화
	}
}

void Banana::Release()
{
	SAFE_RELEASE(move);
	SAFE_RELEASE(mirroringMove);
	SAFE_RELEASE(hit);
	SAFE_RELEASE(mirroringHit);
}

Banana::Banana()
{
	Banana::Init();
}

Banana::~Banana()
{
}
