//============================================================
//
//  title  : データ構造（キュー） [queue.h]
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
class Queue
{
private:
	DoublyLinkedList queueList;

public:
	Queue();                                   // コンストラクタ
	~Queue();                                  // デストラクタ

	void Disp(void);                    // データを表示
	void Dequeue(void);                 // デキュー（要素を取り出す）
	void Enqueue(const RecordData& addRecordData); // エンキュー（要素を追加する）
};