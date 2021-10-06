//============================================================
//
//  title  : �f�[�^�\���i�o�������X�g�j [list.h]
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
	string word;            // �P����i�[
	string description;     // ���������i�[

public:
	List();                                                 // �R���X�g���N�^
	List(string aWord, string aDescription);                // �����t���R���X�g���N�^
	~List();                                                // �f�X�g���N�^

	virtual void OutputData(void);                          // �f�[�^���o��
	virtual void OutputWord(void);                          // �P����o��
	static void AddTop(string aWord, string aDescription);  // �擪�Ƀf�[�^��ǉ�
	static void AddEnd(string aWord, string aDescription);  // �����Ƀf�[�^��ǉ�
	static void Sort(void);                                 // �\�[�g�i���ёւ��j
	static void Remove(int num, bool isDelete);             // �폜
	static List* Create(string aWord, string aDescription); // ����
	static int GetListCount(void);                          // �v�f�̐����擾
	string GetWord(void);                                   // word���擾

	List* nextPtr;        // ���̗v�f�ւ̃|�C���^
	List* prevPtr;        // �O�̗v�f�ւ̃|�C���^

	static List* topPtr;  // �擪�̗v�f�ւ̃|�C���^
	static List* endPtr;  // �����̗v�f�ւ̃|�C���^

	static int listCount; // �v�f�̌����J�E���g
};