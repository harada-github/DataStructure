//============================================================
//
//  title  : データ構造（ハッシュテーブル） [hashTable.h]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/11
//
//============================================================
#pragma once


//============================================================
//　インクルード
//============================================================
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"


using namespace std;


//============================================================
//　クラス宣言
//============================================================
class HashTable
{
private:
	DoublyLinkedList hashData[10];

public:
	HashTable();                                            // コンストラクタ
	~HashTable();                                           // デストラクタ

	void Disp(void);                                 // 単語を表示
	RecordData Search(const string& searchWord);                       // 単語から検索
	void AddData(const RecordData& addRecordData); // 要素を追加する
	int GetHash(const string& getWord);                       // ハッシュ値を計算
};