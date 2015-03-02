#include "NoseManager.h"
#include "Nose.h"
#include "Task.h"
#include "Resource.h"

CNoseManager::CNoseManager(std::shared_ptr<CTask> task) :
CPage(task,0)
{
	const int MaxNum = 3;
	Float2 PlacementPos[MaxNum];
	const float PosX = 550;
	const float PosY = CPageManager::PartsPosY;
	const float SpaceX = 132;
	const float SpaceY = 120;

	for (int i = 0; i < 3; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CNose>(task, it, 0, Float2(-70, -100)));
	}
}

void CNoseManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetNose(select_id)).draw(BackPos);

}