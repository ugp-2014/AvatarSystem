#include "HairManager.h"
#include "Hair.h"
#include "Task.h"
#include "Resource.h"

const int MaxNum = 16;
const int Page = CResource::MaxhairNum / MaxNum;

CHairManager::CHairManager(std::shared_ptr<CTask> task):
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
			parts.push_back(std::make_unique<CHair>(task, it,i));
		}
	}
	const float Y = -10;
	const int PartsNum = Page * 16;
	Float2 PartsPos[PartsNum] =
	{
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 1
		Float2(0, 0), Float2(0, 0), Float2(0, -10), Float2(0, 0), Float2(0, 0),	// 2
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 3
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 4
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 5
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 6
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 7
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 8
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 9
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 10
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 11
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 12
		Float2(0, 0), Float2(0, 0), Float2(0, Y), Float2(0, 0), Float2(0, 0),	// 13
		Float2(0, 0), Float2(0, Y), Float2(0, 0), Float2(0, Y), Float2(0, Y),	// 14
		Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, 0), Float2(0, Y),	// 15
		Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, 0),	// 16
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, Y), Float2(0, Y),	// 17
		Float2(0, 0), Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, Y),	// 18
		Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, Y), Float2(0, Y),	// 19
		Float2(0, Y), Float2(0, 0), Float2(0, Y), Float2(0, 0), Float2(0, 0),	// 20
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 21
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 22
		Float2(0, 0), Float2(0, 0), Float2(20, Y), Float2(20, Y), Float2(20, Y),	// 23
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 24
		Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0), Float2(0, 0),	// 25
		Float2(0, 0), Float2(0, 0), Float2(0, 0)
	};


	for (int i = 0; i < PartsNum; i++)
	{
		parts[i]->PartsPoint(PartsPos[i]);
	}


}

void CHairManager::PartsDraw()
{
	const Float2 BackPos = Float2(50, 70);
	if (select_id <= -1) return;
	TextureAsset(CResource::GetInstance().GetHair(select_id)).draw(BackPos);

}