//============================================================
//
//  title  : ���X�g�\���i�o�������X�g�j [list.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/04
//  Update : 2021/10/05
//
//============================================================
#include "list.h"


//============================================================
//�@�ϐ��錾
//============================================================
List* List::topPtr;
List* List::endPtr;
int List::listCount = 0;


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
List::List()
{
	// ���������Ă���
	nextPtr = nullptr;
	prevPtr = nullptr;
}


//------------------------------------------------------------
//�@�����t���R���X�g���N�^
//------------------------------------------------------------
List::List(int aScore, string aUserName)
{
	// ���������Ă���
	nextPtr = nullptr;
	prevPtr = nullptr;

	// �l����
	score = aScore;
	userName = aUserName;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
List::~List()
{
	;
}


//------------------------------------------------------------
//�@�f�[�^���o��
//------------------------------------------------------------
void List::OutputData()
{
	// �X�R�A�Ɩ��O���o��
	std::cout << score << "�@" << userName << std::endl;
}


//------------------------------------------------------------
//�@�擪�Ƀf�[�^��ǉ�
//------------------------------------------------------------
void List::AddTop(int aScore, string aUserName)
{
	List* list = Create(aScore, aUserName);

	// �����ł��Ȃ�������return
	if (list == nullptr) return;

	// ���X�g����̏ꍇ�͐擪�Ɩ����͐V�v�f�ƂȂ�
	if (endPtr == nullptr)
	{
		topPtr = endPtr = list;
	}
	else
	{
		// �V�v�f�̎��̃|�C���^�ɐ擪�v�f���Ȃ�
		list->nextPtr = topPtr;

		// �O�擪�̎��̃|�C���^�ɐV�v�f���Ȃ�
		topPtr->prevPtr = list;

		// �擪�|�C���^���X�V
		topPtr = list;
	}
}


//------------------------------------------------------------
//�@�����Ƀf�[�^��ǉ�
//------------------------------------------------------------
void List::AddEnd(int aScore, string aUserName)
{
	List* list = Create(aScore, aUserName);

	// �����ł��Ȃ�������return
	if (list == nullptr) return;

	// ���X�g����̏ꍇ�͐擪�Ɩ����͐V�v�f�ƂȂ�
	if (endPtr == nullptr)
	{
		topPtr = endPtr = list;
	}
	else
	{
		// �V�v�f�𖖔��v�f�̎��̃|�C���^�ɂȂ�
		endPtr->nextPtr = list;

		// �V�v�f�̑O�̃|�C���^�ɖ����v�f���Ȃ�
		list->prevPtr = endPtr;

		// �����|�C���^���X�V
		endPtr = list;

		list->nextPtr = nullptr;
	}
}


//------------------------------------------------------------
//�@�\�[�g�i���ёւ��j
//------------------------------------------------------------
void List::Sort()
{
	// ���X�g�̗v�f�̌����擾
	int count = GetListCount();

	// �P�ȉ��Ȃ�return
	if (count <= 1) return;

	// ����ւ��Ɏg�p���邽�߂̕ϐ�
	List *list1, *list2;

	// 
	for (int j = 0; j < count - 1; j++)
	{
		// �擪�Ƃ��̎��̃A�h���X���r
		list1 = topPtr;
		list2 = list1->nextPtr;

		for (int i = 0; i < count - 1 - j; i++)
		{
			// list2��score�������ꍇ�͓���ւ�
			if (list1->score < list2->score)
			{
				// list1�̎���list2�̑O�̐ڑ����ύX
				list1->nextPtr = list2->nextPtr;
				list2->prevPtr = list1->prevPtr;

				// ����ւ���̂��ꂼ����Ȃ�
				list2->nextPtr = list1;
				list1->prevPtr = list2;

				// ����ւ���O��list1��list2�̑O��̐ڑ����ύX
				if (list1 == topPtr)
				{
					// list1���擪�������ꍇ
					topPtr = list2;
				}
				else
				{
					list2->prevPtr->nextPtr = list2;
				}

				if (list2 == endPtr)
				{
					// list2���Ōゾ�����ꍇ
					endPtr = list1;
				}
				else
				{
					list1->nextPtr->prevPtr = list1;
				}

				// ���ɔ�r������̂�list2�֑��
				list2 = list1->nextPtr;
			}
			else
			{
				// ���ɔ�r������̂�ݒ�
				list1 = list1->nextPtr;
				list2 = list2->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//�@����
//------------------------------------------------------------
List* List::Create(int aScore, string aUserName)
{
	// �����t���ŗv�f�𐶐�
	List* list = new List(aScore, aUserName);

	// �v�f�̌����J�E���g
	listCount++;

	return list;
}

//------------------------------------------------------------
//�@�v�f�̌����擾
//------------------------------------------------------------
int List::GetListCount()
{
	return listCount;
}
