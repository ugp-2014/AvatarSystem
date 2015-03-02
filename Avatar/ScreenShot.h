#pragma once
#include "Actor.h"

class CScreenShot:public CActor
{
public:
	CScreenShot(std::shared_ptr<CTask> task);
	void Update();
	void Draw();
private:
	void Push();
	double alpha;
};

