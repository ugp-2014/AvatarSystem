
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <siv3D.hpp>
#include <memory>
#include <map>
#include <array>

///	リソース管理
class CResource
{
public:
	CResource();

	static CResource &GetInstance()
	{
		static CResource instance;
		return instance;
	}

	//　グラフィックの種類
	enum class GraphicType
	{
		BackGraphic,
		PageGraohic,
		PartsBackGraohic_1,
		PartsBackGraohic_2,
		AvatarBack_1,
		AvatarBack_2,
		Reset,
		Cursol,
		ScreenShot,
		Max_GraphicType,
	};

	String GetGraphic(const GraphicType type)
	{
		auto it = graphic.find(type);
		return it->second;
	}
	String GetAvatarBody(const int type)
	{
		auto it = avatar_body.find(type);
		return it->second;
	}

	String GetAvatarBodySkin(const int type)
	{
		auto it = avatar_body_skin.find(type);
		return it->second;
	}

	String GetTab(const int type)
	{
		auto it = tab.find(type);
		return it->second;
	}

	String GetHair(const int type)
	{
		auto it = hair.find(type);
		return it->second;
	}
	String GetEye(const int type)
	{
		auto it = eye.find(type);
		return it->second;
	}
	String GetEyebrow(const int type)
	{
		auto it = eyebrow.find(type);
		return it->second;
	}
	String GetNose(const int type)
	{
		auto it = nose.find(type);
		return it->second;
	}
	String GetMouth(const int type)
	{
		auto it = mouth.find(type);
		return it->second;
	}

	String GetTops(const int type)
	{
		auto it = tops.find(type);
		return it->second;
	}

	String GetBottoms(const int type)
	{
		auto it = bottoms.find(type);
		return it->second;
	}

	String GetShoes(const int type)
	{
		auto it = shoes.find(type);
		return it->second;
	}
	String GetAccessory(const int type)
	{
		auto it = accessory.find(type);
		return it->second;
	}
	String GetSet(const int type)
	{
		auto it = set.find(type);
		return it->second;
	}

	String GetBackGraphic(const int type)
	{
		auto it = backgraphic.find(type);
		return it->second;
	}

	String GetGroup(const int type)
	{
		auto it = group.find(type);
		return it->second;
	}

	String GetPost(const int type)
	{
		auto it = post.find(type);
		return it->second;
	}

	Renderer* GetAddRenderer(){ return add; }
	Renderer* GetAlphaRenderer(){ return alpha; }

	static const int MaxhairNum = 129;
	static const int MaxEyeNum = 47;
	static const int MaxEyebrowNum = 8;
	static const int MaxNoseNum = 3;
	static const int MaxMouthNum = 12;

	static const int MaxTopsNum = 53;
	static const int MaxBottomsNum = 30;
	static const int MaxShoesNum = 19;
	static const int MaxSetNum = 8;
	static const int MaxAccessoryNum = 63;
	static const int MaxBackGraphicNum = 45;
	static const int MaxGroupNum = 18;
	static const int MaxPostNum = 23;

private:
	static const String Path;

	void PartsRead(String path, int num, std::map<int, String>& parts);
	void GraphicRead();

	std::map<GraphicType, String> graphic;
	std::map<int, String> avatar_body;
	std::map<int, String> avatar_body_skin;
	std::map<int, String> tab;

	std::map<int, String> hair;
	std::map<int, String> eye;
	std::map<int, String> eyebrow;
	std::map<int, String> nose;
	std::map<int, String> mouth;
	std::map<int, String> tops;
	std::map<int, String> bottoms;
	std::map<int, String> shoes;
	std::map<int, String> set;
	std::map<int, String> accessory;
	std::map<int, String> backgraphic;
	std::map<int, String> group;
	std::map<int, String> post;

	Renderer *add;
	Renderer *alpha;
	
};

