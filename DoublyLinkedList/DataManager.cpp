//============================================================
//
//  title  : データ管理 [DataManager.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/05
//  Update : 2021/10/05
//
//============================================================
#pragma once


//============================================================
//　インクルード
//============================================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DataManager.h"
#include "list.h"


//============================================================
//　変数宣言
//============================================================
DoublyLinkedList DataManager::scoresList;


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
DataManager::DataManager()
{
	;
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
DataManager::~DataManager()
{
	;
}


//------------------------------------------------------------
//　データを表示
//　isSort：true なら並び替えをする・false なら並び替えをしない
//------------------------------------------------------------
void DataManager::DispData(bool isSort)
{
	scoresList.Remove(2);
	// 表示用の変数
	DoublyLinkedList::Node* temp = scoresList.GetTopPtr();

	// isSort が true の場合は並び替えをする
	//if (isSort) scoresList.Sort();


	// エラーチェック
	if (temp == nullptr)
	{
		std::cout << "データがありません。" << std::endl;
		return;
	}

	// temp が NULL じゃなければデータ表示
	while (temp != nullptr)
	{
		// データを表示
		std::cout << "スコア：" << temp->recordData.score << "　" << "ユーザー名：" << temp->recordData.userName << std::endl;

		// 次のポインタに更新
		temp = temp->nextPtr;
	}
}


//------------------------------------------------------------
//　Scoresテキストファイルの読み込み
//------------------------------------------------------------
void DataManager::ReadScoreTextFile()
{
	// ファイル名を代入
	const char *fileName = "Scores.txt";

	// 代入用の変数
	std::string score;
	std::string userName;
	char temp = NULL;
	RecordData data;

	// ファイルを開く
	FILE* fp = fopen(fileName, "r");

	// データ数によって変わるような仕様にする
	// 100の部分を修正予定
	for (int i = 0; i < 10; i++)
	{
		// 全角スペースまでの文字を取得（9は全角スペース）
		while ((temp = fgetc(fp)) != '\t')
		{
			score += temp;
		}

		// 改行までの文字を取得（10は改行）
		while ((temp = fgetc(fp)) != '\n')
		{
			userName += temp;
		}
		
		// リストの要素を生成
		data.score = atoi(score.c_str());
		data.userName = userName;

		// リストに追加
		scoresList.AddEnd(data);

		// 初期化
		score = "";
		userName = "";
		data.score = 0;
		data.userName = "";
	}
}
