#include "ScreenShot.h"
#include "Resource.h"
#include "Utility.h"
#include"AvatarManager.h"
#include <windows.h>
CScreenShot::CScreenShot(std::shared_ptr<CTask> task):
CActor(task,Float2(1180,10),Float2(100,100),0,State::None),
alpha(0.5)
{
}

void CScreenShot::Push()
{
	if (Input::MouseL.clicked)
	{
		Graphics::RequestScreenCapture();
		state = State::Push;
	}
}

void CScreenShot::Update()
{
	if (state == State::Push)
	{
		state = State::None;
		const Image image = Graphics::ReceiveScreenCapture();
		static int num = 1;
		const String Num = std::to_wstring(num);
		const String Path = L"AvatarIcon/Avatar";
		const FilePath FileName1 = Path + L"Body" + Num + L".png";
		image.getRect(80, 120, 360, 570).save(FileName1);

		const FilePath FileName2 = Path + L"Face" + Num + L".png";
		image.getRect(130, 130, 315, 290).save(FileName2);

		MessageBox(NULL, TEXT("ÇÊÇ≠Ç≈Ç´Ç‹ÇµÇΩÅ`Å`ÅI"), TEXT("OK"), MB_OK);
		num++;
	}

	if (utility::IsMousePointer(pos, size))
	{
		alpha = 1.0;
		Push();
	}
	else
	{
		alpha = 0.5;
	}

}

void CScreenShot::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::ScreenShot)).resize(size).draw(pos,ColorF(1,1,1,alpha));
}