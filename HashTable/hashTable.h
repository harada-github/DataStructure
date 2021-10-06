//============================================================
//
//  title  : データ構造（ハッシュテーブル） [hashTable.h]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#pragma once
#include <iostream>
#include <string>
#include "list.h"


using namespace std;


//============================================================
//　クラス宣言
//============================================================
class HashTable
{
private:
	static List* hashData[10];

public:
	HashTable();                                            // コンストラクタ
	~HashTable();                                           // デストラクタ

	static void Search(string aWord);                       // 単語から検索
	static void AddData(string aWord, string aDescription); // 要素を追加する
	static void DataList(void);                             // データの一覧
	static int GetHash(string aWord);                       // ハッシュ値を計算
};