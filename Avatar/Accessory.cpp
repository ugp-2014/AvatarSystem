#include "Accessory.h"
#include "Utility.h"
#include "Resource.h"

CAccessory::CAccessory(std::shared_ptr<CTask> task, Float2 pos, int page) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CAccessory>(), page)
{
}

void CAccessory::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetAccessory(id)).resize(size).draw(pos + parts_pos);
}
void CAccessory::Select()
{
	if (state == State::None)
	{
		SelectID();
	}
	else
	{
		StateNone();
	}
}
void CAccessory::SelectID()
{
	state = State::Select;
}