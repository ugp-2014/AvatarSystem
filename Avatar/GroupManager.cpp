#include "GroupManager.h"
#include "Group.h"
#include "Task.h"
#include "Resource.h"

CGroupManager::CGroupManager(std::shared_ptr<CTask> task) :
CPage(task,0)
{
	const int MaxNum = CResource::MaxGroupNum;
	Float2 PlacementPos[MaxNum];
	const float PosX = 460;
	const float PosY = CPageManager::PartsPosY+50;
	const float SpaceX = 120;
	const float SpaceY = 130;

	for (int i = 0; i < 6; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 6] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
		PlacementPos[i + 6 * 2] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 2);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CGroup>(task, it, 0));
	}
}

void CGroupManager::PartsDraw()
{
	const Float2 BackPos = Float2(350, 150);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetGroup(select_id)).draw(BackPos);

}