#pragma once
#include "Actor.h"

class CResetAvatar:public CActor
{
public:
	CResetAvatar(std::shared_ptr<CTask> task);

	void Update();
	void Draw();
private:

};

