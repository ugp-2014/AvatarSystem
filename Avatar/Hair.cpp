#include "Hair.h"
#include "Utility.h"
#include "PageManager.h"
#include "HairManager.h"
#include "Resource.h"
#include "AvatarManager.h"

CHair::CHair(std::shared_ptr<CTask> task, Float2 pos, int page,Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420/2.8, 640/2.8), utility::GetId<CHair>(), page)
{
}

void CHair::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetHair(id)).resize(size).draw(pos + Float2(10,0) + parts_pos);
}