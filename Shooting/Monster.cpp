#include "Monster.h"

void Monster::Init()
{
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
}

void Monster::Release()
{
}

void Monster::ChangeSceneX(int maxElapsedCount, int maxFrameX)
{
	elapsedCount++;
	if (elapsedCount >= maxElapsedCount) {
		frameX++;
		if (frameX >= maxFrameX) {
			frameX = 0;
		}
		elapsedCount = 0;
	}
}

void Monster::ChangeSceneY(int maxElapsedCount, int maxFrameY)
{
	elapsedCount++;
	if (elapsedCount >= maxElapsedCount) {
		frameY++;
		if (frameY >= maxFrameY) {
			frameY = 0;
		}
		elapsedCount = 0;
	}
}

Monster::Monster()
{
	Monster::Init();
}

Monster::~Monster()
{
}
