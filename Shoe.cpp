#include "Shoe.h"
#include <iostream>
#include <random> //乱数生成

using namespace std;


void Shoe::_shoeMake() {
	//カードを入れてく0.... /13でカード種類とする
	for (int i = 0; i < CARD; i++) {
		cardShoe[i] = i % 13 + 1;
	}

	//カードを入れてく0.... /13でカード種類とする
	for (int i = 0; i < CARD; i++) {
		_cardShoe[i].setNum(i % 13 + 1);
		_cardShoe[i].setSuit(i / 13 + 1);
		cardShoe[i] = i % 13 + 1;
	}

	_cardNum = CARD - 1; //カード枚数の設定

	//シャッフル
	_shuffle();
}

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

//コンストラクタ
Shoe::Shoe() {
	_shoeMake();
}

//カードシューを表示(デバッグ用)
void Shoe::showShoe(SHOW_TYPE type) 
{
	int roopCnt = CARD;
	if (type == CARD_ONLY) {	//カード枚数分表示
		//カードのみ表示にする。
		roopCnt = _cardNum + 1;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i].getNum() << "," << _cardShoe[i].getSuit() << ' ';
	}
	cout << endl;
}

//カードを1枚取り出す
Card Shoe::takeCard() {
#ifdef DEBUG
	printf("\nnum %d   take %d - %d\n", _cardNum, _cardShoe[_cardNum].getSuit(), _cardShoe[_cardNum].getNum());
#endif // DEBUG

	//カード枚数が0以下だった場合,エラーとして出力
	if (_cardNum <= 0) {
		//標準出力
		cout << "デッキを再生成" << endl;
		_shoeMake();
		return  takeCard();
	}

	return _cardShoe[_cardNum--];
}
