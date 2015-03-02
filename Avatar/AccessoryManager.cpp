#include "AccessoryManager.h"
#include "Accessory.h"
#include "Task.h"
#include "Resource.h"

const int MaxNum = 16;
const int Page = CResource::MaxAccessoryNum / MaxNum;

CAccessoryManager::CAccessoryManager(std::shared_ptr<CTask> task) :
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
			parts.push_back(std::make_unique<CAccessory>(task, it, i));
		}
	}
	struct Info
	{
		Float2 pos;
		CAccessory::ZBuffer zbuffer;
	};
	const int PartsNum = Page * 16;
	Info PartsPos[PartsNum] =
	{
		{ Float2(0, 0), CAccessory::ZBuffer ::Back},
		{ Float2(0, 20), CAccessory::ZBuffer::Back },
		{ Float2(0, 15), CAccessory::ZBuffer::Back },
		{ Float2(40, -70), CAccessory::ZBuffer::Back },
		{ Float2(0, -120), CAccessory::ZBuffer::Back },
		{ Float2(0, -20), CAccessory::ZBuffer::Back },
		{ Float2(0, -20), CAccessory::ZBuffer::Back },
		{ Float2(0, -50), CAccessory::ZBuffer::Back },
		{ Float2(0, -50), CAccessory::ZBuffer::Back },
		{ Float2(0, -120), CAccessory::ZBuffer::Back },

		{ Float2(0, -110), CAccessory::ZBuffer::Back },
		{ Float2(0, -120), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, -50), CAccessory::ZBuffer::Front },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },

		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, -30), CAccessory::ZBuffer::Front },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },

		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },

		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(50, -50), CAccessory::ZBuffer::Back },
		{ Float2(50, -50), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, 0), CAccessory::ZBuffer::Back },
		{ Float2(0, -30), CAccessory::ZBuffer::Front }
	};

	for (int i = 0; i < PartsNum; i++)
	{
		parts[i]->PartsPoint(PartsPos[i].pos);
	}


	for (int i = 0; i < PartsNum; i++)
	{
		std::dynamic_pointer_cast<CAccessory>(parts[i])->SetZBuffer(PartsPos[i].zbuffer);
	}
}
void CAccessoryManager::Reset()
{
	for (auto& it : parts)
	{
		it->StateNone();
	}
	
}
void CAccessoryManager::SelectID(const int id)
{
	for (auto& it : parts)
	{
		if (it->GetId() != id) continue;
		it->Select();
		break;

	}
}

void CAccessoryManager::PartsBackDraw()
{
	const Float2 BackPos = Float2(50, 70);
	for (auto& it : parts)
	{
		if (it->GetState() == CParts::State::None) continue;
		if (std::dynamic_pointer_cast<CAccessory>(it)->GetZBuffer() != CAccessory::ZBuffer::Back) continue;
		TextureAsset(CResource::GetInstance().GetAccessory(it->GetId())).draw(BackPos);
	}
}
void CAccessoryManager::PartsFrontDraw()
{
	const Float2 BackPos = Float2(50, 70);
	for (auto& it : parts)
	{
		if (it->GetState() == CParts::State::None) continue;
		if (std::dynamic_pointer_cast<CAccessory>(it)->GetZBuffer() != CAccessory::ZBuffer::Front) continue;
		TextureAsset(CResource::GetInstance().GetAccessory(it->GetId())).draw(BackPos);
	}
}