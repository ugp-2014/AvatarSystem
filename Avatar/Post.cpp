#include "Post.h"
#include "Utility.h"
#include "Resource.h"

CPost::CPost(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(100, 100), utility::GetId<CPost>(), page)
{
}

void CPost::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetPost(id)).resize(size).draw(pos + parts_pos);
}