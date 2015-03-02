// -------------------------------------------
//			フレームレート設定
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
	//1フレーム目なら時刻を記憶
	if (Count == 0)
	{ 
		StartTime = time.elapsed();
	}
	//設定したフレーム目なら平均を計算する
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
	const int TookTime = time.elapsed() -StartTime;	//かかった時間
	const int WaitTime = Count * 1000 / FPS - TookTime;	//待つべき時間
	if (WaitTime > 0)
	{
		//待機
		Sleep(WaitTime);
	}
}



void CFPS::Draw()
{

}