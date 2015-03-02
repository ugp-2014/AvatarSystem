#include "EyeManager.h"
#include "Eye.h"
#include "Task.h"
#include "Resource.h"

const int MaxNum = 16;
const int Page = CResource::MaxEyeNum / MaxNum;

CEyeManager::CEyeManager(std::shared_ptr<CTask> task) :
CPage(task, Page-1)
{
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
		PlacementPos[i + 4 * 3] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 3);
	}

	for (int i = 0; i < Page; i++)
	{
		for (auto& it : PlacementPos)
		{
			parts.push_back(std::make_unique<CEye>(task, it, i));
		}
	}



}

void CEyeManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetEye(select_id)).draw(BackPos);

}