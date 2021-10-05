//============================================================
//
//  title  : データ管理 [DataManager.h]
//  Author : 原田 陽央
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
	// 解放処理
	List* tempList;
	List* deleteList = List::topPtr;

	// エラーチェック
	if (tempList == nullptr)
	{
		std::cout << "消去するデータはありません。" << std::endl;
		return;
	}

	// リストの要素を順に解放
	while (tempList != nullptr)
	{
		tempList = deleteList->nextPtr;
		delete deleteList;
		deleteList = tempList;
	}

	// 先頭と最後のポインタをNULLにする
	List::topPtr = nullptr;
	List::endPtr = nullptr;
}


//------------------------------------------------------------
//　データを表示
//------------------------------------------------------------
void DataManager::DispData()
{
	// 表示用の変数
	List* dispList = List::topPtr;

	// エラーチェック
	if (dispList == nullptr)
	{
		std::cout << "データがありません。" << std::endl;
		return;
	}
	
	// 要素の個数分表示
	for (int i = 0; i < List::GetListCount(); i++)
	{
		dispList->OutputData();
		dispList = dispList->nextPtr;
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

	// ファイルを開く
	FILE* fp = fopen(fileName, "r");

	// データ数によって変わるような仕様にする
	// 100の部分を修正予定
	for (int i = 0; i < 100; i++)
	{
		// 全角スペースまでの文字を取得（9は全角スペース）
		while ((temp = fgetc(fp)) != 9)
		{
			score += temp;
		}

		// 改行までの文字を取得（10は改行）
		while ((temp = fgetc(fp)) != 10)
		{
			userName += temp;
		}
		
		// リストの要素を生成
		List::AddEnd(atoi(score.c_str()), userName);

		// 初期化
		score = "";
		userName = "";
	}
}
