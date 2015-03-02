
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <unordered_map>
#include <string> 
#include <memory>

class CActor;

class CTask 
{
	std::unordered_map<std::string, std::shared_ptr<CActor>> object;
public:

	// ------------------------------
	//　Actorを入れる
	// ------------------------------
	void Append(std::string name, std::shared_ptr<CActor> actor);

	// ------------------------------
	//　Actorを空にする
	// ------------------------------
	void Clear();
	
	// ------------------------------
	//　タスクから消去する
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

	// ------------------------------------------------------
	// オブジェクトを取得する（IDまで取得できる）
	// ------------------------------------------------------
	template<typename OBJ>
	std::shared_ptr<OBJ> GetComponent(const std::string& name, const int Id)
	{
		auto it = object.begin();
		it = object.find(name);
		assert(it != object.end());

		return std::dynamic_pointer_cast<OBJ>(it->second->GetComponent(Id));
	}

	// -------------------------------------------------------------
	// オブジェクトを取得する（Actorの中にあるクラスの全体を取得）
	// -------------------------------------------------------------
	std::shared_ptr<CActor>  GetComponents(const std::string& name);

	// ------------------------------------------------------
	//　アクター自体を取得する
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor(const std::string& name);

	// ------------------------------------------
	// オブジェクトの数を取得
	// -----------------------------------------
	int GetNum(const std::string& name);
};
