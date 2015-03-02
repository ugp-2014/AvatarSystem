#include "BackGraphicManager.h"
#include "BackGraphic.h"
#include "Task.h"
#include "Resource.h"

const int MaxNum = 4 * 3;
const int Page = CResource::MaxBackGraphicNum / MaxNum;


CBackGraphicManager::CBackGraphicManager(std::shared_ptr<CTask> task) :
CPage(task, Page-1)
{
	const Float2 framesize(120, 160);
	Float2 PlacementPos[MaxNum];
	const float PosX = 590;
	const float PosY = CPageManager::PartsPosY+20;
	const float SpaceX = framesize.x + 10;
	const float SpaceY = framesize.y + 5;

	for (int i = 0; i < 4; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 4] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
		PlacementPos[i + 4 * 2] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 2);
	}

	for (int i = 0; i < Page; i++)
	{
		for (auto& it : PlacementPos)
		{
			parts.push_back(std::make_unique<CBackGraphic>(task, it,i));
		}
	}

}

void CBackGraphicManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 80);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetBackGraphic(select_id)).draw(BackPos);

}