#pragma once

#include "common.h"
#include "Card.h"

//�J�[�h�V���[�N���X
class Shoe {

private:
	//��{�I�ɃJ�[�h�V���[��private
	int cardShoe[CARD]; //�J�[�h�z��
	Card _cardShoe[CARD];
	int _cardNum; //�J�[�h����

	void _shoeMake();
	void _shuffle();

public:
	enum SHOW_TYPE
	{
		CARD_ONLY,
		ALL
	};

	//�R���X�g���N�^
	Shoe();

	//�J�[�h��1�����o��
	Card takeCard();

	//�J�[�h�V���[��\��(�f�o�b�O�p)
	void showShoe(SHOW_TYPE type = CARD_ONLY);
};

