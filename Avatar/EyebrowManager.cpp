#include "EyebrowManager.h"
#include "Eyebrow.h"
#include "Task.h"
#include "Resource.h"

CEyebrowManager::CEyebrowManager(std::shared_ptr<CTask> task) :
CPage(task, 0)
{
	const int MaxNum = 8;
	Float2 PlacementPos[MaxNum];
	const float PosX = 550;
	const float PosY = CPageManager::PartsPosY;
	const float SpaceX = 132;
	const float SpaceY = 120;

	for (int i = 0; i < 4; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 4] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CEyebrow>(task, it, 0,Float2(-70,-100)));
	}
}

void CEyebrowManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetEyebrow(select_id)).draw(BackPos);

}