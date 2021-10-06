//============================================================
//
//  title  : データ構造（スタック） [stack.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#include "stack.h"
#include "list.h"


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
Stack::Stack()
{
	;
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
Stack::~Stack()
{
	// 解放処理
	List* tempList = nullptr;
	List* deleteList = List::topPtr;

	// エラーチェック
	if (tempList == nullptr)
	{
		std::cout << "消去するデータはありません。" << std::endl;
		return;
	}

	// リストの要素を順に解放
	while (tempList != nullptr)
	{
		tempList = deleteList->nextPtr;
		delete deleteList;
		deleteList = tempList;
	}

	// 先頭と最後のポインタをNULLにする
	List::topPtr = nullptr;
	List::endPtr = nullptr;
}


//------------------------------------------------------------
//　データを表示
//------------------------------------------------------------
void Stack::Disp()
{
	// 表示用の変数
	List* dispList = List::topPtr;

	// エラーチェック
	if (dispList == nullptr)
	{
		std::cout << "データがありません。" << std::endl;
		return;
	}
	else
	{
		std::cout << "データを表示" << endl;
	}

	// 要素の個数分表示
	for (int i = 0; i < List::GetListCount(); i++)
	{
		dispList->OutputData();
		dispList = dispList->nextPtr;
	}
}


//------------------------------------------------------------
//　ポップ（要素を取り出す）
//------------------------------------------------------------
void Stack::Pop()
{
	// データを取り出す
	List* popData = List::endPtr;

	// リストからデータを削除
	List::Remove(List::GetListCount(), false);

	// データを表示
	std::cout << "下記のデータを取り出しました" << endl;
	popData->OutputData();

	// データを削除
	delete popData;
}


//------------------------------------------------------------
//　プッシュ（要素を追加する）
//------------------------------------------------------------
void Stack::Push(int num, string name)
{
	// リストにデータを追加
	List::AddEnd(num, name);
}
