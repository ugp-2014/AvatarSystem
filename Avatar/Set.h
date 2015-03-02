#pragma once

#include "Parts.h"


class CSet :public CParts
{
public:
	CSet(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos = Float2(0, 0));
	void Draw();
	void Change();
private:
	void PartsDraw();
};

