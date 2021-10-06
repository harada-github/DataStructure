//============================================================
//
//  title  : ���X�g�\���i�o�������X�g�j [list.h]
//  Author : ���c �z��
//   Date  : 2021/10/04
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
class List
{
private:
	int score;            // �X�R�A���i�[
	string userName;      // ���O���i�[

public:
	List();                                            // �R���X�g���N�^
	List(int aScore, string aUserName);                // �����t���R���X�g���N�^
	~List();                                           // �f�X�g���N�^

	virtual void OutputData(void);                     // �f�[�^���o��
	static void AddTop(int aScore, string aUserName);  // �擪�Ƀf�[�^��ǉ�
	static void AddEnd(int aScore, string aUserName);  // �����Ƀf�[�^��ǉ�
	static void Sort(void);                            // �\�[�g�i���ёւ��j
	static void Remove(int num);                       // �폜
	static List* Create(int aScore, string aUserName); // ����
	static int GetListCount(void);                     // �v�f�̐����擾

	List* nextPtr;        // ���̗v�f�ւ̃|�C���^
	List* prevPtr;        // �O�̗v�f�ւ̃|�C���^

	static List* topPtr;  // �擪�̗v�f�ւ̃|�C���^
	static List* endPtr;  // �����̗v�f�ւ̃|�C���^

	static int listCount; // �v�f�̌����J�E���g
};