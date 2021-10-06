//============================================================
//
//  title  : �f�[�^�\���i�X�^�b�N�j [HashTable.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#include "hashTable.h"
#include "list.h"


//============================================================
//�@�ϐ��錾
//============================================================
List* HashTable::hashData[10];


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
HashTable::HashTable()
{
	// �����������Ă���
	for (int i = 0; i < 10; i++)
	{
		hashData[i] = nullptr;
	}
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
HashTable::~HashTable()
{
	// ����p�̕ϐ�
	List* temp = nullptr;
	List* dele = nullptr;

	// �f�[�^�̉��
	for (int i = 0; i < 10; i++)
	{
		if (hashData[i] == nullptr)
		{
			continue;
		}
		else
		{
			temp = hashData[i];

			// �f�[�^������ꍇ�͂��̎��̃|�C���^���m�F
			while (temp != nullptr)
			{
				dele = temp;
				temp = temp->nextPtr;
				delete dele;
			}
		}
	}
}


//------------------------------------------------------------
//�@�P�ꂩ�猟��
//------------------------------------------------------------
void HashTable::Search(string aWord)
{
	// �G���[�`�F�b�N
	if (hashData[GetHash(aWord)] == nullptr)
	{
		std::cout << "��v����f�[�^��������܂���ł����B" << std::endl;
	}
	// word����v������f�[�^��\��
	else
	{
		// ����p�̕ϐ�
		List* temp = hashData[GetHash(aWord)];

		// �f�[�^������ꍇ�͂��̎��̃|�C���^���m�F
		while (temp->nextPtr != nullptr)
		{
			temp = temp->nextPtr;
		}

		// �������O�̒P�ꂪ���������ꍇ
		if (temp->GetWord() == aWord)
		{
			// �f�[�^�\��
			temp->OutputData();
			return;
		}
		else
		{
			// �f�[�^���Ȃ��ꍇ
			std::cout << "��v����f�[�^��������܂���ł����B" << std::endl;
		}
		
	}
}


//------------------------------------------------------------
//�@�v�f��ǉ�����
//------------------------------------------------------------
void HashTable::AddData(string aWord, string aDescription)
{
	// �`�F�C���@

	if (hashData[GetHash(aWord)] == nullptr)
	{
		// �f�[�^�𐶐�
		hashData[GetHash(aWord)] = List::Create(aWord, aDescription);
	}
	else
	{
		// ����p�̕ϐ�
		List* temp = hashData[GetHash(aWord)];

		// �f�[�^������ꍇ�͂��̎��̃|�C���^���m�F
		while (temp->nextPtr != nullptr)
		{
			// �����P�ꂪ����ꍇ��return
			if (temp->GetWord() == aWord)
			{
				std::cout << "�������O�̒P�ꂪ���݂��܂�" << std::endl;
				return;
			}

			temp = temp->nextPtr;
		}

		// �f�[�^�̐����ƑO��̃|�C���^�̍X�V
		temp->nextPtr = List::Create(aWord, aDescription);
		temp->nextPtr->prevPtr = temp;
		temp->nextPtr->nextPtr = nullptr;

	}
	
}


//------------------------------------------------------------
//�@�f�[�^�̈ꗗ
//------------------------------------------------------------
void HashTable::DataList()
{
	AddData("����", "�{��ǂ݁A���������A�܂��d�������邽�߂Ɏg����B");
	AddData("����", "�l�����������邽�߂̉Ƌ�̑��́B");
	AddData("����", "���o���C�˒I�C�ߑ��~������Ȃ���[�Ƌ�B");
	AddData("�ꂢ������", "�H�i�𒙑����邽�߂ɁA���e���̉��x��ቷ�x�ɕۂ��Ƃ��ł��鑕�u�B");
	AddData("�x�b�h", "�����A�x���̂��߂ɉ���(������)����Ƌ�B");
	AddData("�e���r", "�e���r�W�����̗�");
	AddData("���݂΂�", "�s�v�ɂȂ����t�@�C����t�H���_���ꎞ�I�ɕۊǂ���ꏊ�̂��ƁB");
	AddData("�Q�[��", "�V�т��ƁB");
}


//------------------------------------------------------------
//�@�n�b�V���l���v�Z
//------------------------------------------------------------
int HashTable::GetHash(string aWord)
{
	return aWord.length() % 10;
}

