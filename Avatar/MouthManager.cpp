#include "MouthManager.h"
#include "Mouth.h"
#include "Task.h"
#include "Resource.h"

CMouthManager::CMouthManager(std::shared_ptr<CTask> task) :
CPage(task,0)
{
	const int MaxNum = 12;
	Float2 PlacementPos[MaxNum];
	const float PosX = 550;
	const float PosY = CPageManager::PartsPosY;
	const float SpaceX = 132;
	const float SpaceY = 120;

	for (int i = 0; i < 4; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 4] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
		PlacementPos[i + 4 * 2] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 2);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CMouth>(task, it, 0, Float2(-70, -130)));
	}

}

void CMouthManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetMouth(select_id)).draw(BackPos);

}