#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;


Dealer::Dealer() : Person("Dealer") {

}

Dealer::~Dealer() {

}

//�Q�[�����s
void Dealer::playBase(Shoe& shoe) {
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (getScore() < 17 && getScore() > 0) {
		//�q�b�g����
		hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
		cout << "====================" << endl;
		cout << getName() << endl;
		showHand();
		cout << "====================" << endl;
	}
}