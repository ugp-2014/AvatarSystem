#pragma once
#include <vector>
#include "Hair.h"
#include "PageManager.h"
class CTask;

class CEyeManager :public CPage
{
public:
	CEyeManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

