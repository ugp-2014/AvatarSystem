#pragma once
#include "Actor.h"

class CAvatarBodySkinColor;

class CAvatarBody:public Object
{
public:
	CAvatarBody(std::shared_ptr<CTask> task, State state = State::None);

	void Update();
	void Draw();
	void ChangeColor();
	void StateNone();
private:
	std::unique_ptr<CAvatarBodySkinColor> skin;
};

