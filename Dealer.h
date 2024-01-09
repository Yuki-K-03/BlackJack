#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
public:
	Dealer();
	virtual ~Dealer();

protected:
	//ゲーム実行
	void playBase(Shoe& shoe);

};