//============================================================
//
//  title  : �f�[�^�Ǘ� [DataManager.h]
//  Author : ���c �z��
//   Date  : 2021/10/05
//  Update : 2021/10/05
//
//============================================================
#pragma once
#include <iostream>

using namespace std;


//============================================================
//�@�N���X�錾
//============================================================
class DataManager
{
private:
	

public:
	DataManager();   // �R���X�g���N�^
	~DataManager();  // �f�X�g���N�^

	static void ReadScoreTextFile(void);
	static void LoadData(void);

	static string data;       // �S�f�[�^���i�[
};