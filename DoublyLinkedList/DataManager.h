//============================================================
//
//  title  : �f�[�^�Ǘ� [DataManager.h]
//  Author : ���c �z��
//   Date  : 2021/10/05
//  Update : 2021/10/05
//
//============================================================
#pragma once


//============================================================
//�@�C���N���[�h
//============================================================
#include "DoublyLinkedList.h"


//============================================================
//�@�N���X�錾
//============================================================
class DataManager
{
private:
	static DoublyLinkedList scoresList;  // Scores�e�L�X�g�̃f�[�^���i�[���郊�X�g

public:
	DataManager();                       // �R���X�g���N�^
	~DataManager();                      // �f�X�g���N�^

	static void DispData(bool isSort);   // �f�[�^��\��
	static void ReadScoreTextFile(void); // �e�L�X�g�t�@�C����ǂݍ���
};