#include "Shoes.h"
#include "Utility.h"
#include "Resource.h"

CShoes::CShoes(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CShoes>(), page)
{
}

void CShoes::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetShoes(id)).resize(size).draw(pos + parts_pos);
}