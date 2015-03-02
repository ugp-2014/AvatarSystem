#pragma once

#include "Parts.h"


class CPost :public CParts
{
public:
	CPost(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos = Float2(50, 30));

private:
	void PartsDraw();
};

