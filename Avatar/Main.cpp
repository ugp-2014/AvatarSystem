
# include <Siv3D.hpp>
#include "AvatarApplication.h"

void Main()
{
	Window::Resize(CAvatarApplication::ScreenWidth, CAvatarApplication::ScreenHeight);
	CAvatarApplication app;
	while (System::Update())
	{
		app.Update();
	}
}
