//============================================================
//
//  title  : ���X�g�\���i�X�^�b�N�j [stack.h]
//  Author : ���c �z��
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#pragma once



//============================================================
//�@�N���X�錾
//============================================================
class Stack
{
private:

public:
	Stack();                // �R���X�g���N�^
	~Stack();               // �f�X�g���N�^

	static void Disp(void); // �f�[�^��\��
	static void Pop(void);   // �|�b�v�i�v�f�����o���j
	static void Push(void); // �v�b�V���i�v�f��ǉ�����j
};