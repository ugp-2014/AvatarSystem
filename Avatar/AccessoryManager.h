#pragma once
#include <vector>
#include "PageManager.h"
class CTask;

class CAccessoryManager :public CPage
{
public:
	CAccessoryManager(std::shared_ptr<CTask> task);

	void DeleteSelect();
	void SelectID(const int id);
	void Reset();
	void PartsBackDraw();
	void PartsFrontDraw();

private:
	void PartsDraw(){}
	std::vector<int> id;

};

