#include "Utility.h"

namespace utility
{
	// ----------------------------------------------------------
	//	�w�肵���{�b�N�X���Ƀ}�E�X�����݂��邩�ǂ���
	//	�߂�l 1:���݂��� 0:���݂��Ȃ�
	// ----------------------------------------------------------
	bool IsMousePointer(const Float2 pos, const Float2 size)
	{
		const Float2 mouse = Mouse::Pos();

		//�{�b�N�X���Ƀ}�E�X���W�����݂��邩
		if ((mouse.x >= pos.x && mouse.x <= pos.x + size.x) &&
			(mouse.y >= pos.y && mouse.y <= pos.y + size.y)) {
			return true;
		}
		return false;
	}



}