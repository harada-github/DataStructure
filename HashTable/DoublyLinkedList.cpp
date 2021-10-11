//============================================================
//
//  title  : 双方向リスト [DoublyLinkedList.h]
//  Author : 原田 陽央
//   Date  : 2021/10/08
//  Update : 2021/10/08
//
//============================================================
//============================================================
//　インクルード
//============================================================
#include "DoublyLinkedList.h"


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　【 コンストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::DoublyLinkedList()
{
	// 値を初期化
	thisPtr = nullptr;
}


//------------------------------------------------------------
//　【 デストラクタ 】
//------------------------------------------------------------
DoublyLinkedList::~DoublyLinkedList()
{
	// 解放処理
	Node* temp = GetTopPtr();
	Node* dele = nullptr;

	// temp が NULL じゃなけばdelete
	while (temp != nullptr)
	{
		dele = temp;

		temp = temp->nextPtr;

		delete dele;
	}
}


//------------------------------------------------------------
//　【 先頭にデータを追加 】
//　addRecordData：追加したい成績データ
//------------------------------------------------------------
void DoublyLinkedList::AddTop(RecordData addRecordData)
{
	// 先頭のノードへのポインタを格納
	Node* topPtr = GetTopPtr();

	// topPtr が NULL の場合は最初のデータとして topPtr に追加
	if (topPtr == nullptr)
	{
		topPtr = new Node();

		// 引数からデータを追加
		topPtr->recordData.word = addRecordData.word;
		topPtr->recordData.description = addRecordData.description;

		// 前後のポインタを更新
		topPtr->prevPtr = nullptr;
		topPtr->nextPtr = nullptr;

		// thisPtr を更新
		thisPtr = topPtr;
	}
	// topPtrがNULLじゃなければ次のノードへのポインタにデータを追加
	else
	{
		topPtr->prevPtr = new Node();

		// 引数からデータを追加
		topPtr->prevPtr->recordData.word = addRecordData.word;
		topPtr->prevPtr->recordData.description = addRecordData.description;

		// 前後のポインタを更新
		topPtr->prevPtr->nextPtr = topPtr;
		topPtr->prevPtr->prevPtr = nullptr;

		// thisPtr を更新
		thisPtr = topPtr->prevPtr;
	}
}


//------------------------------------------------------------
//　【 末尾にデータを追加 】
//　addRecordData：追加したい成績データ
//------------------------------------------------------------
void DoublyLinkedList::AddEnd(RecordData addRecordData)
{
	// 末尾のノードへのポインタを格納
	Node* endPtr = GetEndPtr();

	// endPtr が NULL の場合は最初のデータとして endPtr に追加
	if (endPtr == nullptr)
	{
		endPtr = new Node();

		// 引数からデータを追加
		endPtr->recordData.word = addRecordData.word;
		endPtr->recordData.description = addRecordData.description;

		// 前後のポインタを更新
		endPtr->prevPtr = nullptr;
		endPtr->nextPtr = nullptr;

		// thisPtr を更新
		thisPtr = endPtr;
	}
	// endPtrがNULLじゃなければ次のノードへのポインタにデータを追加
	else
	{
		endPtr->nextPtr = new Node();
		
		// 引数からデータを追加
		endPtr->nextPtr->recordData.word = addRecordData.word;
		endPtr->nextPtr->recordData.description = addRecordData.description;

		// 前後のポインタを更新
		endPtr->nextPtr->prevPtr = endPtr;
		endPtr->nextPtr->nextPtr = nullptr;

		// thisPtr を更新
		thisPtr = endPtr->nextPtr;
	}
}


//------------------------------------------------------------
//　【 先頭のノードを取得 】
//　return：先頭のノードのポインタ
//　※ノード（要素）が０の場合は NULL の状態で返す
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::GetTopPtr()
{
	// 先頭のノードへのポインタを格納
	Node* topPtr = thisPtr;

	// topPtr が NULL の場合はそのまま返す
	if (topPtr != nullptr)
	{
		// 次のノードへのポインタがNULLになるまで確認
		while (topPtr->prevPtr != nullptr)
		{
			topPtr = topPtr->prevPtr;
		}
	}

	// 先頭のノードへのポインタを返す
	return topPtr;
}


//------------------------------------------------------------
//　【 末尾のノードを取得 】
//　return：末尾のノードのポインタ
//　※ノード（要素）が０の場合は NULL の状態で返す
//------------------------------------------------------------
DoublyLinkedList::Node* DoublyLinkedList::GetEndPtr()
{
	// 末尾のノードへのポインタを格納
	Node* endPtr = thisPtr;
	
	// endPtr が NULL の場合はそのまま返す
	if (endPtr != nullptr)
	{
		// 次のノードへのポインタがNULLになるまで確認
		while (endPtr->nextPtr != nullptr)
		{
			endPtr = endPtr->nextPtr;
		}
	}

	// 末尾のノードへのポインタを返す
	return endPtr;
}


//------------------------------------------------------------
//　【 ソート（並び替え） 】
//------------------------------------------------------------
void DoublyLinkedList::Sort()
{
	// データの数を取得
	int dataCount = GetDataCount();

	// １つ以下ならreturn
	if (dataCount <= 1) return;

	// 先頭と末尾のポインタを取得
	Node* topPtr = GetTopPtr();
	Node* endPtr = GetEndPtr();

	// 入れ替えに使用するための変数
	Node *data1, *data2;

	for (int j = 0; j < dataCount - 1; j++)
	{
		// 先頭とその次のアドレスを比較
		data1 = topPtr;
		data2 = data1->nextPtr;

		for (int i = 0; i < dataCount - 1 - j; i++)
		{
			// list2のwordが高い場合は入れ替え
			if (data1->recordData.word < data2->recordData.word)
			{
				// list1の次とlist2の前の接続先を変更
				data1->nextPtr = data2->nextPtr;
				data2->prevPtr = data1->prevPtr;

				// 入れ替え後のそれぞれをつなぐ
				data2->nextPtr = data1;
				data1->prevPtr = data2;

				// 入れ替える前のlist1とlist2の前後の接続先を変更
				if (data1 == topPtr)
				{
					// list1が先頭だった場合
					topPtr = data2;
				}
				else
				{
					data2->prevPtr->nextPtr = data2;
				}

				if (data2 == endPtr)
				{
					// list2が最後だった場合
					endPtr = data1;
				}
				else
				{
					data1->nextPtr->prevPtr = data1;
				}

				// 次に比較するものをlist2へ代入
				data2 = data1->nextPtr;
			}
			else
			{
				// 次に比較するものを設定
				data1 = data1->nextPtr;
				data2 = data2->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//　【 データの削除 】
//　num：削除するデータの位置（1を先頭とする）
//------------------------------------------------------------
void DoublyLinkedList::Remove(int num)
{
	// リストの要素の個数を取得
	int count = GetDataCount();

	// 個数が0 または 削除したい位置が0 または 削除したい位置が個数より大きければ return
	if (count == 0 || num == 0 || num > count) return;

	// 削除に使用する変数
	Node* temp;

	// 先頭と末尾のポインタを取得
	Node* topPtr = GetTopPtr();
	Node* endPtr = GetEndPtr();

	if (count == 1)
	{
		// 要素が一つの場合

		// 削除
		delete topPtr;

		// 先頭と末尾をNULLにする
		thisPtr = topPtr = endPtr = nullptr;
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

		// 末尾の要素とthisPtrを更新
		endPtr = temp;
		thisPtr = temp;

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
}


//------------------------------------------------------------
//　【 データの数の取得 】
//　return：データの数
//------------------------------------------------------------
int DoublyLinkedList::GetDataCount()
{
	// データの数をカウントする変数
	int dataCount = 0;

	// 先頭ポインタを保存
	Node* temp = GetTopPtr();

	while (temp != nullptr)
	{
		// データをカウント
		dataCount++;

		// 次のポインタへ更新
		temp = temp->nextPtr;
	}

	// データの数を返す
	return dataCount;
}

