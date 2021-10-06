//============================================================
//
//  title  : �f�[�^�\���i�n�b�V���e�[�u���j [hashTable.h]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#pragma once
#include <iostream>
#include <string>
#include "list.h"


using namespace std;


//============================================================
//�@�N���X�錾
//============================================================
class HashTable
{
private:
	static List* hashData[10];

public:
	HashTable();                                            // �R���X�g���N�^
	~HashTable();                                           // �f�X�g���N�^

	static void Search(string aWord);                       // �P�ꂩ�猟��
	static void AddData(string aWord, string aDescription); // �v�f��ǉ�����
	static void DataList(void);                             // �f�[�^�̈ꗗ
	static int GetHash(string aWord);                       // �n�b�V���l���v�Z
};