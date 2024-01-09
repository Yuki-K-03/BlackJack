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
	// �R���X�g���N�^
	Person(const char* name);
	// �R�s�[�R���X�g���N�^
	Person(const Person& other);

	// �f�X�g���N�^
	virtual ~Person();

	// ���O�̎擾
	char* getName();

	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe& shoe);

	//��D��\��
	void showHand();

	//�^�[������
	bool play(Shoe& shoe);

protected:
	virtual void playBase(Shoe& shoe) = 0;	//�^�[�������{��

};

