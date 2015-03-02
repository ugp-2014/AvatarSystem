// -------------------------------------------
//			�t���[�����[�g�ݒ�
//					code by yamada masamitsu
// -------------------------------------------

#include "FPS.h"
#include <windows.h>

CFPS::CFPS() :
StartTime(0), 
Count(0), 
Fps(0)
{
	time.start();
}

void CFPS::Update()
{
	//1�t���[���ڂȂ玞�����L��
	if (Count == 0)
	{ 
		StartTime = time.elapsed();
	}
	//�ݒ肵���t���[���ڂȂ畽�ς��v�Z����
	if (Count == N)
	{
		int t = time.elapsed();
		Fps = 1000.f / ((t - StartTime) / (float)N);
		Count = 0;
		StartTime = t;
	}
	Count++;

}




void CFPS::Wait()
{
	const int TookTime = time.elapsed() -StartTime;	//������������
	const int WaitTime = Count * 1000 / FPS - TookTime;	//�҂ׂ�����
	if (WaitTime > 0)
	{
		//�ҋ@
		Sleep(WaitTime);
	}
}



void CFPS::Draw()
{

}