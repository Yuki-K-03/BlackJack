#pragma once
class Card
{
private :
	int _num;
	int _suit;

public :
	Card();
	int getNum();
	int getSuit();
	void setNum(int num);
	void setSuit(int suit);
};

