#include "Task.h"
#include "Actor.h"
#include <assert.h>

// ------------------------------
//�@Actor������
// ------------------------------
void CTask::Append(std::string name, std::shared_ptr<CActor> actor)
{
	assert(actor);
	object.insert(std::make_pair(name, actor));
}
// ------------------------------
//�@Actor����ɂ���
// ------------------------------
void CTask::Clear()
{
	object.clear();
}

// ------------------------------
//�@�^�X�N�����������
// ------------------------------
void CTask::Remove()
{
	for (auto& obj : object)
	{
		obj.second->Remove();
	}
}

// ----------------------------------
//�@�A�b�v�f�[�g�̑O�ɌĂ΂�鏈��
// ----------------------------------
void CTask::Start()
{
	for (auto& obj : object)
	{
		obj.second->Start();
	}
}


// ------------------------------
//�@�A�b�v�f�[�g
// ------------------------------
void CTask::Update()
{
	for (auto& obj : object)
	{
		obj.second->Update();
	}
}

// ------------------------------
//�@�`��
// ------------------------------
void CTask::Draw()
{
	for (auto& obj : object)
	{
		obj.second->Draw();
	}
}


// -------------------------------------------------------------
// �I�u�W�F�N�g���擾����iActor�̒��ɂ���N���X�̑S�̂��擾�j
// -------------------------------------------------------------
std::shared_ptr<CActor> CTask::GetComponents(const std::string& name)
{
	auto it = object.begin();
	it = object.find(name);
	assert(it != object.end());

	return it->second;
}

// ------------------------------------------------------
//�@�A�N�^�[���̂��擾����
// ------------------------------------------------------
std::vector<std::shared_ptr<CActor>> CTask::GetActor(const std::string& name)
{
	auto it = object.begin();
	it = object.find(name);
	assert(it != object.end());

	return it->second->GetActor();
}

// ------------------------------------------
// �I�u�W�F�N�g�̐����擾
// -----------------------------------------
int CTask::GetNum(const std::string& name)
{
	auto it = object.begin();
	it = object.find(name);

	assert(it != object.end());

	return it->second->GetNum();
}