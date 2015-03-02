
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once
#include "Object.h"
#include "Task.h"


//	�A�N�^�[�N���X
class CActor :public Object
{
	std::vector<std::shared_ptr<CActor>> actor;
protected:
	bool isDelete = false;					///<	�������邩�𒲂ׂ�
	std::shared_ptr<CTask> task;	///<	�^�X�N
public:
	CActor() :Object(Float2(0, 0), Float2(0, 0), 0, State::None){}
	CActor(std::shared_ptr<CTask> task, Float2 pos, Float2 size, int id, State state) :
		task(task),Object(pos, size,id,state){}
	
	virtual ~CActor() = default;

	// ------------------------------
	//�@�I�u�W�F�N�g������
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//�@�I�u�W�F�N�g����ɂ���
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//�@��������
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
	// ------------------------------------------
	// �I�u�W�F�N�g���擾����
	// -----------------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------------------------------
	//�@�������g���擾����
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }


	// ------------------------------------------
	// �I�u�W�F�N�g�̐����擾
	// -----------------------------------------
	int GetNum()const{ return actor.size(); }


	// ---------------------------------------------------------------
	//	�_�C�i�~�b�N�L���X�g
	//	for(auto&)�͊�{���N���XCActor�̗v�f�����擾�ł��Ȃ����A
	//	������g�p����Ɣh���N���X�̗v�f�܂Ŏ擾�ł���
	// ----------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}

private:

};

