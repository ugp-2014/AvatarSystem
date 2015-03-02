#include "AvatarBody.h"
#include "Utility.h"
#include "Resource.h"
#include "AvatarBodySkinColor.h"

CAvatarBody::CAvatarBody(std::shared_ptr<CTask> task, State state) :
Object(Float2(50, 70), Float2(420, 640), utility::GetId<CAvatarBody>(), state),
skin(std::make_unique<CAvatarBodySkinColor>(task,state))
{
}


void CAvatarBody::Update()
{
	skin->Update(this);
}

void CAvatarBody::StateNone()
{
	state = State::None;
}
void CAvatarBody::ChangeColor()
{
	state = State::Live;
}

void CAvatarBody::Draw()
{
	skin->Draw();
	if (state == State::Live)
	{
		TextureAsset(CResource::GetInstance().GetAvatarBody(id)).resize(size).draw(pos);
	}
}