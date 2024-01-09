#include <iostream>
#include "Card.h"


Card::Card() {
	_num = 0;
	_suit = 0;
}

int Card::getNum() {
	return _num;
}

int Card::getSuit() {
	return _suit;
}

void Card::setNum(int num){
#ifdef DEBUG
	printf("num : %d, ", num);
#endif // DEBUG
	if (1 <= num && num <= 13) {
		_num = num;
	}
	else {
		printf("エラー\n");
	}
}

void Card::setSuit(int suit){
#ifdef DEBUG
	printf("suit : %d, \n", suit);
#endif // DEBUG
	if (1 <= suit && suit <= 4) {
		_suit = suit;
	}
	else {
		printf("エラー\n");
	}
}

