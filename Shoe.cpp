#include "Shoe.h"
#include <iostream>
#include <random> //��������

using namespace std;


void Shoe::_shoeMake() {
	//�J�[�h�����Ă�0.... /13�ŃJ�[�h��ނƂ���
	for (int i = 0; i < CARD; i++) {
		cardShoe[i] = i % 13 + 1;
	}

	//�J�[�h�����Ă�0.... /13�ŃJ�[�h��ނƂ���
	for (int i = 0; i < CARD; i++) {
		_cardShoe[i].setNum(i % 13 + 1);
		_cardShoe[i].setSuit(i / 13 + 1);
		cardShoe[i] = i % 13 + 1;
	}

	_cardNum = CARD - 1; //�J�[�h�����̐ݒ�

	//�V���b�t��
	_shuffle();
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

//�R���X�g���N�^
Shoe::Shoe() {
	_shoeMake();
}

//�J�[�h�V���[��\��(�f�o�b�O�p)
void Shoe::showShoe(SHOW_TYPE type) 
{
	int roopCnt = CARD;
	if (type == CARD_ONLY) {	//�J�[�h�������\��
		//�J�[�h�̂ݕ\���ɂ���B
		roopCnt = _cardNum + 1;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i].getNum() << "," << _cardShoe[i].getSuit() << ' ';
	}
	cout << endl;
}

//�J�[�h��1�����o��
Card Shoe::takeCard() {
#ifdef DEBUG
	printf("\nnum %d   take %d - %d\n", _cardNum, _cardShoe[_cardNum].getSuit(), _cardShoe[_cardNum].getNum());
#endif // DEBUG

	//�J�[�h������0�ȉ��������ꍇ,�G���[�Ƃ��ďo��
	if (_cardNum <= 0) {
		//�W���o��
		cout << "�f�b�L���Đ���" << endl;
		_shoeMake();
		return  takeCard();
	}

	return _cardShoe[_cardNum--];
}
