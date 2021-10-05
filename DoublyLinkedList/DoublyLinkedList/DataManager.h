//============================================================
//
//  title  : データ管理 [DataManager.h]
//  Author : 原田 陽央
//   Date  : 2021/10/05
//  Update : 2021/10/05
//
//============================================================
#pragma once
#include <iostream>

using namespace std;


//============================================================
//　クラス宣言
//============================================================
class DataManager
{
private:
	

public:
	DataManager();   // コンストラクタ
	~DataManager();  // デストラクタ

	static void ReadScoreTextFile(void);
	static void LoadData(void);

	static string data;       // 全データを格納
};