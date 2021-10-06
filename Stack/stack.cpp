//============================================================
//
//  title  : �f�[�^�\���i�X�^�b�N�j [stack.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#include "stack.h"
#include "list.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
Stack::Stack()
{
	;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
Stack::~Stack()
{
	// �������
	List* tempList = nullptr;
	List* deleteList = List::topPtr;

	// �G���[�`�F�b�N
	if (tempList == nullptr)
	{
		std::cout << "��������f�[�^�͂���܂���B" << std::endl;
		return;
	}

	// ���X�g�̗v�f�����ɉ��
	while (tempList != nullptr)
	{
		tempList = deleteList->nextPtr;
		delete deleteList;
		deleteList = tempList;
	}

	// �擪�ƍŌ�̃|�C���^��NULL�ɂ���
	List::topPtr = nullptr;
	List::endPtr = nullptr;
}


//------------------------------------------------------------
//�@�f�[�^��\��
//------------------------------------------------------------
void Stack::Disp()
{
	// �\���p�̕ϐ�
	List* dispList = List::topPtr;

	// �G���[�`�F�b�N
	if (dispList == nullptr)
	{
		std::cout << "�f�[�^������܂���B" << std::endl;
		return;
	}
	else
	{
		std::cout << "�f�[�^��\��" << endl;
	}

	// �v�f�̌����\��
	for (int i = 0; i < List::GetListCount(); i++)
	{
		dispList->OutputData();
		dispList = dispList->nextPtr;
	}
}


//------------------------------------------------------------
//�@�|�b�v�i�v�f�����o���j
//------------------------------------------------------------
void Stack::Pop()
{
	// �f�[�^�����o��
	List* popData = List::endPtr;

	// ���X�g����f�[�^���폜
	List::Remove(List::GetListCount(), false);

	// �f�[�^��\��
	std::cout << "���L�̃f�[�^�����o���܂���" << endl;
	popData->OutputData();

	// �f�[�^���폜
	delete popData;
}


//------------------------------------------------------------
//�@�v�b�V���i�v�f��ǉ�����j
//------------------------------------------------------------
void Stack::Push(int num, string name)
{
	// ���X�g�Ƀf�[�^��ǉ�
	List::AddEnd(num, name);
}
