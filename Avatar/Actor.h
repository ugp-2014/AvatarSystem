
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Object.h"
#include "Task.h"


//	アクタークラス
class CActor :public Object
{
	std::vector<std::shared_ptr<CActor>> actor;
protected:
	bool isDelete = false;					///<	消去するかを調べる
	std::shared_ptr<CTask> task;	///<	タスク
public:
	CActor() :Object(Float2(0, 0), Float2(0, 0), 0, State::None){}
	CActor(std::shared_ptr<CTask> task, Float2 pos, Float2 size, int id, State state) :
		task(task),Object(pos, size,id,state){}
	
	virtual ~CActor() = default;

	// ------------------------------
	//　オブジェクトを入れる
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//　オブジェクトを空にする
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//　消去する
	// ------------------------------
	void Remove();

	// ----------------------------------
	//　アップデートの前に呼ばれる処理
	// ----------------------------------
	void Start();

	// ------------------------------
	//　アップデート
	// ------------------------------
	void Update();

	// ------------------------------
	//　描画
	// ------------------------------
	void Draw();
	// ------------------------------------------
	// オブジェクトを取得する
	// -----------------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------------------------------
	//　自分自身を取得する
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }


	// ------------------------------------------
	// オブジェクトの数を取得
	// -----------------------------------------
	int GetNum()const{ return actor.size(); }


	// ---------------------------------------------------------------
	//	ダイナミックキャスト
	//	for(auto&)は基本基底クラスCActorの要素しか取得できないが、
	//	これを使用すると派生クラスの要素まで取得できる
	// ----------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}

private:

};

