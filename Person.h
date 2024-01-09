#pragma once

#include "common.h"
#include "Card.h"

class Shoe;

class Person
{
private:
	Card _hand[HAND_SIZE];
	bool _calcUpdate;
	char* _pName;
	int _cardNum;
	int _score;

public:
	// コンストラクタ
	Person(const char* name);
	// コピーコンストラクタ
	Person(const Person& other);

	// デストラクタ
	virtual ~Person();

	// 名前の取得
	char* getName();

	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe& shoe);

	//手札を表示
	void showHand();

	//ターン処理
	bool play(Shoe& shoe);

protected:
	virtual void playBase(Shoe& shoe) = 0;	//ターン処理本体

};

