#pragma once

#include "Config.h"
#include "KeyManager.h"

class Image;

class GameObject
{
private:

protected:
	int elapsedCount;
	int frameX, frameY;

	enum class MoveDir { Left, Right, Up, Down };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void ChangeSceneX(int maxElapsedCount, int maxFrameX);	//프레임X가 바뀔 때
	void ChangeSceneY(int maxElapsedCount, int maxFrameY);	//프레임Y가 바뀔 때

	GameObject();
	~GameObject();

};

