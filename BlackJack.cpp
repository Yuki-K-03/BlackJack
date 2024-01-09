#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p, int num)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << p[0]->getName() << endl;
	p[0]->showHand();
	for (int i = 1; i < num; i++) {
	cout << "============================" << endl;
		cout << p[i]->getName() << endl;
		p[i]->showHand();
	cout << "============================" << endl;
	}
	for (int i = 1; i < num; i++) {
		if (p[0]->getScore() < p[i]->getScore()) {
			cout << p[i]->getName() << "Win!" << endl;
		}
		else if (p[0]->getScore() > p[i]->getScore()) {
			cout << p[i]->getName() << "Lose" << endl;
		}
		else {
			cout << p[i]->getName() << "Push" << endl;
		}
	}
	cout << "============================" << endl;
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	cout << p->getName() << endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	//各オブジェクトの生成
	Shoe shoe;
#ifdef DEBUG
	shoe.showShoe();
#endif // DEBUG

	Person* persons[] = { new Dealer, new Player("Player1"), new Player("Player2"), new Player("Player3") };
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}

	//ディーラーに2枚目を配布
	persons[0]->hit(shoe);

	//プレイヤーに2枚目を配布
	for (int i = 1; i < num; i++) {
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}


	// ----　勝負開始
	printf("ゲーム開始\n");
	//プレイヤーの実行
	//バーストしているかどうか判別
	for (int i = 1; i < num; i++) {
		showHand(persons[i]);
		persons[i]->play(shoe);
	}
	//ディーラーの手札を表示
	showHand(persons[0]);

	//ディーラーの自動実行
	persons[0]->play(shoe);
	//結果の表示
	showResult(persons, num);

	return 0;
}