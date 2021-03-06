//============================================================
//
//  title  : データ管理 [DataManager.h]
//  Author : 原田 陽央
//   Date  : 2021/10/05
//  Update : 2021/10/08
//
//============================================================
#pragma once


//============================================================
//　インクルード
//============================================================
#include "DoublyLinkedList.h"


//============================================================
//　クラス宣言
//============================================================
class DataManager
{
private:
	static DoublyLinkedList scoresList;  // Scoresテキストのデータを格納するリスト

public:
	DataManager();                       // コンストラクタ
	~DataManager();                      // デストラクタ

	static void DispData(bool isSort);   // データを表示
	static void ReadScoreTextFile(void); // テキストファイルを読み込む
};