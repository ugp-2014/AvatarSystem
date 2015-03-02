#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CNoseManager :public CPage
{
public:
	CNoseManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

