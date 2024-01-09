#pragma once

#include "Person.h"

//プレイヤークラス
class Player : public Person
{
public :
	Player(const char* name);
	virtual ~Player();

protected:
	//ゲーム実行
	void playBase(Shoe& shoe);
};
