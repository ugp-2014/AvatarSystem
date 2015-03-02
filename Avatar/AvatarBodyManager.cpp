#include "AvatarBodyManager.h"
#include "AvatarBody.h"
#include "Utility.h"
#include "Resource.h"


CAvatarBodyManager::CAvatarBodyManager(std::shared_ptr<CTask> task)
{
	avatar_body.push_back(std::make_unique<CAvatarBody>(task,State::Live));
	avatar_body.push_back(std::make_unique<CAvatarBody>(task));
	avatar_body.push_back(std::make_unique<CAvatarBody>(task));

}

void CAvatarBodyManager::Update()
{
	for (auto &body : avatar_body)
	{
		body->Update();
	}
}

void CAvatarBodyManager::BodySkineColorNone()
{
	for (auto &body : avatar_body)
	{
		body->StateNone();
	}
}

const Float2 BackPos = Float2(50, 80);

void CAvatarBodyManager::BackDraw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::AvatarBack_1)).draw(BackPos);
}

void CAvatarBodyManager::FrameDraw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::AvatarBack_2)).draw(BackPos);
}

void CAvatarBodyManager::Draw()
{
	for (auto &body : avatar_body)
	{
		body->Draw();
	}
}