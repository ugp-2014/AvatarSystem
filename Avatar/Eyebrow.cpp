#include "Eyebrow.h"
#include "Utility.h"
#include "PageManager.h"
#include "HairManager.h"
#include "Resource.h"
#include "AvatarManager.h"

CEyebrow::CEyebrow(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CEyebrow>(), page)
{
}
void CEyebrow::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetEyebrow(id)).resize(size * 2).draw(pos + parts_pos);
}