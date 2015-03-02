#include "AvatarBodySkinColor.h"
#include "Utility.h"
#include "Resource.h"
#include "AvatarBody.h"
#include "AvatarBodyManager.h"
#include "AvatarManager.h"
#include "PageManager.h"

static float NextPosX()
{
	static float next = 0;
	return next += 100;
}

CAvatarBodySkinColor::CAvatarBodySkinColor(std::shared_ptr<CTask> task,State state) :
Object(Float2(10,10) + Float2(NextPosX(),0), Float2(90, 70), utility::GetId<CAvatarBodySkinColor>(), state),
task(task)
{
}


void CAvatarBodySkinColor::Update(CAvatarBody* body)
{
	if (utility::IsMousePointer(pos, size) && Input::MouseL.clicked)
	{
		task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->BodySkineColorNone();
		body->ChangeColor();
	}

}

void CAvatarBodySkinColor::Draw()
{
	TextureAsset(CResource::GetInstance().GetAvatarBodySkin(id)).resize(size).draw(pos);
}