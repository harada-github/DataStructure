//============================================================
//
//  title  : データ構造（スタック） [HashTable.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/11
//
//============================================================
//============================================================
//　インクルード
//============================================================
#include "hashTable.h"
#include "list.h"
#include "DoublyLinkedList.h"


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
HashTable::HashTable()
{
	;
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
HashTable::~HashTable()
{
	;
}


//------------------------------------------------------------
//　単語を表示
//------------------------------------------------------------
void HashTable::Disp()
{
	// 代入用の変数
	DoublyLinkedList::Node* temp = nullptr;

	// 文を表示
	std::cout << "[調べることができる単語の一覧]" << std::endl;

	// データの一覧表示
	for (int i = 0; i < 10; i++)
	{
		if (hashData[i].GetDataCount() == 0)
		{
			continue;
		}
		else
		{
			temp = hashData[i].GetTopPtr();

			// データがある場合はその次のポインタを確認
			while (temp != nullptr)
			{
				// データ表示
				std::cout << "・" << temp->recordData.word << std::endl;
				temp = temp->nextPtr;
			}
		}
	}
}


//------------------------------------------------------------
//　単語から検索
//------------------------------------------------------------
RecordData HashTable::Search(const string& searchWord)
{
	// ハッシュ値を保存
	int hash = GetHash(searchWord);

	// データがなかった場合に返すRecordData
	RecordData nullData = {};

	// エラーチェック
	if (hashData[hash].GetDataCount() == 0)
	{
		return nullData;
	}
	// wordが一致したらデータを表示
	else
	{
		// 代入用の変数
		DoublyLinkedList::Node* temp = hashData[hash].GetTopPtr();

		while (temp != nullptr)
		{
			if (temp->recordData.word == searchWord)
			{
				return temp->recordData;
			}

			// 次ポインタへ更新
			temp = temp->nextPtr;
		}
	}

	return nullData;
}


//------------------------------------------------------------
//　要素を追加する
//------------------------------------------------------------
void HashTable::AddData(const RecordData& addRecordData)
{
	// チェイン法

	// ハッシュ値を保存
	int hash = GetHash(addRecordData.word);

	// データを生成
	hashData[hash].AddEnd(addRecordData);
}


//------------------------------------------------------------
//　ハッシュ値を計算
//------------------------------------------------------------
int HashTable::GetHash(const string& getWord)
{
	// 文字数を１０で割った余りをハッシュ値とする
	return getWord.length() / 2 % 10;
}
