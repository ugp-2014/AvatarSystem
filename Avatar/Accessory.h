#pragma once

#include "Parts.h"


class CAccessory:public CParts
{
public:
	enum class ZBuffer;
	CAccessory(std::shared_ptr<CTask> task, Float2 pos, int page);
	
	void Select();

	enum class ZBuffer
	{
		Front,
		Back,
	};
	ZBuffer GetZBuffer()const{ return zbuffer; }
	void SetZBuffer(ZBuffer zbuffer){ this->zbuffer = zbuffer; }
private:
	void SelectID();
	void PartsDraw();
	ZBuffer zbuffer;
};

