//============================================================
//
//  title  : �f�[�^�\���i�X�^�b�N�j [HashTable.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/11
//
//============================================================
//============================================================
//�@�C���N���[�h
//============================================================
#include "hashTable.h"
#include "list.h"
#include "DoublyLinkedList.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
HashTable::HashTable()
{
	;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
HashTable::~HashTable()
{
	;
}


//------------------------------------------------------------
//�@�P���\��
//------------------------------------------------------------
void HashTable::Disp()
{
	// ����p�̕ϐ�
	DoublyLinkedList::Node* temp = nullptr;

	// ����\��
	std::cout << "[���ׂ邱�Ƃ��ł���P��̈ꗗ]" << std::endl;

	// �f�[�^�̈ꗗ�\��
	for (int i = 0; i < 10; i++)
	{
		if (hashData[i].GetDataCount() == 0)
		{
			continue;
		}
		else
		{
			temp = hashData[i].GetTopPtr();

			// �f�[�^������ꍇ�͂��̎��̃|�C���^���m�F
			while (temp != nullptr)
			{
				// �f�[�^�\��
				std::cout << "�E" << temp->recordData.word << std::endl;
				temp = temp->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//�@�P�ꂩ�猟��
//------------------------------------------------------------
RecordData HashTable::Search(const string& searchWord)
{
	// �n�b�V���l��ۑ�
	int hash = GetHash(searchWord);

	// �f�[�^���Ȃ������ꍇ�ɕԂ�RecordData
	RecordData nullData = {};

	// �G���[�`�F�b�N
	if (hashData[hash].GetDataCount() == 0)
	{
		return nullData;
	}
	// word����v������f�[�^��\��
	else
	{
		// ����p�̕ϐ�
		DoublyLinkedList::Node* temp = hashData[hash].GetTopPtr();

		while (temp != nullptr)
		{
			if (temp->recordData.word == searchWord)
			{
				return temp->recordData;
			}

			// ���|�C���^�֍X�V
			temp = temp->nextPtr;
		}
	}

	return nullData;
}


//------------------------------------------------------------
//�@�v�f��ǉ�����
//------------------------------------------------------------
void HashTable::AddData(const RecordData& addRecordData)
{
	// �`�F�C���@

	// �n�b�V���l��ۑ�
	int hash = GetHash(addRecordData.word);

	// �f�[�^�𐶐�
	hashData[hash].AddEnd(addRecordData);
}


//------------------------------------------------------------
//�@�n�b�V���l���v�Z
//------------------------------------------------------------
int HashTable::GetHash(const string& getWord)
{
	// ���������P�O�Ŋ������]����n�b�V���l�Ƃ���
	return getWord.length() / 2 % 10;
}
