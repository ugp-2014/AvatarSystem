#include "Parts.h"
#include "Utility.h"
#include "Resource.h"
#include "PageManager.h"
#include "AvatarManager.h"

CParts::CParts(std::shared_ptr<CTask> task, Float2 pos, Float2 parts_pos, Float2 size, int id, int page) :
task(task), pos(pos), size(size), id(id), state(State::None), parts_pos(parts_pos), page(page)
{
}

void CParts::Update()
{
	Change();
}

const Float2 framepos(40, 20);

void CParts::Change()
{
	if (utility::IsMousePointer(pos + framepos, Float2(120, 120)) && Input::MouseL.clicked)
	{
		Select();
	}
}

void CParts::Draw()
{
	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_1)).
		resize(Float2(120, 120)).draw(pos + framepos);

	PartsDraw();

	TextureAsset(CResource::GetInstance().GetGraphic(CResource::GraphicType::PartsBackGraohic_2)).
		resize(Float2(120, 120)).draw(pos + framepos);

}

void CParts::StateNone()
{
	state = State::None;
}

void CParts::SelectID()
{
	task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->NonSelect();
	state = State::Select;
	task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->SelectID(id);
}

void CParts::NonSelectID()
{
	task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->NonSelect();
	task->GetComponent<CPageManager>(CAvatarManager::PageName, 0)->SelectID(-1);
}

void CParts::Select()
{
	if (state == State::None)
	{
		SelectID();
	}
	else
	{
		NonSelectID();
	}
}
