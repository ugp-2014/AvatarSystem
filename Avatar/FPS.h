
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include <siv3D.hpp>

///	フレームレート
class CFPS
{
public:
	CFPS();

	void Update();
	void Wait();
	
	static const int FPS = 30;	//設定したFPS
	static const int N = FPS;//平均を取るサンプル数
private:
	void Draw();
	int StartTime;         //測定開始時刻
	int Count;             //カウンタ
	float Fps;             //fps

	TimerMillisec time;
};

