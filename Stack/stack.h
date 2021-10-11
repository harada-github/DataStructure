//============================================================
//
//  title  : �f�[�^�\���i�X�^�b�N�j [stack.h]
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
class Stack
{
private:
	DoublyLinkedList pushList;

public:
	Stack();                             // �R���X�g���N�^
	~Stack();                            // �f�X�g���N�^

	void Disp(void);                     // �f�[�^��\��
	void Pop(void);                      // �|�b�v�i�v�f�����o���j
	void Push(const RecordData& addRecordData); // �v�b�V���i�v�f��ǉ�����j
};