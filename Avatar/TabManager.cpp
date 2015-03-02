#include "TabManager.h"
#include "Tab.h"
#include "PageManager.h"
#include "AvatarManager.h"

const int Tab1X = 500;
const int Tab2X = 550;
const int Tab1Y = 55;
const int Tab2Y = 10;
const int TabWidth = 100;

CTabManager::CTabManager(std::shared_ptr<CTask> task):
CActor(task,Float2(0,0),Float2(0,0),0,State::Live)
{
	tab.insert(std::make_pair(CPageManager::Page::Tops, std::make_unique<CTab>(Float2(Tab2X, Tab2Y))));
	tab.insert(std::make_pair(CPageManager::Page::Bottoms, std::make_unique<CTab>(Float2(Tab2X + (TabWidth * 1), Tab2Y))));
	tab.insert(std::make_pair(CPageManager::Page::Shoes, std::make_unique<CTab>(Float2(Tab2X + (TabWidth * 2), Tab2Y))));
	tab.insert(std::make_pair(CPageManager::Page::Accessory, std::make_unique<CTab>(Float2(Tab2X + (TabWidth * 3), Tab2Y))));
	tab.insert(std::make_pair(CPageManager::Page::BackGraphic, std::make_unique<CTab>(Float2(Tab2X + (TabWidth * 4), Tab2Y))));
	tab.insert(std::make_pair(CPageManager::Page::Group, std::make_unique<CTab>(Float2(Tab2X + (TabWidth * 5), Tab2Y))));

	tab.insert(std::make_pair(CPageManager::Page::Hair, std::make_unique<CTab>(Float2(Tab1X, Tab1Y), State::Live)));
	tab.insert(std::make_pair(CPageManager::Page::Eyebrow, std::make_unique<CTab>(Float2(Tab1X + (TabWidth * 1), Tab1Y))));
	tab.insert(std::make_pair(CPageManager::Page::Eye, std::make_unique<CTab>(Float2(Tab1X + (TabWidth * 2), Tab1Y))));
	tab.insert(std::make_pair(CPageManager::Page::Nose, std::make_unique<CTab>(Float2(Tab1X + (TabWidth * 3), Tab1Y))));
	tab.insert(std::make_pair(CPageManager::Page::Mouth, std::make_unique<CTab>(Float2(Tab1X + (TabWidth * 4), Tab1Y))));
	tab.insert(std::make_pair(CPageManager::Page::Set, std::make_unique<CTab>(Float2(Tab1X + (TabWidth * 5), Tab1Y))));
	
}

void CTabManager::Close()
{
	for (auto& tab : tab)
	{
		tab.second->Close();
	}
}
void CTabManager::PostSelect()
{
	if (Input::KeyU.pressed && Input::KeyG.pressed && Input::KeyP.pressed)
	{
		task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->ChangePage(CPageManager::Page::Post);
	}
}

void CTabManager::Update()
{
	PostSelect();

	for (auto& tab : tab)
	{
		tab.second->Update();
		if (tab.second->GetState() == CTab::State::Push)
		{
			Close();
			tab.second->Change();
			task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->ChangePage(tab.first);
		}
	}
}

void CTabManager::Draw()
{
	const CPageManager::Page Table[] = 
	{
		{ CPageManager::Page::Tops },
		{ CPageManager::Page::Bottoms },
		{ CPageManager::Page::Shoes },
		{ CPageManager::Page::Accessory },
		{ CPageManager::Page::BackGraphic },
		{ CPageManager::Page::Group },
		{ CPageManager::Page::Hair },
		{ CPageManager::Page::Eyebrow },
		{ CPageManager::Page::Eye },
		{ CPageManager::Page::Nose },
		{ CPageManager::Page::Mouth },
		{ CPageManager::Page::Set },
		
	};
	for (auto& i : Table)
	{
		auto it = tab.find(i);
		it->second->Draw();
	}
}
