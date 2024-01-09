#pragma once

#include "common.h"
#include "Card.h"

//カードシュークラス
class Shoe {

private:
	//基本的にカードシューはprivate
	int cardShoe[CARD]; //カード配列
	Card _cardShoe[CARD];
	int _cardNum; //カード枚数

	void _shoeMake();
	void _shuffle();

public:
	enum SHOW_TYPE
	{
		CARD_ONLY,
		ALL
	};

	//コンストラクタ
	Shoe();

	//カードを1枚取り出す
	Card takeCard();

	//カードシューを表示(デバッグ用)
	void showShoe(SHOW_TYPE type = CARD_ONLY);
};

