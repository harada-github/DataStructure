//============================================================
//
//  title  : データ構造（スタック） [HashTable.cpp]
//  Author : 原田 陽央
//   Date  : 2021/10/06
//  Update : 2021/10/06
//
//============================================================
#include "hashTable.h"
#include "list.h"


//============================================================
//　変数宣言
//============================================================
List* HashTable::hashData[10];


//============================================================
//　関数
//============================================================
//------------------------------------------------------------
//　コンストラクタ
//------------------------------------------------------------
HashTable::HashTable()
{
	// 初期化をしておく
	for (int i = 0; i < 10; i++)
	{
		hashData[i] = nullptr;
	}
}


//------------------------------------------------------------
//　デストラクタ
//------------------------------------------------------------
HashTable::~HashTable()
{
	// 代入用の変数
	List* temp = nullptr;
	List* dele = nullptr;

	// データの解放
	for (int i = 0; i < 10; i++)
	{
		if (hashData[i] == nullptr)
		{
			continue;
		}
		else
		{
			temp = hashData[i];

			// データがある場合はその次のポインタを確認
			while (temp != nullptr)
			{
				dele = temp;
				temp = temp->nextPtr;
				delete dele;
			}
		}
	}
}


//------------------------------------------------------------
//　単語から検索
//------------------------------------------------------------
void HashTable::Search(string aWord)
{
	// エラーチェック
	if (hashData[GetHash(aWord)] == nullptr)
	{
		std::cout << "一致するデータが見つかりませんでした。" << std::endl;
	}
	// wordが一致したらデータを表示
	else
	{
		// 代入用の変数
		List* temp = hashData[GetHash(aWord)];

		// データがある場合はその次のポインタを確認
		while (temp->nextPtr != nullptr)
		{
			temp = temp->nextPtr;
		}

		// 同じ名前の単語が見つかった場合
		if (temp->GetWord() == aWord)
		{
			// データ表示
			temp->OutputData();
			return;
		}
		else
		{
			// データがない場合
			std::cout << "一致するデータが見つかりませんでした。" << std::endl;
		}
		
	}
}


//------------------------------------------------------------
//　要素を追加する
//------------------------------------------------------------
void HashTable::AddData(string aWord, string aDescription)
{
	// チェイン法

	if (hashData[GetHash(aWord)] == nullptr)
	{
		// データを生成
		hashData[GetHash(aWord)] = List::Create(aWord, aDescription);
	}
	else
	{
		// 代入用の変数
		List* temp = hashData[GetHash(aWord)];

		// データがある場合はその次のポインタを確認
		while (temp->nextPtr != nullptr)
		{
			// 同じ単語がある場合はreturn
			if (temp->GetWord() == aWord)
			{
				std::cout << "同じ名前の単語が存在します" << std::endl;
				return;
			}

			temp = temp->nextPtr;
		}

		// データの生成と前後のポインタの更新
		temp->nextPtr = List::Create(aWord, aDescription);
		temp->nextPtr->prevPtr = temp;
		temp->nextPtr->nextPtr = nullptr;

	}
	
}


//------------------------------------------------------------
//　データの一覧
//------------------------------------------------------------
void HashTable::DataList()
{
	AddData("つくえ", "本を読み、字を書き、また仕事をするために使う台。");
	AddData("いす", "人が腰をかけるための家具の総称。");
	AddData("たんす", "引出し，戸棚，衣装盆等からなる収納家具。");
	AddData("れいぞうこ", "食品を貯蔵するために、収容部の温度を低温度に保つことができる装置。");
	AddData("ベッド", "睡眠、休息のために横臥(おうが)する家具。");
	AddData("テレビ", "テレビジョンの略");
	AddData("ごみばこ", "不要になったファイルやフォルダを一時的に保管する場所のこと。");
	AddData("ゲーム", "遊びごと。");
}


//------------------------------------------------------------
//　ハッシュ値を計算
//------------------------------------------------------------
int HashTable::GetHash(string aWord)
{
	return aWord.length() % 10;
}

