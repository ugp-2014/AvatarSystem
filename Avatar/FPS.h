
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	�t���[�����[�g
class CFPS
{
public:
	CFPS();

	void Update();
	void Wait();
	
	static const int FPS = 30;	//�ݒ肵��FPS
	static const int N = FPS;//���ς����T���v����
private:
	void Draw();
	int StartTime;         //����J�n����
	int Count;             //�J�E���^
	float Fps;             //fps

	TimerMillisec time;
};

