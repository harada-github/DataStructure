//============================================================
//
//  title  : リスト構造（双方向リスト） [list.h]
//  Author : 原田 陽央
//   Date  : 2021/10/04
//  Update : 2021/10/05
//
//============================================================
#pragma once
#include <iostream>

using namespace std;


//============================================================
//　クラス宣言
//============================================================
class List
{
private:
	int score;         // スコアを格納
	string userName;   // 名前を格納

	List* nextPtr; // 次の要素へのポインタ
	List* prevPtr; // 前の要素へのポインタ

	static List* topPtr;  // 先頭の要素へのポインタ
	static List* endPtr;  // 末尾の要素へのポインタ

public:
	List();   // コンストラクタ
	~List();  // デストラクタ

	virtual void OutputData(void); // データを出力
	static void AddTop(void);      // 先頭にデータを追加
	static void AddEnd(void);      // 末尾にデータを追加
	static void Sort(void);        // ソート（並び替え）
	static List* Create(void);     // 生成
};