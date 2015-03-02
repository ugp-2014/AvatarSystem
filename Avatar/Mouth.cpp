#include "Mouth.h"
#include "Utility.h"
#include "Resource.h"

CMouth::CMouth(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CMouth>(), page)
{
}

void CMouth::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetMouth(id)).resize(size * 2).draw(pos + parts_pos);
}