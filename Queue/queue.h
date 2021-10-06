//============================================================
//
//  title  : リスト構造（キュー） [queue.h]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#pragma once
#include <iostream>
#include <string>


using namespace std;


//============================================================
//　クラス宣言
//============================================================
class Queue
{
private:

public:
	Queue();                                   // コンストラクタ
	~Queue();                                  // デストラクタ

	static void Disp(void);                    // データを表示
	static void Dequeue(void);                 // デキュー（要素を取り出す）
	static void Enqueue(int num, string name); // エンキュー（要素を追加する）
};