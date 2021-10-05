//============================================================
//
//  title  : ���X�g�\���i�o�������X�g�j [list.h]
//  Author : ���c �z��
//   Date  : 2021/10/04
//  Update : 2021/10/05
//
//============================================================
#pragma once
#include <iostream>

using namespace std;


//============================================================
//�@�N���X�錾
//============================================================
class List
{
private:
	int score;         // �X�R�A���i�[
	string userName;   // ���O���i�[

	List* nextPtr; // ���̗v�f�ւ̃|�C���^
	List* prevPtr; // �O�̗v�f�ւ̃|�C���^

	static List* topPtr;  // �擪�̗v�f�ւ̃|�C���^
	static List* endPtr;  // �����̗v�f�ւ̃|�C���^

public:
	List();   // �R���X�g���N�^
	~List();  // �f�X�g���N�^

	virtual void OutputData(void); // �f�[�^���o��
	static void AddTop(void);      // �擪�Ƀf�[�^��ǉ�
	static void AddEnd(void);      // �����Ƀf�[�^��ǉ�
	static void Sort(void);        // �\�[�g�i���ёւ��j
	static List* Create(void);     // ����
};