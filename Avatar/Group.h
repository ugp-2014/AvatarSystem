#pragma once

#include "Parts.h"


class CGroup :public CParts
{
public:
	CGroup(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos = Float2(50,30));

private:
	void PartsDraw();
};

