#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CGroupManager :public CPage
{
public:
	CGroupManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

