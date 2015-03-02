
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
	//�@Actor������
	// ------------------------------
	void Append(std::string name, std::shared_ptr<CActor> actor);

	// ------------------------------
	//�@Actor����ɂ���
	// ------------------------------
	void Clear();
	
	// ------------------------------
	//�@�^�X�N�����������
	// ------------------------------
	void Remove();

	// ----------------------------------
	//�@�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
	// ----------------------------------
	void Start();
	
	// ------------------------------
	//�@�A�b�v�f�[�g
	// ------------------------------
	void Update();
	
	// ------------------------------
	//�@�`��
	// ------------------------------
	void Draw();

	// ------------------------------------------------------
	// �I�u�W�F�N�g���擾����iID�܂Ŏ擾�ł���j
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
	// �I�u�W�F�N�g���擾����iActor�̒��ɂ���N���X�̑S�̂��擾�j
	// -------------------------------------------------------------
	std::shared_ptr<CActor>  GetComponents(const std::string& name);

	// ------------------------------------------------------
	//�@�A�N�^�[���̂��擾����
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor(const std::string& name);

	// ------------------------------------------
	// �I�u�W�F�N�g�̐����擾
	// -----------------------------------------
	int GetNum(const std::string& name);
};
