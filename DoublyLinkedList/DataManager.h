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
//�@�N���X�錾
//============================================================
class DataManager
{
private:

public:
	DataManager();   // �R���X�g���N�^
	~DataManager();  // �f�X�g���N�^

	static void DispData(void);          // �f�[�^��\��
	static void ReadScoreTextFile(void); // �e�L�X�g�t�@�C����ǂݍ���
};