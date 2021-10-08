//============================================================
//
//  title  : �f�[�^�Ǘ� [DataManager.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/05
//  Update : 2021/10/05
//
//============================================================
#pragma once


//============================================================
//�@�C���N���[�h
//============================================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DataManager.h"
#include "list.h"


//============================================================
//�@�ϐ��錾
//============================================================
DoublyLinkedList DataManager::scoresList;


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
	;
}


//------------------------------------------------------------
//�@�f�[�^��\��
//�@isSort�Ftrue �Ȃ���ёւ�������Efalse �Ȃ���ёւ������Ȃ�
//------------------------------------------------------------
void DataManager::DispData(bool isSort)
{
	scoresList.Remove(2);
	// �\���p�̕ϐ�
	DoublyLinkedList::Node* temp = scoresList.GetTopPtr();

	// isSort �� true �̏ꍇ�͕��ёւ�������
	//if (isSort) scoresList.Sort();


	// �G���[�`�F�b�N
	if (temp == nullptr)
	{
		std::cout << "�f�[�^������܂���B" << std::endl;
		return;
	}

	// temp �� NULL ����Ȃ���΃f�[�^�\��
	while (temp != nullptr)
	{
		// �f�[�^��\��
		std::cout << "�X�R�A�F" << temp->recordData.score << "�@" << "���[�U�[���F" << temp->recordData.userName << std::endl;

		// ���̃|�C���^�ɍX�V
		temp = temp->nextPtr;
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
	RecordData data;

	// �t�@�C�����J��
	FILE* fp = fopen(fileName, "r");

	// �f�[�^���ɂ���ĕς��悤�Ȏd�l�ɂ���
	// 100�̕������C���\��
	for (int i = 0; i < 10; i++)
	{
		// �S�p�X�y�[�X�܂ł̕������擾�i9�͑S�p�X�y�[�X�j
		while ((temp = fgetc(fp)) != '\t')
		{
			score += temp;
		}

		// ���s�܂ł̕������擾�i10�͉��s�j
		while ((temp = fgetc(fp)) != '\n')
		{
			userName += temp;
		}
		
		// ���X�g�̗v�f�𐶐�
		data.score = atoi(score.c_str());
		data.userName = userName;

		// ���X�g�ɒǉ�
		scoresList.AddEnd(data);

		// ������
		score = "";
		userName = "";
		data.score = 0;
		data.userName = "";
	}
}
