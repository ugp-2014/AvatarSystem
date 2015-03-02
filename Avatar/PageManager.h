#pragma once
#include "Actor.h"
#include <map>

class CHairManager;
class CPage;
class CParts;
class CAvatarBodyManager;
class CPageManager:public CActor
{
public:
	enum class Page;
	CPageManager(std::shared_ptr<CTask> task);

	void Update();
	void Draw();
	void NonSelect();
	void SelectID(const int id);
	void ChangePage(Page page);
	void BodySkineColorNone();
	void Reset();

	enum class Page
	{
		BackGraphic,
		Hair,
		Accessory,
		Bottoms,
		Shoes,
		Tops,
		Eyebrow,
		Eye,
		Nose,
		Mouth,
		Group,
		Set,
		Post,
	};
	static const float PartsPosY;
private:
	std::map<Page, std::shared_ptr<CPage>> page;
	std::shared_ptr<CPage> now_page;
	std::unique_ptr<CAvatarBodyManager> body;
};

class CPage
{
public:
	CPage(std::shared_ptr<CTask> task,int max_page);

	void Update();
	void Draw();
	void NonSelect();
	virtual void PartsDraw() = 0;
	virtual void Reset();
	virtual void SelectID(const int id){ select_id = id; }
	int GetNowPage()const{ return now_page; }
protected:
	int select_id;
	std::shared_ptr<CTask> task;
	std::vector<std::shared_ptr<CParts>> parts;
private:
	void BottonUpdate();
	void BottonDraw();
	Float2 back_pos;
	Float2 next_pos;
	Float2 size;
	int now_page;
	int max_page;
};