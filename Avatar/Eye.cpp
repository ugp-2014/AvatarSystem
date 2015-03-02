#include "Eye.h"
#include "Utility.h"
#include "Resource.h"

CEye::CEye(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CEye>(), page)
{
}

void CEye::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetEye(id)).resize(size).draw(pos + parts_pos);
}