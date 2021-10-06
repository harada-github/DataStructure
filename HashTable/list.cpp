//============================================================
//
//  title  : �f�[�^�\���i�o�������X�g�j [list.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/04
//  Update : 2021/10/06
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
List::List(string aWord, string aDescription)
{
	// ���������Ă���
	nextPtr = nullptr;
	prevPtr = nullptr;

	// �l����
	word = aWord;
	description = aDescription;
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
	std::cout << "�P��F" << word << std::endl;
	std::cout << "�����F" << description << std::endl;
}


//------------------------------------------------------------
//�@�P����o��
//------------------------------------------------------------
void List::OutputWord()
{
	// �X�R�A�Ɩ��O���o��
	std::cout << "�E" << word << std::endl;
}


//------------------------------------------------------------
//�@�擪�Ƀf�[�^��ǉ�
//------------------------------------------------------------
void List::AddTop(string aWord, string aDescription)
{
	List* list = Create(aWord, aDescription);

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
void List::AddEnd(string aWord, string aDescription)
{
	List* list = Create(aWord, aDescription);

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

	for (int j = 0; j < count - 1; j++)
	{
		// �擪�Ƃ��̎��̃A�h���X���r
		list1 = topPtr;
		list2 = list1->nextPtr;

		for (int i = 0; i < count - 1 - j; i++)
		{
			// list2��word�������ꍇ�͓���ւ�
			if (list1->word < list2->word)
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
//�@�폜
//�@num �͍폜����f�[�^�̈ʒu�i1��擪�Ƃ���j
//  isDelete �͍폜����f�[�^��������邩�ǂ���
//------------------------------------------------------------
void List::Remove(int num, bool isDelete)
{
	// ���X�g�̗v�f�̌����擾
	int count = GetListCount();

	// ����0 �܂��� �폜�������ʒu��0 �܂��� �폜�������ʒu�������傫����� return
	if (count == 0 || num == 0 || num > count) return;

	// �폜�Ɏg�p����ϐ�
	List* temp;

	if (count == 1)
	{
		// �v�f����̏ꍇ

		// �폜
		if(isDelete) delete topPtr;

		// �擪�Ɩ�����NULL�ɂ���
		topPtr = endPtr = nullptr;
	}
	else if (num == 1)
	{
		// �擪�̗v�f�̏ꍇ

		// �폜����O�Ɏ��̃|�C���^��ۑ�
		temp = topPtr->nextPtr;

		// �폜
		if (isDelete) delete topPtr;

		// �擪�̗v�f���X�V
		topPtr = temp;

		// �擪�̗v�f�ɂȂ�|�C���^�̑O�|�C���^��NULL�ɂ���
		temp->prevPtr = nullptr;
	}
	else if (num == count)
	{
		// �����̗v�f�̏ꍇ

		// �폜����O�ɑO�̃|�C���^��ۑ�
		temp = endPtr->prevPtr;

		// �폜
		if (isDelete) delete endPtr;

		// �����̗v�f���X�V
		endPtr = temp;

		// �����̗v�f�ɂȂ�|�C���^�̎��|�C���^��NULL�ɂ���
		temp->nextPtr = nullptr;
	}
	else
	{
		// �擪�Ɩ����ȊO�̏ꍇ

		// �擪�̃|�C���^��ۑ�
		temp = topPtr;

		// num�̈ʒu�܂ł��ǂ�
		for (int i = 1; i < num; i++)
		{
			temp = temp->nextPtr;
		}

		// �폜�������ʒu�̃|�C���^�̑O����X�V
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		// �폜
		if (isDelete) delete temp;
	}

	// �������炷
	listCount--;
}


//------------------------------------------------------------
//�@����
//------------------------------------------------------------
List* List::Create(string aWord, string aDescription)
{
	// �����t���ŗv�f�𐶐�
	List* list = new List(aWord, aDescription);

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


//------------------------------------------------------------
//�@word���擾
//------------------------------------------------------------
string List::GetWord()
{
	return word;
}
