#include "Actor.h"

// ------------------------------
//�@�I�u�W�F�N�g������
// ------------------------------
void CActor::Append(std::shared_ptr<CActor> obj)
{
	assert(obj);
	actor.emplace_back(obj);
}

// ------------------------------
//�@��������
// ------------------------------
void CActor::Remove()
{
	Erase_if(actor, [](std::shared_ptr<CActor> &obj)
	{
		return obj->isDelete;
	});
}

// ----------------------------------
//�@�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
// ----------------------------------
void CActor::Start()
{
	for (auto& obj : actor)
	{
		obj->Start();
	}

}

// ------------------------------
//�@�A�b�v�f�[�g
// ------------------------------
void CActor::Update()
{
	for (auto& obj : actor)
	{
		obj->Update();
	}
}

// ------------------------------
//�@�`��
// ------------------------------
void CActor::Draw()
{
	for (auto& obj : actor)
	{
		obj->Draw();
	}
}
// ------------------------------------------
// �I�u�W�F�N�g���擾����
// -----------------------------------------
std::shared_ptr<Object> CActor::GetComponent(const int id)const
{
	assert(id >= 0);
	assert(id <= (int)actor.size() -1);

	return actor[id];
}
