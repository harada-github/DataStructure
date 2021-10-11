//============================================================
//
//  title  : 双方向リスト [DoublyLinkedList.h]
//  Author : 原田 陽央
//   Date  : 2021/10/08
//  Update : 2021/10/08
//
//============================================================
#pragma once


//============================================================
//　インクルード
//============================================================
#include <iostream>
#include <string>


using namespace std;


//============================================================
//　構造体宣言
//============================================================
// 成績データの構造体
struct RecordData
{
	string word;        // スコアを格納
	string description;  // ユーザー名を格納
};


//============================================================
//　クラス宣言
//============================================================
class DoublyLinkedList
{
public:

	// ノードの構造体
	struct Node
	{
		Node* prevPtr;          // 前のノードへのポインタ
		Node* nextPtr;          // 次のノードへのポインタ
		RecordData recordData;  // 成績データ
	};


	DoublyLinkedList();                                                 // コンストラクタ
	~DoublyLinkedList();                                                // デストラクタ

	
	void AddTop(RecordData addRecordData);  // 先頭にデータを追加
	void AddEnd(RecordData addRecordData);  // 末尾にデータを追加
	Node* GetTopPtr(void);                  // 先頭のノードを取得
	Node* GetEndPtr(void);                  // 末尾のノードを取得
	void Sort(void);                        // ソート（並び替え）
	void Remove(int num);                   // データの削除
	int GetDataCount(void);                 // データの数の取得

private:
	Node* thisPtr; // 新しく追加されたノードへのポインタを格納

};