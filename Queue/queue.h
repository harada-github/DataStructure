//============================================================
//
//  title  : ���X�g�\���i�L���[�j [queue.h]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#pragma once
#include <iostream>
#include <string>


using namespace std;


//============================================================
//�@�N���X�錾
//============================================================
class Queue
{
private:

public:
	Queue();                                   // �R���X�g���N�^
	~Queue();                                  // �f�X�g���N�^

	static void Disp(void);                    // �f�[�^��\��
	static void Dequeue(void);                 // �f�L���[�i�v�f�����o���j
	static void Enqueue(int num, string name); // �G���L���[�i�v�f��ǉ�����j
};