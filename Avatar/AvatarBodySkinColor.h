#pragma once
#include "Object.h"

class CTask;
class CAvatarBody;
class CAvatarBodySkinColor:public Object
{
public:
	CAvatarBodySkinColor(std::shared_ptr<CTask> task,State state);
	
	void Update(CAvatarBody* body);
	void Draw();

private:
	std::shared_ptr<CTask> task;
};

