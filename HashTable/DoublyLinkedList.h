//============================================================
//
//  title  : �o�������X�g [DoublyLinkedList.h]
//  Author : ���c �z��
//   Date  : 2021/10/08
//  Update : 2021/10/08
//
//============================================================
#pragma once


//============================================================
//�@�C���N���[�h
//============================================================
#include <iostream>
#include <string>


using namespace std;


//============================================================
//�@�\���̐錾
//============================================================
// ���уf�[�^�̍\����
struct RecordData
{
	string word;        // �X�R�A���i�[
	string description;  // ���[�U�[�����i�[
};


//============================================================
//�@�N���X�錾
//============================================================
class DoublyLinkedList
{
public:

	// �m�[�h�̍\����
	struct Node
	{
		Node* prevPtr;          // �O�̃m�[�h�ւ̃|�C���^
		Node* nextPtr;          // ���̃m�[�h�ւ̃|�C���^
		RecordData recordData;  // ���уf�[�^
	};


	DoublyLinkedList();                                                 // �R���X�g���N�^
	~DoublyLinkedList();                                                // �f�X�g���N�^

	
	void AddTop(RecordData addRecordData);  // �擪�Ƀf�[�^��ǉ�
	void AddEnd(RecordData addRecordData);  // �����Ƀf�[�^��ǉ�
	Node* GetTopPtr(void);                  // �擪�̃m�[�h���擾
	Node* GetEndPtr(void);                  // �����̃m�[�h���擾
	void Sort(void);                        // �\�[�g�i���ёւ��j
	void Remove(int num);                   // �f�[�^�̍폜
	int GetDataCount(void);                 // �f�[�^�̐��̎擾

private:
	Node* thisPtr; // �V�����ǉ����ꂽ�m�[�h�ւ̃|�C���^���i�[

};