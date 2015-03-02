#include "Tab.h"
#include "Utility.h"
#include "Resource.h"

CTab::CTab(Float2 pos,State state):
Object(pos,Float2(130,100),utility::GetId<CTab>(),state),
alpha(0)
{
}

void CTab::Change()
{
	state = State::Live;
}


void CTab::Close()
{
	state = State::None;
}

void CTab::Push()
{
	if (Input::MouseL.clicked)
	{
		state = State::Push;
	}
}
void CTab::Update()
{
	if (utility::IsMousePointer(Float2(pos.x + 50, pos.y + 10), Float2(size.x / 2, size.y / 3)))
	{
		alpha = 1.0;
		Push();
	}
	else
	{
		alpha = 0.5;
	}

}

void CTab::Draw()
{
	if(state == State::None)
		TextureAsset(CResource::GetInstance().GetTab(id)).resize(size).draw(pos,ColorF(1,1,1,alpha));

	else if (state == State::Live)
		TextureAsset(CResource::GetInstance().GetTab(id)).resize(size).draw(pos);
}