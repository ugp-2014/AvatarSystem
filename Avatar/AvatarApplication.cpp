#include "AvatarApplication.h"
#include "Resource.h"

CAvatarApplication::CAvatarApplication()
{
	Window::SetTitle(L"AvatarSystem");
	CResource::GetInstance();
	const Image image = Image(L"engine\\splash.png");
	Window::SetIcon(image);

}


void CAvatarApplication::Update()
{
	fps.Wait();
	manager.Update();
	manager.Draw();
	fps.Update();

}