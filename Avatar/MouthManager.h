#pragma once
#include <vector>
#include "Hair.h"
#include "PageManager.h"
class CTask;

class CMouthManager :public CPage
{
public:
	CMouthManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

