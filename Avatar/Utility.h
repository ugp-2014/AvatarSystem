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
	//	�w�肵���{�b�N�X���Ƀ}�E�X�����݂��邩�ǂ���
	//	�߂�l 1:���݂��� 0:���݂��Ȃ�
	// ----------------------------------------------------------
	bool IsMousePointer(const Float2 pos, const Float2 size);



}