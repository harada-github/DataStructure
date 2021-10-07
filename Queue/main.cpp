//============================================================
//
//  title  : データ構造 [main.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/04
//  Update : 2021/10/06
//
//============================================================
//============================================================
//　インクルード
//============================================================
#include "list.h"
#include "queue.h"


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　メイン関数
//------------------------------------------------------------
int main(void)
{
	// 要素を追加
	Queue::Enqueue(0, "Tanaka");
	Queue::Enqueue(1, "Satou");
	Queue::Enqueue(2, "Kobayashi");
	Queue::Enqueue(3, "Kishida");
	Queue::Enqueue(4, "Shimamura");
	Queue::Enqueue(5, "Suga");
	// データを一覧表示
	Queue::Disp();
	// 改行用
	std::cout << "" << endl;


	// １回目
	// 要素を取り出す
	Queue::Dequeue();
	std::cout << "" << endl;
	// データを再度一覧表示
	Queue::Disp();
	// 改行用
	std::cout << "" << endl;


	// ２回目
	// 要素を取り出す
	Queue::Dequeue();
	std::cout << "" << endl;
	// データを再度一覧表示
	Queue::Disp();
}
