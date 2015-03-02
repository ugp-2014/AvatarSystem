#pragma once
#include <siv3D.hpp>


class Object
{
public:
	enum class State;
	Object(Float2 pos, Float2 size, int id, State state) :
	pos(pos),size(size),id(id),state(state){}
	virtual ~Object() = default;

	virtual void Update() {};
	virtual void Draw(){};

	enum class State
	{
		None,
		Push,
		Live,
	};
	State GetState()const{ return state; }

protected:
	State state;
	Float2 pos;
	Float2 size;
	int id;

};