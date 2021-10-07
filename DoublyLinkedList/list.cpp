//============================================================
//
//  title  : データ構造（双方向リスト） [list.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/04
//  Update : 2021/10/06
//
//============================================================
//============================================================
//　インクルード
//============================================================
#include "list.h"


//============================================================
//　変数宣言
//============================================================
List* List::topPtr;
List* List::endPtr;
int List::listCount = 0;


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
List::List()
{
	// 初期化しておく
	nextPtr = nullptr;
	prevPtr = nullptr;
}


//------------------------------------------------------------
//　引数付きコンストラクタ
//------------------------------------------------------------
List::List(int aScore, string aUserName)
{
	// 初期化しておく
	nextPtr = nullptr;
	prevPtr = nullptr;

	// 値を代入
	score = aScore;
	userName = aUserName;
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
List::~List()
{
	;
}


//------------------------------------------------------------
//　データを出力
//------------------------------------------------------------
void List::OutputData()
{
	// スコアと名前を出力
	std::cout << score << "　" << userName << std::endl;
}


//------------------------------------------------------------
//　先頭にデータを追加
//------------------------------------------------------------
void List::AddTop(int aScore, string aUserName)
{
	List* list = Create(aScore, aUserName);

	// 生成できなかったらreturn
	if (list == nullptr) return;

	// リストが空の場合は先頭と末尾は新要素となる
	if (endPtr == nullptr)
	{
		topPtr = endPtr = list;
	}
	else
	{
		// 新要素の次のポインタに先頭要素をつなぐ
		list->nextPtr = topPtr;

		// 前先頭の次のポインタに新要素をつなぐ
		topPtr->prevPtr = list;

		// 先頭ポインタを更新
		topPtr = list;
	}
}


//------------------------------------------------------------
//　末尾にデータを追加
//------------------------------------------------------------
void List::AddEnd(int aScore, string aUserName)
{
	List* list = Create(aScore, aUserName);

	// 生成できなかったらreturn
	if (list == nullptr) return;

	// リストが空の場合は先頭と末尾は新要素となる
	if (endPtr == nullptr)
	{
		topPtr = endPtr = list;
	}
	else
	{
		// 新要素を末尾要素の次のポインタにつなぐ
		endPtr->nextPtr = list;

		// 新要素の前のポインタに末尾要素をつなぐ
		list->prevPtr = endPtr;

		// 末尾ポインタを更新
		endPtr = list;

		list->nextPtr = nullptr;
	}
}


//------------------------------------------------------------
//　ソート（並び替え）
//------------------------------------------------------------
void List::Sort()
{
	// リストの要素の個数を取得
	int count = GetListCount();

	// １つ以下ならreturn
	if (count <= 1) return;

	// 入れ替えに使用するための変数
	List *list1, *list2;

	for (int j = 0; j < count - 1; j++)
	{
		// 先頭とその次のアドレスを比較
		list1 = topPtr;
		list2 = list1->nextPtr;

		for (int i = 0; i < count - 1 - j; i++)
		{
			// list2のscoreが高い場合は入れ替え
			if (list1->score < list2->score)
			{
				// list1の次とlist2の前の接続先を変更
				list1->nextPtr = list2->nextPtr;
				list2->prevPtr = list1->prevPtr;

				// 入れ替え後のそれぞれをつなぐ
				list2->nextPtr = list1;
				list1->prevPtr = list2;

				// 入れ替える前のlist1とlist2の前後の接続先を変更
				if (list1 == topPtr)
				{
					// list1が先頭だった場合
					topPtr = list2;
				}
				else
				{
					list2->prevPtr->nextPtr = list2;
				}

				if (list2 == endPtr)
				{
					// list2が最後だった場合
					endPtr = list1;
				}
				else
				{
					list1->nextPtr->prevPtr = list1;
				}

				// 次に比較するものをlist2へ代入
				list2 = list1->nextPtr;
			}
			else
			{
				// 次に比較するものを設定
				list1 = list1->nextPtr;
				list2 = list2->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//　削除
//　num は削除するデータの位置（1を先頭とする）
//------------------------------------------------------------
void List::Remove(int num)
{
	// リストの要素の個数を取得
	int count = GetListCount();

	// 個数が0 または 削除したい位置が0 または 削除したい位置が個数より大きければ return
	if (count == 0 || num == 0 || num > count) return;

	// 削除に使用する変数
	List* temp;

	if (count == 1)
	{
		// 要素が一つの場合

		// 削除
		delete topPtr;

		// 先頭と末尾をNULLにする
		topPtr = endPtr = nullptr;
	}
	else if (num == 1)
	{
		// 先頭の要素の場合

		// 削除する前に次のポインタを保存
		temp = topPtr->nextPtr;

		// 削除
		delete topPtr;

		// 先頭の要素を更新
		topPtr = temp;

		// 先頭の要素になるポインタの前ポインタをNULLにする
		temp->prevPtr = nullptr;
	}
	else if (num == count)
	{
		// 末尾の要素の場合

		// 削除する前に前のポインタを保存
		temp = endPtr->prevPtr;

		// 削除
		delete endPtr;

		// 末尾の要素を更新
		endPtr = temp;

		// 末尾の要素になるポインタの次ポインタをNULLにする
		temp->nextPtr = nullptr;
	}
	else
	{
		// 先頭と末尾以外の場合

		// 先頭のポインタを保存
		temp = topPtr;

		// numの位置までたどる
		for (int i = 1; i < num; i++)
		{
			temp = temp->nextPtr;
		}

		// 削除したい位置のポインタの前後を更新
		temp->prevPtr->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = temp->prevPtr;

		// 削除
		delete temp;
	}

	// 個数を減らす
	listCount--;
}


//------------------------------------------------------------
//　生成
//------------------------------------------------------------
List* List::Create(int aScore, string aUserName)
{
	// 引数付きで要素を生成
	List* list = new List(aScore, aUserName);

	// 要素の個数をカウント
	listCount++;

	return list;
}

//------------------------------------------------------------
//　要素の個数を取得
//------------------------------------------------------------
int List::GetListCount()
{
	return listCount;
}
