#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CPostManager :public CPage
{
public:
	CPostManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

