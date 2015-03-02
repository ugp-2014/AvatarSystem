#pragma once

#include "Parts.h"

class CBackGraphic :public CParts
{
public:
	CBackGraphic(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos = Float2(0, 0));

	void Change();
	void Draw();
private:
	void PartsDraw();
};

