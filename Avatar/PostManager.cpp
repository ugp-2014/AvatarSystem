#include "PostManager.h"
#include "Post.h"
#include "Task.h"
#include "Resource.h"

CPostManager::CPostManager(std::shared_ptr<CTask> task) :
CPage(task, 0)
{
	const int MaxNum = CResource::MaxPostNum;
	Float2 PlacementPos[MaxNum];
	const float PosX = 460;
	const float PosY = CPageManager::PartsPosY + 20;
	const float SpaceX = 120;
	const float SpaceY = 115;

	for (int i = 0; i < 6; i++)
	{
		PlacementPos[i] = Float2(PosX + (i * SpaceX), PosY);
		PlacementPos[i + 6] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 1);
		PlacementPos[i + 6 * 2] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 2);
	}

	for (int i = 0; i < 5; i++)
	{
		PlacementPos[i + 6 * 3] = Float2(PosX + (i * SpaceX), PosY + SpaceY * 3);
	}

	for (auto& it : PlacementPos)
	{
		parts.push_back(std::make_unique<CPost>(task, it, 0));
	}
}

void CPostManager::PartsDraw()
{
	const Float2 BackPos = Float2(130, 150);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetPost(select_id)).draw(BackPos);

}