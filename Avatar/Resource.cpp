#include "Resource.h"
#include <iostream>
#include <sstream>

const String CResource::Path = L"engine\\data\\";

CResource::CResource()
{
	GraphicRead();

	RendererProperty prop = RendererProperty::Forward();
	RendererProperty prop2 = RendererProperty::Forward();
	prop.forwardBlend = BlendState::Default();
	prop.depthWriteEnable = false;
	prop2.forwardBlend = BlendState::Additive();
	prop2.rasterizer = Rasterizer::NoCull_Solid;
	add = new Renderer(prop2);
	alpha = new Renderer(prop);
}

void CResource::PartsRead(String path, int num, std::map<int, String> &parts)
{
	for (int i = 0; i < num; i++)
	{
		const String directory = path + std::to_wstring(i + 1);
		parts.insert(std::make_pair(i, directory));
		const FilePath FileName = Path + directory + L".png";
		TextureAsset::Register(directory, FileName);
	}
}

void CResource::GraphicRead()
{
	graphic.insert(std::make_pair(GraphicType::AvatarBack_1, L"AvatarGraphic\\AvatarBackGraphic"));
	graphic.insert(std::make_pair(GraphicType::AvatarBack_2, L"AvatarGraphic\\AvatarBackGraphic2"));
	graphic.insert(std::make_pair(GraphicType::BackGraphic, L"AvatarGraphic\\UI\\UIBackGraphic"));
	graphic.insert(std::make_pair(GraphicType::PageGraohic, L"AvatarGraphic\\UI\\UIRightBackGraphic"));
	graphic.insert(std::make_pair(GraphicType::PartsBackGraohic_1, L"AvatarGraphic\\UI\\UIPartsBackGraphic"));
	graphic.insert(std::make_pair(GraphicType::PartsBackGraohic_2, L"AvatarGraphic\\UI\\UIParts"));
	graphic.insert(std::make_pair(GraphicType::Cursol, L"AvatarGraphic\\UI\\UICursol"));
	graphic.insert(std::make_pair(GraphicType::Reset, L"AvatarGraphic\\UI\\Reset"));
	graphic.insert(std::make_pair(GraphicType::ScreenShot, L"AvatarGraphic\\UI\\ScreenShot"));

	avatar_body.insert(std::make_pair(0, L"AvatarGraphic\\Avatar"));
	avatar_body.insert(std::make_pair(1, L"AvatarGraphic\\Avatar2"));
	avatar_body.insert(std::make_pair(2, L"AvatarGraphic\\Avatar3"));

	avatar_body_skin.insert(std::make_pair(0, L"AvatarGraphic\\Normal"));
	avatar_body_skin.insert(std::make_pair(1, L"AvatarGraphic\\Brown"));
	avatar_body_skin.insert(std::make_pair(2, L"AvatarGraphic\\White"));

	tab.insert(std::make_pair(0, L"AvatarGraphic\\UI\\UITabTops"));
	tab.insert(std::make_pair(1, L"AvatarGraphic\\UI\\UITabBottoms"));
	tab.insert(std::make_pair(2, L"AvatarGraphic\\UI\\UITabShoes"));
	tab.insert(std::make_pair(3, L"AvatarGraphic\\UI\\UITabAccessory"));
	tab.insert(std::make_pair(4, L"AvatarGraphic\\UI\\UITabBackGraphic"));
	tab.insert(std::make_pair(5, L"AvatarGraphic\\UI\\UITabGroup"));

	tab.insert(std::make_pair(6, L"AvatarGraphic\\UI\\UITabHair"));
	tab.insert(std::make_pair(7, L"AvatarGraphic\\UI\\UITabEyebrow"));
	tab.insert(std::make_pair(8, L"AvatarGraphic\\UI\\UITabEye"));
	tab.insert(std::make_pair(9, L"AvatarGraphic\\UI\\UITabNose"));
	tab.insert(std::make_pair(10, L"AvatarGraphic\\UI\\UITabMouth"));
	tab.insert(std::make_pair(11, L"AvatarGraphic\\UI\\UITabSet"));

	PartsRead(L"髪の毛\\", MaxhairNum,hair);
	PartsRead(L"眉毛\\", MaxEyebrowNum,eyebrow);
	PartsRead(L"目\\", MaxEyeNum,eye);
	PartsRead(L"鼻\\", MaxNoseNum, nose);
	PartsRead(L"口\\", MaxMouthNum, mouth);
	PartsRead(L"トップス\\", MaxTopsNum,tops);
	PartsRead(L"ボトムス\\", MaxBottomsNum,bottoms);
	PartsRead(L"靴\\", MaxShoesNum,shoes);
	PartsRead(L"セット\\", MaxShoesNum,set);
	PartsRead(L"アクセサリー\\", MaxAccessoryNum, accessory);
	PartsRead(L"背景\\", MaxBackGraphicNum, backgraphic);


	group.insert(std::make_pair(0, L"AvatarGraphic\\班\\Entertainment"));
	group.insert(std::make_pair(1, L"AvatarGraphic\\班\\Entertainment2"));
	group.insert(std::make_pair(2, L"AvatarGraphic\\班\\Entertainment3"));

	group.insert(std::make_pair(3, L"AvatarGraphic\\班\\Graphics"));
	group.insert(std::make_pair(4, L"AvatarGraphic\\班\\Graphics2"));
	group.insert(std::make_pair(5, L"AvatarGraphic\\班\\Graphics3"));

	group.insert(std::make_pair(6, L"AvatarGraphic\\班\\Music"));
	group.insert(std::make_pair(7, L"AvatarGraphic\\班\\Music2"));
	group.insert(std::make_pair(8, L"AvatarGraphic\\班\\Music3"));

	group.insert(std::make_pair(9, L"AvatarGraphic\\班\\Programmer"));
	group.insert(std::make_pair(10, L"AvatarGraphic\\班\\Programmer2"));
	group.insert(std::make_pair(11, L"AvatarGraphic\\班\\Programmer3"));

	group.insert(std::make_pair(12, L"AvatarGraphic\\班\\Scenario"));
	group.insert(std::make_pair(13, L"AvatarGraphic\\班\\Scenario2"));
	group.insert(std::make_pair(14, L"AvatarGraphic\\班\\Scenario3"));

	group.insert(std::make_pair(15, L"AvatarGraphic\\班\\Editorial"));
	group.insert(std::make_pair(16, L"AvatarGraphic\\班\\Editorial2"));
	group.insert(std::make_pair(17, L"AvatarGraphic\\班\\Editorial3"));


	post.insert(std::make_pair(0, L"AvatarGraphic\\エンブレム\\Director"));
	post.insert(std::make_pair(1, L"AvatarGraphic\\エンブレム\\Director2"));
	post.insert(std::make_pair(2, L"AvatarGraphic\\エンブレム\\Controller"));

	post.insert(std::make_pair(3, L"AvatarGraphic\\エンブレム\\PlanningProduction"));
	post.insert(std::make_pair(4, L"AvatarGraphic\\エンブレム\\PlanningProduction2"));
	post.insert(std::make_pair(5, L"AvatarGraphic\\エンブレム\\PlanningProduction3"));

	post.insert(std::make_pair(6, L"AvatarGraphic\\エンブレム\\GeneralAffairsDepartment"));
	post.insert(std::make_pair(7, L"AvatarGraphic\\エンブレム\\GeneralAffairsDepartment2"));
	post.insert(std::make_pair(8, L"AvatarGraphic\\エンブレム\\GeneralAffairsDepartment3"));

	post.insert(std::make_pair(9, L"AvatarGraphic\\エンブレム\\PlanningManagement"));
	post.insert(std::make_pair(10, L"AvatarGraphic\\エンブレム\\PlanningManagement2"));
	post.insert(std::make_pair(11, L"AvatarGraphic\\エンブレム\\PlanningManagement3"));

	post.insert(std::make_pair(12, L"AvatarGraphic\\エンブレム\\Information"));
	post.insert(std::make_pair(13, L"AvatarGraphic\\エンブレム\\Information2"));
	post.insert(std::make_pair(14, L"AvatarGraphic\\エンブレム\\Information3"));

	post.insert(std::make_pair(15, L"AvatarGraphic\\エンブレム\\Humanly"));
	post.insert(std::make_pair(16, L"AvatarGraphic\\エンブレム\\Humanly2"));
	post.insert(std::make_pair(17, L"AvatarGraphic\\エンブレム\\Humanly3"));

	post.insert(std::make_pair(18, L"AvatarGraphic\\エンブレム\\Operation"));
	post.insert(std::make_pair(19, L"AvatarGraphic\\エンブレム\\Operation2"));
	post.insert(std::make_pair(20, L"AvatarGraphic\\エンブレム\\Operation3"));

	post.insert(std::make_pair(21, L"AvatarGraphic\\エンブレム\\Management"));
	post.insert(std::make_pair(22, L"AvatarGraphic\\エンブレム\\Management2"));


	for (auto& graph : post)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}


	for (auto& graph : group)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}

	for (auto& graph : graphic)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}

	for (auto& graph : avatar_body)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}
	for (auto& graph : avatar_body_skin)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}
	for (auto& graph : tab)
	{
		const FilePath FileName = Path + graph.second + L".png";
		TextureAsset::Register(graph.second, FileName);
	}
}