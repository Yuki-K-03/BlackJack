#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
public:
	Dealer();
	virtual ~Dealer();

protected:
	//�Q�[�����s
	void playBase(Shoe& shoe);

};