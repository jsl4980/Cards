#pragma once
#include <string>
#include "Cards.h"

class Card
{
public:
	Card(suit s, cardValue v);
	virtual ~Card();

	cardValue getValue();

	std::string toString(); 
	friend bool operator==(const Card &lhs, const Card &rhs);
	friend bool operator<(const Card &lhs, const Card &rhs);
	friend bool operator>(const Card &lhs, const Card &rhs);

private:
	suit mSuit;
	cardValue mValue;
};

