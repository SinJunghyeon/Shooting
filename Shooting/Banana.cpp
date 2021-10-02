#include "Banana.h"

#include "Image.h"
#include "ZombieLupin.h"

void Banana::Init()
{
	weaponPos.x = BANANA_POX_X;
	weaponPos.y = BANANA_POX_Y;
	weaponBodySize = BANANA_BODYSIZE;
	weaponMoveSpeed = BANANA_SPEED;

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
	weaponDelay = 0;

	bananaDir = MoveDir::Right;
}

void Banana::Update()
{
	cout << "Banana isFire : " << boolalpha << isFire << endl;
	//cout << "weaponPos.x : " << weaponPos.x << endl;
	//cout << "weaponPos.y : " << weaponPos.y << endl;
	//cout << "weaponBodySize : " << weaponBodySize << endl;
	cout << endl;

	if (isFire) {
		if (weaponDelay >= 61) {
			if (bananaDir == MoveDir::Right) {
				weaponPos.x += weaponMoveSpeed;
			}
			else if (bananaDir == MoveDir::Left) {
				weaponPos.x -= weaponMoveSpeed;
			}
			weaponShape.left = WEAPON_SIZE_LEFT;
			weaponShape.top = WEAPON_SIZE_TOP;
			weaponShape.right = WEAPON_SIZE_RIGHT;
			weaponShape.bottom = WEAPON_SIZE_BOTTOM;
		}
	}
}

void Banana::Render(HDC hdc)
{
	if (isFire) {
		cout << "weaponDelay : " << weaponDelay << endl;
		cout << endl;
		weaponDelay++;
		if (weaponDelay >= 62) {
			Ellipse(hdc, WEAPON_SIZE_LEFT, WEAPON_SIZE_TOP, WEAPON_SIZE_RIGHT, WEAPON_SIZE_BOTTOM);
			if (bananaDir == MoveDir::Right) {
				cout << "elapsedCount : " << elapsedCount << endl;
				cout << "Banana move FrameX : " << frameX << endl;
				cout << endl;
				INSERT_WEAPON_IMAGE(move);				//move->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
				}
			else if (bananaDir == MoveDir::Left) {
				cout << "elapsedCount : " << elapsedCount << endl;
				cout << "Banana mirroringMove FrameX : " << frameX << endl;
				cout << endl;
				INSERT_WEAPON_IMAGE(mirroringMove);		//mirroringMove->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);				
				}
				elapsedCount++;
				if (elapsedCount >= 5) {
					frameX++;
					if (frameX >= 9) {
						frameX = 0;
						isFire = false;
						weaponDelay = 0;
					}
					elapsedCount = 0;
				}
			//INSERT_WEAPON_IMAGE(hit);					//hit->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
			//ChangeSceneX(10, 2);						//프레임X 변화
			//INSERT_WEAPON_IMAGE(mirroringHit);		//mirroringHit->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY);
			//ChangeSceneX(10, 2);						//프레임X 변화
		}
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
