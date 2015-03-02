#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CShoesManager :public CPage
{
public:
	CShoesManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

