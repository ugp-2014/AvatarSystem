#pragma once
#include "Task.h"

class CAvatarManager
{
public:
	CAvatarManager();
	void Update();
	void Draw();

	static const std::string ResetName;
	static const std::string TabName;
	static const std::string PageName;
	static const std::string ScreenShotName;
private:
	void AvatarBodyCreate();
	std::shared_ptr<CTask> task;
};

