//============================================================
//
//  title  : ���X�g�\���i�L���[�j [queue.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#include "queue.h"
#include "list.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
Queue::Queue()
{
	;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
Queue::~Queue()
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
void Queue::Disp()
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
//�@�f�L���[�i�v�f�����o���j
//------------------------------------------------------------
void Queue::Dequeue()
{
	// �f�[�^�����o��
	List* popData = List::topPtr;

	// ���X�g����f�[�^���폜
	List::Remove(1, false);

	// �f�[�^��\��
	std::cout << "���L�̃f�[�^�����o���܂���" << endl;
	popData->OutputData();

	// �f�[�^���폜
	delete popData;
}


//------------------------------------------------------------
//�@�G���L���[�i�v�f��ǉ�����j
//------------------------------------------------------------
void Queue::Enqueue(int num, string name)
{
	// ���X�g�Ƀf�[�^��ǉ�
	List::AddEnd(num, name);
}
