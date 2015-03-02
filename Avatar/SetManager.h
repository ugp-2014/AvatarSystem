#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CSetManager :public CPage
{
public:
	CSetManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

