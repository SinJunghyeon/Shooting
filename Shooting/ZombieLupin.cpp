#include "ZombieLupin.h"

#include "Image.h"
#include "Banana.h"

void ZombieLupin::Init()
{
	KeyManager::GetSingleton()->Init();

	monsterPos.x = ZOMBIELUPIN_POX_X;
	monsterPos.y = ZOMBIELUPIN_POX_Y;
	monsterBodySize = ZOMBIELUPIN_BODYSIZE;
	monsterMoveSpeed = ZOMBIELUPIN_SPEED;

	monsterShape.left = MONSTER_SIZE_LEFT;
	monsterShape.top = MONSTER_SIZE_TOP;
	monsterShape.right = MONSTER_SIZE_RIGHT;
	monsterShape.bottom = MONSTER_SIZE_BOTTOM;

	idle = new Image;
	idle->Init("Image/ZombieLupin/ZombieLupin_idle.bmp", 80, 80, 1, 1, true, RGB(255,0,255));
	mirroringIdle = new Image;
	mirroringIdle->Init("Image/ZombieLupin/ZombieLupin_mirroringIdle.bmp", 80, 80, 1, 1, true, RGB(255, 0, 255));
	rightMove = new Image;
	rightMove->Init("Image/ZombieLupin/ZombieLupin_rightMove.bmp", 240, 80, 3, 1, true, RGB(255, 0, 255));
	leftMove = new Image;
	leftMove->Init("Image/ZombieLupin/ZombieLupin_leftMove.bmp", 240, 80, 3, 1, true, RGB(255, 0, 255));
	attack = new Image;
	attack->Init("Image/ZombieLupin/ZombieLupin_attack.bmp", 880, 80, 11, 1, true, RGB(255, 0, 255));
	mirroringAttack = new Image;
	mirroringAttack->Init("Image/ZombieLupin/ZombieLupin_mirroringAttack.bmp", 880, 80, 11, 1, true, RGB(255, 0, 255));
	damaged = new Image;
	damaged->Init("Image/ZombieLupin/ZombieLupin_damaged.bmp", 720, 80, 9, 1, true, RGB(255, 0, 255));
	mirroringDamaged = new Image;
	mirroringDamaged->Init("Image/ZombieLupin/ZombieLupin_mirroringDamaged.bmp", 720, 80, 9, 1, true, RGB(255, 0, 255));

	isShoot = false;

	moveDir = MoveDir::Right;
	state = MonsterState::Idle;

	banana = new Banana;
	banana->Init();
}

void ZombieLupin::Update()
{
	InputKey();

	monsterShape.left = MONSTER_SIZE_LEFT;
	monsterShape.top = MONSTER_SIZE_TOP;
	monsterShape.right = MONSTER_SIZE_RIGHT;
	monsterShape.bottom = MONSTER_SIZE_BOTTOM;

	banana->Update();
}

void ZombieLupin::Render(HDC hdc)
{
	//cout << "monsterPos.x : " << monsterPos.x << endl;
	//cout << "monsterPos.y : " << monsterPos.y << endl;
	//cout << "monsterShape.left : " << monsterShape.left << endl;
	//cout << "monsterShape.top : " << monsterShape.top << endl;
	//cout << "monsterShape.right : " << monsterShape.right << endl;
	//cout << "monsterShape.bottom : " << monsterShape.bottom << endl;
	cout << "ZombieLupin isShoot : " << boolalpha << isShoot << endl;
	cout << endl;
	//Rectangle(hdc, MONSTER_SIZE_LEFT - 6.0f, MONSTER_SIZE_TOP + 7.0f, MONSTER_SIZE_RIGHT + 4.0f, MONSTER_SIZE_BOTTOM + 20.0f);
	if (idle || mirroringIdle) {
		switch (state) {
		case MonsterState::Idle:
			//cout << "ZombieLupin Idle FrameX : " << frameX << endl;
			//cout << endl;
			if (moveDir == MoveDir::Right) {
				INSERT_MONSTER_IMAGE(idle);
			}
			else if (moveDir == MoveDir::Left) {
				INSERT_MONSTER_IMAGE(mirroringIdle);
			}
			break;
		case MonsterState::Move:
			//cout << "elapsedCount : " << elapsedCount << endl;
			//cout << "ZombieLupin Move FrameX : " << frameX << endl;
			//cout << endl;
			if (moveDir == MoveDir::Right) {
				INSERT_MONSTER_IMAGE(rightMove);
			}
			else if (moveDir == MoveDir::Left) {
				INSERT_MONSTER_IMAGE(leftMove);
			}
			ChangeSceneX(10, 2);
			break;
		case MonsterState::Attack:
			cout << "elapsedCount : " << elapsedCount << endl;
			cout << "ZombieLupin Attack FrameX : " << frameX << endl;
			cout << endl;
			if (moveDir == MoveDir::Right) {
				INSERT_MONSTER_IMAGE(attack);
			}
			else if (moveDir == MoveDir::Left) {
				INSERT_MONSTER_IMAGE(mirroringAttack);
			}
			elapsedCount++;
			if (elapsedCount >= 10) {
				frameX++;
				if (frameX >= 10) {
					frameX = 0;
					state = MonsterState::Idle;
					isShoot = false;
				}
				elapsedCount = 0;
			}
			break;
		case MonsterState::Damaged:
			cout << "elapsedCount : " << elapsedCount << endl;
			cout << "ZombieLupin Damaged FrameX : " << frameX << endl;
			cout << endl;
			if (moveDir == MoveDir::Right) {
				INSERT_MONSTER_IMAGE(damaged);
			}
			else if (moveDir == MoveDir::Left) {
				INSERT_MONSTER_IMAGE(mirroringDamaged);
			}
			ChangeSceneX(5, 8);
			break;
		}
	}

	//Banana
	banana->Render(hdc);
}

void ZombieLupin::Release()
{
	SAFE_RELEASE(idle);
	SAFE_RELEASE(mirroringIdle);
	SAFE_RELEASE(rightMove);
	SAFE_RELEASE(leftMove);
	SAFE_RELEASE(attack);
	SAFE_RELEASE(mirroringAttack);
	SAFE_RELEASE(damaged);
	SAFE_RELEASE(mirroringDamaged);

	SAFE_RELEASE(banana);

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();
}

void ZombieLupin::InputKey()
{	
	//?????????? ??????
	if (!isShoot) {
		//?????? ???? ?????? ????
		if (KeyManager::GetSingleton()->IsOnceKeyUp(MOVE_RIGHT)) {
			frameX = 0;
			state = MonsterState::Idle;
			moveDir = MoveDir::Right;
			banana->SetDirection(MoveDir::Right);
			isShoot = false;
		}
		//???? ???? ?????? ????
		if (KeyManager::GetSingleton()->IsOnceKeyUp(MOVE_LEFT)) {
			frameX = 0;
			state = MonsterState::Idle;
			moveDir = MoveDir::Left;
			banana->SetDirection(MoveDir::Left);
			isShoot = false;
		}
		//?????? ???? ???????? ????
		if (KeyManager::GetSingleton()->IsStayKeyDown(MOVE_RIGHT) || KeyManager::GetSingleton()->IsOnceKeyDown(MOVE_RIGHT)) {
			state = MonsterState::Move;
			moveDir = MoveDir::Right;
			banana->SetDirection(MoveDir::Right);
			monsterPos.x += monsterMoveSpeed;
			isShoot = false;
		}
		//???? ???? ???????? ????
		else if (KeyManager::GetSingleton()->IsStayKeyDown(MOVE_LEFT) || KeyManager::GetSingleton()->IsOnceKeyDown(MOVE_LEFT)) {
			moveDir = MoveDir::Left;
			state = MonsterState::Move;
			banana->SetDirection(MoveDir::Left);
			monsterPos.x -= monsterMoveSpeed;
			isShoot = false;
		}
	}
	//????
	if (KeyManager::GetSingleton()->IsOnceKeyDown(BANANA_ATTACK) && (state != MonsterState::Damaged) && !isShoot) {
		if (banana->GetIsFire() == false)
		{
			state = MonsterState::Attack;
			isShoot = true;
			banana->SetPos(monsterPos);
			banana->SetIsFire(true);
		}
	}
}

ZombieLupin::ZombieLupin()
{
	ZombieLupin::Init();
}

ZombieLupin::~ZombieLupin()
{
}
