#include "Set.h"
#include "Utility.h"
#include "Resource.h"

const Float2 framesize(120, 200);
const Float2 framepos(40, 20);

CSet::CSet(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CSet>(), page)
{
}

void CSet::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetSet(id)).resize(size).draw(pos + parts_pos);
}

void CSet::Change()
{
	if (utility::IsMousePointer(pos + framepos, framesize) && Input::MouseL.clicked)
	{
		Select();
	}

}

void CSet::Draw()
{

	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_1)).
		resize(framesize).draw(pos + framepos);

	PartsDraw();

	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_2)).
		resize(framesize).draw(pos + framepos);

}