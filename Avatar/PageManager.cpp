#include "PageManager.h"
#include "Resource.h"
#include "HairManager.h"
#include "Utility.h"
#include "Parts.h"
#include "EyebrowManager.h"
#include "EyeManager.h"
#include "NoseManager.h"
#include "MouthManager.h"
#include "BottomsManager.h"
#include "SetManager.h"
#include "AccessoryManager.h"
#include "TopsManager.h"
#include "BackGraphicManager.h"
#include "ShoesManager.h"
#include "AvatarBodyManager.h"
#include "GroupManager.h"
#include "PostManager.h"

const float CPageManager::PartsPosY = 120.0f;

CPageManager::CPageManager(std::shared_ptr<CTask> task):
CActor(task,Float2(470,100),Float2(775,580),0,State::Live),
body(std::make_unique<CAvatarBodyManager>(task))
{
	page.insert(std::make_pair(Page::BackGraphic, std::make_unique<CBackGraphicManager>(task)));
	page.insert(std::make_pair(Page::Bottoms, std::make_unique<CBottomsManager>(task)));
	page.insert(std::make_pair(Page::Tops, std::make_unique<CTopsManager>(task)));
	page.insert(std::make_pair(Page::Shoes, std::make_unique<CShoesManager>(task)));
	page.insert(std::make_pair(Page::Accessory, std::make_unique<CAccessoryManager>(task)));
	page.insert(std::make_pair(Page::Group, std::make_unique<CGroupManager>(task)));

	page.insert(std::make_pair(Page::Hair, std::make_unique<CHairManager>(task)));
	page.insert(std::make_pair(Page::Eyebrow, std::make_unique<CEyebrowManager>(task)));
	page.insert(std::make_pair(Page::Eye, std::make_unique<CEyeManager>(task)));
	page.insert(std::make_pair(Page::Nose, std::make_unique<CNoseManager>(task)));
	page.insert(std::make_pair(Page::Mouth, std::make_unique<CMouthManager>(task)));
	page.insert(std::make_pair(Page::Set, std::make_unique<CSetManager>(task)));

	page.insert(std::make_pair(Page::Post, std::make_unique<CPostManager>(task)));

	ChangePage(Page::Hair);
}

void CPageManager::ChangePage(Page page)
{
	auto it = this->page.find(page);
	now_page = it->second;
}
void CPageManager::Update()
{
	body->Update();
	now_page->Update();
}

void CPageManager::NonSelect()
{
	now_page->NonSelect();
}
void CPageManager::SelectID(const int id)
{
	now_page->SelectID(id);
}

void CPageManager::BodySkineColorNone()
{
	body->BodySkineColorNone();
}

void CPageManager::Reset()
{
	for (auto& it : page)
	{
		it.second->Reset();
	}
}

void CPageManager::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PageGraohic)).resize(size).draw(pos);
	now_page->Draw();

	body->BackDraw();

	for (auto& it : page)
	{
		if (it.first != Page::BackGraphic) continue;
		it.second->PartsDraw();
	}

	body->FrameDraw();

	body->Draw();

	auto draw = page.find(Page::Hair);
	draw->second->PartsDraw();
	draw = page.find(Page::Eyebrow);
	draw->second->PartsDraw();
	draw = page.find(Page::Eye);
	draw->second->PartsDraw();
	draw = page.find(Page::Accessory);
	std::dynamic_pointer_cast<CAccessoryManager>(draw->second)->PartsBackDraw();
	draw = page.find(Page::Bottoms);
	draw->second->PartsDraw();
	draw = page.find(Page::Shoes);
	draw->second->PartsDraw();
	draw = page.find(Page::Tops);
	draw->second->PartsDraw();
	draw = page.find(Page::Accessory);
	std::dynamic_pointer_cast<CAccessoryManager>(draw->second)->PartsFrontDraw();
	draw = page.find(Page::Nose);
	draw->second->PartsDraw();
	draw = page.find(Page::Mouth);
	draw->second->PartsDraw();
	draw = page.find(Page::Group);
	draw->second->PartsDraw();
	draw = page.find(Page::Set);
	draw->second->PartsDraw();
	draw = page.find(Page::Post);
	draw->second->PartsDraw();
}


CPage::CPage(std::shared_ptr<CTask> task, int max_page) :
task(task),
back_pos(Float2(500, 320)),
next_pos(Float2(1130, 340)),
size(Float2(70, 70)),
now_page(0),
max_page(max_page),
select_id(-1){}

void CPage::Reset()
{
	NonSelect();
	select_id = -1;
}

void CPage::BottonUpdate()
{
	if (utility::IsMousePointer(back_pos, size) && Input::MouseL.clicked)
	{
		if (now_page <= 0) return;
		now_page--;
	}

	if (utility::IsMousePointer(next_pos, size) && Input::MouseL.clicked)
	{
		if (now_page >= max_page) return;
		now_page++;
	}
}
void CPage::BottonDraw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Cursol)).mirror().resize(size).draw(back_pos);
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::Cursol)).resize(size).draw(next_pos);
}


void CPage::Update()
{
	BottonUpdate();
	for (auto& it : parts)
	{
		if (it->GetPage() != now_page) continue;
		it->Update();
	}
}

void CPage::NonSelect()
{
	for (auto& it : parts)
	{
		it->StateNone();
	}
}

void CPage::Draw()
{
	BottonDraw();
	for (auto& it : parts)
	{
		if (it->GetPage() != now_page) continue;
		it->Draw();
	}
}