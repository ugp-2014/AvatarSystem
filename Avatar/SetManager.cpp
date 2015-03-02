#include "SetManager.h"
#include "Set.h"
#include "Task.h"
#include "Resource.h"

CSetManager::CSetManager(std::shared_ptr<CTask> task) :
CPage(task, 0)
{
	const Float2 framesize(120, 200);
	const int MaxNum = 8;
	Float2 PlacementPos[MaxNum];
	const float PosX = 550;
	const float PosY = CPageManager::PartsPosY+30;
	const float SpaceX = 132;
	const float SpaceY = 20 + framesize.y;

	for (int i = 0; i < 4; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 4] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CSet>(task, it, 0,Float2(0,-50)));
	}
}

void CSetManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetSet(select_id)).draw(BackPos);
}