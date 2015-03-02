#include "BackGraphic.h"
#include "Utility.h"
#include "Resource.h"

const Float2 framesize(120, 160);

CBackGraphic::CBackGraphic(std::shared_ptr<CTask> task, Float2 pos, int page, Float2 parts_pos) :
CParts(task, pos, parts_pos, Float2(420 / 2.5, 640 / 2.5), utility::GetId<CBackGraphic>(), page)
{
}

void CBackGraphic::PartsDraw()
{
	TextureAsset(CResource::GetInstance().GetBackGraphic(id)).resize(framesize).draw(pos);
}

void CBackGraphic::Change()
{
	if (utility::IsMousePointer(pos, framesize) && Input::MouseL.clicked)
	{
		Select();
	}
}

void CBackGraphic::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_1)).
		resize(framesize).draw(pos);

	PartsDraw();

	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_2)).
		resize(framesize).draw(pos);

}