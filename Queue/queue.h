//============================================================
//
//  title  : �f�[�^�\���i�L���[�j [queue.h]
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
class Queue
{
private:
	DoublyLinkedList queueList;

public:
	Queue();                                   // �R���X�g���N�^
	~Queue();                                  // �f�X�g���N�^

	void Disp(void);                    // �f�[�^��\��
	void Dequeue(void);                 // �f�L���[�i�v�f�����o���j
	void Enqueue(const RecordData& addRecordData); // �G���L���[�i�v�f��ǉ�����j
};