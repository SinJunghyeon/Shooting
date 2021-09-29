#include "ZombieLupin.h"

#include "Banana.h"

void ZombieLupin::Init()
{
	KeyManager::GetSingleton()->Init();

	monsterPos.x = WIN_SIZE_X / 2.0f;
	monsterPos.y = WIN_SIZE_Y - 100.0f;
	monsterBodySize = 40;
	monsterMoveSpeed = 5.0f;

	monsterShape.left = monsterPos.x - monsterBodySize / 2;
	monsterShape.top = monsterPos.y - monsterBodySize / 2;
	monsterShape.right = monsterPos.x + monsterBodySize / 2;
	monsterShape.bottom = monsterPos.y + monsterBodySize / 2;

	banana = new Banana;
	banana->Init();
}

void ZombieLupin::Update()
{
	//cout << "monsterPos.x : " << monsterPos.x << endl;
	//cout << "monsterPos.y : " << monsterPos.y << endl;
	//cout << endl;
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT)) {
		monsterPos.x += monsterMoveSpeed;
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT)) {
		monsterPos.x -= monsterMoveSpeed;
	}
	monsterShape.left = monsterPos.x - monsterBodySize / 2;
	monsterShape.top = monsterPos.y - monsterBodySize / 2;
	monsterShape.right = monsterPos.x + monsterBodySize / 2;
	monsterShape.bottom = monsterPos.y + monsterBodySize / 2;

	banana->Update();
	banana->SetPos(monsterPos);

	if (KeyManager::GetSingleton()->IsOnceKeyDown('A')) {
		banana->SetIsFire(true);
	}
}

void ZombieLupin::Render(HDC hdc)
{
	//cout << "monsterShape.left : " << monsterShape.left << endl;
	//cout << "monsterShape.top : " << monsterShape.top << endl;
	//cout << "monsterShape.right : " << monsterShape.right << endl;
	//cout << "monsterShape.bottom : " << monsterShape.bottom << endl;
	//cout << endl;
	Rectangle(hdc, monsterShape.left, monsterShape.top, monsterShape.right, monsterShape.bottom);

	//Banana
	banana->Render(hdc);
}

void ZombieLupin::Release()
{
	SAFE_RELEASE(banana);
}

ZombieLupin::ZombieLupin()
{
	ZombieLupin::Init();
}

ZombieLupin::~ZombieLupin()
{
}
