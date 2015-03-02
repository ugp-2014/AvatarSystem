#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CTopsManager :public CPage
{
public:
	CTopsManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

