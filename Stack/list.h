//============================================================
//
//  title  : リスト構造（双方向リスト） [list.h]
//  Author : 原田 陽央
//   Date  : 2021/10/04
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
class List
{
private:
	int score;            // スコアを格納
	string userName;      // 名前を格納

public:
	List();                                            // コンストラクタ
	List(int aScore, string aUserName);                // 引数付きコンストラクタ
	~List();                                           // デストラクタ

	virtual void OutputData(void);                     // データを出力
	static void AddTop(int aScore, string aUserName);  // 先頭にデータを追加
	static void AddEnd(int aScore, string aUserName);  // 末尾にデータを追加
	static void Sort(void);                            // ソート（並び替え）
	static void Remove(int num);                       // 削除
	static List* Create(int aScore, string aUserName); // 生成
	static int GetListCount(void);                     // 要素の数を取得

	List* nextPtr;        // 次の要素へのポインタ
	List* prevPtr;        // 前の要素へのポインタ

	static List* topPtr;  // 先頭の要素へのポインタ
	static List* endPtr;  // 末尾の要素へのポインタ

	static int listCount; // 要素の個数をカウント
};