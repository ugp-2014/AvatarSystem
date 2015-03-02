#pragma once
#include <siv3D.hpp>


namespace utility
{

	template<class T>
	static int GetId()
	{
		static int id = 0;
		return id++;
	}

	// ----------------------------------------------------------
	//	指定したボックス内にマウスが存在するかどうか
	//	戻り値 1:存在する 0:存在しない
	// ----------------------------------------------------------
	bool IsMousePointer(const Float2 pos, const Float2 size);



}