//============================================================
//
//  title  : �f�[�^�\���i�n�b�V���e�[�u���j [hashTable.h]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/11
//
//============================================================
#pragma once


//============================================================
//�@�C���N���[�h
//============================================================
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"


using namespace std;


//============================================================
//�@�N���X�錾
//============================================================
class HashTable
{
private:
	DoublyLinkedList hashData[10];

public:
	HashTable();                                            // �R���X�g���N�^
	~HashTable();                                           // �f�X�g���N�^

	void Disp(void);                                 // �P���\��
	RecordData Search(const string& searchWord);                       // �P�ꂩ�猟��
	void AddData(const RecordData& addRecordData); // �v�f��ǉ�����
	int GetHash(const string& getWord);                       // �n�b�V���l���v�Z
};