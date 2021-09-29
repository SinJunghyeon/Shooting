#include "GameObject.h"

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::Render(HDC hdc)
{
}

void GameObject::Release()
{
}

void GameObject::ChangeSceneX(int maxElapsedCount, int maxFrameX)
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

void GameObject::ChangeSceneY(int maxElapsedCount, int maxFrameY)
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

GameObject::GameObject()
{
	GameObject::Init();
}

GameObject::~GameObject()
{
}
