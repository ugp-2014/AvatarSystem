#pragma once
#include <siv3d.hpp>
#include "Task.h"

class CParts
{
public:
	CParts(std::shared_ptr<CTask> task, Float2 pos, Float2 parts_pos, Float2 size, int id, int page);
	virtual ~CParts() = default;
	enum class State
	{
		None,
		Push,
		Select,
	};
	int GetId()const{ return id; }
	int GetPage()const{ return page; }
	State GetState()const{ return state; }
	void ChangeStateSelect(){ state = State::Select; }
	void PartsPoint(Float2 pos){ parts_pos = pos; }
	virtual void PartsDraw() = 0;
	virtual void Change();
	void Update();
	virtual void Draw();
	void StateNone();
	virtual void Select();
protected:
	virtual void NonSelectID();
	virtual void SelectID();
	Float2 pos;
	Float2 size;
	State state;
	Float2 parts_pos;
	int page;
	int id;

	std::shared_ptr<CTask> task;
};


