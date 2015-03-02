#pragma once
#include "Actor.h"
#include <map>
#include "PageManager.h"

class CTab;

class CTabManager:public CActor
{
public:
	CTabManager(std::shared_ptr<CTask> task);

	void Update();
	void Draw();

private:
	void PostSelect();
	void Close();
	std::map<CPageManager::Page, std::unique_ptr<CTab>> tab;

};

