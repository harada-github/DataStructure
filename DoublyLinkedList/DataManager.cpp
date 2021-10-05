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
#include <fstream>
#include <string>
#include <sstream>
#include "DataManager.h"
#include "list.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@�R���X�g���N�^
//------------------------------------------------------------
DataManager::DataManager()
{
	;
}


//------------------------------------------------------------
//�@�f�X�g���N�^
//------------------------------------------------------------
DataManager::~DataManager()
{
	// �������
	List* tempList;
	List* deleteList = List::topPtr;

	// �G���[�`�F�b�N
	if (tempList == nullptr)
	{
		std::cout << "��������f�[�^�͂���܂���B" << std::endl;
		return;
	}

	// ���X�g�̗v�f�����ɉ��
	while (tempList != nullptr)
	{
		tempList = deleteList->nextPtr;
		delete deleteList;
		deleteList = tempList;
	}

	// �擪�ƍŌ�̃|�C���^��NULL�ɂ���
	List::topPtr = nullptr;
	List::endPtr = nullptr;
}


//------------------------------------------------------------
//�@�f�[�^��\��
//------------------------------------------------------------
void DataManager::DispData()
{
	// �\���p�̕ϐ�
	List* dispList = List::topPtr;

	// �G���[�`�F�b�N
	if (dispList == nullptr)
	{
		std::cout << "�f�[�^������܂���B" << std::endl;
		return;
	}
	
	// �v�f�̌����\��
	for (int i = 0; i < List::GetListCount(); i++)
	{
		dispList->OutputData();
		dispList = dispList->nextPtr;
	}
}


//------------------------------------------------------------
//�@Scores�e�L�X�g�t�@�C���̓ǂݍ���
//------------------------------------------------------------
void DataManager::ReadScoreTextFile()
{
	// �t�@�C��������
	const char *fileName = "Scores.txt";

	// ����p�̕ϐ�
	std::string score;
	std::string userName;
	char temp = NULL;

	// �t�@�C�����J��
	FILE* fp = fopen(fileName, "r");

	// �f�[�^���ɂ���ĕς��悤�Ȏd�l�ɂ���
	// 100�̕������C���\��
	for (int i = 0; i < 100; i++)
	{
		// �S�p�X�y�[�X�܂ł̕������擾�i9�͑S�p�X�y�[�X�j
		while ((temp = fgetc(fp)) != 9)
		{
			score += temp;
		}

		// ���s�܂ł̕������擾�i10�͉��s�j
		while ((temp = fgetc(fp)) != 10)
		{
			userName += temp;
		}
		
		// ���X�g�̗v�f�𐶐�
		List::AddEnd(atoi(score.c_str()), userName);

		// ������
		score = "";
		userName = "";
	}
}
