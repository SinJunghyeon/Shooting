#include "ZombieLupin.h"

#include "Image.h"
#include "KeyManager.h"

void ZombieLupin::Init()
{
	pos.x = 100.0f;
	pos.y = 520.0f;

	bodySize = 50;
	moveSpeed = 10.0f;

	shape.left = pos.x - (bodySize / 2);
	shape.top = pos.y - (bodySize / 2);
	shape.right = shape.left + bodySize;
	shape.bottom = shape.top + bodySize;

	idle = new Image;
	idle->Init("Image/ZombieLupin/ZombieLupin_idle.bmp", 400, 80, 5, 1, true, RGB(255, 0, 255));
	leftMove = new Image;
	leftMove->Init("Image/ZombieLupin/ZombieLupin_leftMove.bmp", 240, 80, 3, 1, true, RGB(255, 0, 255));
	rightMove = new Image;
	rightMove->Init("Image/ZombieLupin/ZombieLupin_rightMove.bmp", 240, 80, 3, 1, true, RGB(255, 0, 255));
	attack = new Image;
	attack->Init("Image/ZombieLupin/ZombieLupin_attack.bmp", 880, 80, 11, 1, true, RGB(255, 0, 255));
	damaged = new Image;
	damaged->Init("Image/ZombieLupin/ZombieLupin_damaged.bmp", 320, 80, 4, 1, true, RGB(255, 0, 255));

	frameX = frameY = 0;
	elapsedCount = 0;

	moveDir = MoveDir::Right;
	state = State::Idle;

	isAttack = false;
	isAlive = true;
}

void ZombieLupin::Update()
{
	cout << "ZombieLupin Left : " << shape.left << endl;
	cout << "ZombieLupin Top : " << shape.top << endl;
	cout << "ZombieLupin Right : " << shape.right << endl;
	cout << "ZombieLupin Bottom : " << shape.bottom << endl;

	shape.left = pos.x - (bodySize / 2);
	shape.top = pos.y - (bodySize / 2);
	shape.right = shape.left + bodySize;
	shape.bottom = shape.top + bodySize;

	if (state == State::Idle)
	{
		isAttack = false;
		state = State::Idle;
	}
	//오른쪽으로 이동
	if (KeyManager::GetSingleton()->IsStayKeyDown(MOVE_RIGHT) && state == State::Idle)
	{
		frameX = 0;
		state = State::Move;
		moveDir = MoveDir::Right;
		isAttack = false;
	}
	//왼쪽으로 이동
	else if (KeyManager::GetSingleton()->IsStayKeyDown(MOVE_LEFT) && state == State::Idle)
	{
		frameX = 0;
		state = State::Move;
		moveDir = MoveDir::Left;
		isAttack = false;
	}
	//이동키를 땠을 때 멈춤
	if (KeyManager::GetSingleton()->IsOnceKeyUp(MOVE_RIGHT) || KeyManager::GetSingleton()->IsOnceKeyUp(MOVE_LEFT))
	{
		frameX = 0;
		isAttack = false;
		state = State::Idle;
	}
	//공격
	if (KeyManager::GetSingleton()->IsOnceKeyDown(BANANA_ATTACK) && !isAttack)
	{
		frameX = 0;
		isAttack = true;
		state = State::Attack;
	}
}

void ZombieLupin::Render(HDC hdc)
{
	cout << "ZombieLupin pos.x : " << pos.x << endl;
	if (idle)
	{
		Rectangle(hdc, shape.left, shape.top, shape.right, shape.bottom);
		switch (state)
		{
		case State::Idle:
			cout << "Idle frameX : " << frameX << endl;
			idle->Render(hdc, pos.x, pos.y - 15, frameX, frameY);
			elapsedCount++;
			if (elapsedCount >= 5)
			{
				elapsedCount = 0;
				frameX++;
				if (frameX >= 4)
				{
					frameX = 0;
				}
			}
			break;
		case State::Move:
			if (moveDir == MoveDir::Right)
			{
				cout << "Move Right frameX : " << frameX << endl;
				rightMove->Render(hdc, pos.x, pos.y - 15, frameX, frameY);
				elapsedCount++;
				if (elapsedCount >= 5)
				{
					elapsedCount = 0;
					frameX++;
					if (frameX >= 2)
					{
						frameX = 0;
					}
				}
				pos.x += moveSpeed / 3;
			}
			else if (moveDir == MoveDir::Left)
			{
				cout << "Move Left frameX : " << frameX << endl;
				leftMove->Render(hdc, pos.x, pos.y - 15, frameX, frameY);
				elapsedCount++;
				if (elapsedCount >= 5)
				{
					elapsedCount = 0;
					frameX++;
					if (frameX >= 2)
					{
						frameX = 0;
					}
				}
				pos.x -= moveSpeed / 3;
			}
			break;
		case State::Attack:
			cout << "Attack frameX : " << frameX << endl;
			attack->Render(hdc, pos.x, pos.y - 15, frameX, frameY);
			elapsedCount++;
			if (elapsedCount >= 10)
			{
				elapsedCount = 0;
				frameX++;
				if (frameX >= 10)
				{
					isAttack = false;
					state = State::Idle;
					frameX = 0;
				}
			}
			break;
		case State::Damaged:
			cout << "Damaged frameX : " << frameX << endl;
			damaged->Render(hdc, pos.x, pos.y - 15, frameX, frameY);
			elapsedCount++;
			if (elapsedCount >= 5)
			{
				elapsedCount = 0;
				frameX++;
				if (frameX >= 3)
				{
					frameX = 0;
				}
			}
			break;
		}
	}
}

void ZombieLupin::Release()
{
	SAFE_RELEASE(idle);
	SAFE_RELEASE(leftMove);
	SAFE_RELEASE(rightMove);
	SAFE_RELEASE(attack);
	SAFE_RELEASE(damaged);
}

ZombieLupin::ZombieLupin()
{
	ZombieLupin::Init();
}

ZombieLupin::~ZombieLupin()
{
}
