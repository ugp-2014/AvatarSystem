#pragma once
#include "FPS.h"
#include "AvatarManager.h"

class CAvatarApplication
{
public:
	CAvatarApplication();

	void Update();
	static const int ScreenWidth = 1280;
	static const int ScreenHeight = 720;
private:
	CFPS fps;
	CAvatarManager manager;
};

