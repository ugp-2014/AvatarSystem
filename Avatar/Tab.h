#pragma once
#include "Object.h"

class CTab:public Object
{
public:
	CTab(Float2 pos,State state = State::None);

	void Update();
	void Draw();
	void Change();
	void Close();
	
private:
	void Push();
	double alpha;
};

