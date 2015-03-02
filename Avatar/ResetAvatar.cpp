#include "ResetAvatar.h"
#include "Resource.h"
#include "Utility.h"
#include "PageManager.h"
#include "AvatarManager.h"

CResetAvatar::CResetAvatar(std::shared_ptr<CTask> task):
CActor(task,Float2(1000,630),Float2(150,70),0,State::Live)
{
}

void CResetAvatar::Update()
{
	if (utility::IsMousePointer(pos, size) && Input::MouseL.clicked)
	{
		task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->Reset();
	}
}

void CResetAvatar::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Reset)).draw(pos);
}

