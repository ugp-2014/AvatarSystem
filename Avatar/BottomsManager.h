#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CBottomsManager :public CPage
{
public:
	CBottomsManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

