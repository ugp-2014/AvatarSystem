#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CBackGraphicManager :public CPage
{
public:
	CBackGraphicManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

