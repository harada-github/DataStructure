//============================================================
//
//  title  : データ構造（スタック） [stack.h]
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
class Stack
{
private:

public:
	Stack();                                // コンストラクタ
	~Stack();                               // デストラクタ

	static void Disp(void);                 // データを表示
	static void Pop(void);                  // ポップ（要素を取り出す）
	static void Push(int num, string name); // プッシュ（要素を追加する）
};