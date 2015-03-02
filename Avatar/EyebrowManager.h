#pragma once

#include <vector>
#include "Hair.h"
#include "PageManager.h"
class CTask;

class CEyebrowManager :public CPage
{
public:
	CEyebrowManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();

};

