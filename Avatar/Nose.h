#pragma once

#include "Parts.h"


class CNose:public CParts
{
public:
	CNose(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos = Float2(0, 0));

private:
	void PartsDraw();
};

