#include "AvatarManager.h"
#include "AvatarBodyManager.h"
#include "Resource.h"
#include "TabManager.h"
#include "PageManager.h"
#include "ResetAvatar.h"
#include "ScreenShot.h"

const std::string CAvatarManager::ResetName = "reset";
const std::string CAvatarManager::TabName = "tab";
const std::string CAvatarManager::PageName = "page";
const std::string CAvatarManager::ScreenShotName = "screenshot";

CAvatarManager::CAvatarManager() :
task(std::make_shared<CTask>())
{
	AvatarBodyCreate();
}

void CAvatarManager::AvatarBodyCreate()
{
	auto tab = std::make_shared<CActor>();
	tab->Append(std::make_shared<CTabManager>(task));
	task->Append(TabName, tab);

	auto page = std::make_shared<CActor>();
	page->Append(std::make_shared<CPageManager>(task));
	task->Append(PageName, page);

	auto reset = std::make_shared<CActor>();
	reset->Append(std::make_shared<CResetAvatar>(task));
	task->Append(ResetName, reset);

	auto screenshot = std::make_shared<CActor>();
	screenshot->Append(std::make_shared<CScreenShot>(task));
	task->Append(ScreenShotName, screenshot);
}

void CAvatarManager::Update()
{
	task->Update();

}
void CAvatarManager::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::BackGraphic)).draw(0,0);

	task->Draw();
	task->Remove();

}