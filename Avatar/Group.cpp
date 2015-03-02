#include "Group.h"
#include "Utility.h"
#include "Resource.h"

CGroup::CGroup(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(100,100), utility::GetId<CGroup>(), page)
{
}

void CGroup::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetGroup(id)).resize(size).draw(pos + parts_pos);
}