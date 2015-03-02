#include "Utility.h"

namespace utility
{
	// ----------------------------------------------------------
	//	指定したボックス内にマウスが存在するかどうか
	//	戻り値 1:存在する 0:存在しない
	// ----------------------------------------------------------
	bool IsMousePointer(const Float2 pos, const Float2 size)
	{
		const Float2 mouse = Mouse::Pos();

		//ボックス内にマウス座標が存在するか
		if ((mouse.x >= pos.x && mouse.x <= pos.x + size.x) &&
			(mouse.y >= pos.y && mouse.y <= pos.y + size.y)) {
			return true;
		}
		return false;
	}



}