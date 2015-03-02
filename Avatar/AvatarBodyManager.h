#pragma once

#include "Actor.h"

class CAvatarBody;

class CAvatarBodyManager:public CActor
{
public:
	CAvatarBodyManager(std::shared_ptr<CTask> task);

	void Update();
	void Draw();
	void BodySkineColorNone();
	void BackDraw();
	void FrameDraw();
private:
	std::vector<std::unique_ptr<CAvatarBody>> avatar_body;
};

