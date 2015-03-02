#pragma once
#include <vector>
#include "Hair.h"
#include "PageManager.h"
class CTask;

class CHairManager :public CPage
{
public:
	CHairManager(std::shared_ptr<CTask> task);

private:
	void PartsDraw();


};

