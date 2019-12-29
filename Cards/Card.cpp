#include "stdafx.h"
#include "Card.h"

Card::Card(suit s, cardValue v) :
	mSuit(s),
	mValue(v)
{
}

Card::~Card()
{
}

cardValue Card::getValue()
{
	return mValue;
}

std::string Card::toString()
{
	return VALUE_NAMES[mValue] + " of " + SUIT_NAMES[mSuit];
}

bool operator==(const Card & lhs, const Card & rhs)
{
	return lhs.mValue == rhs.mValue;
}

bool operator<(const Card & lhs, const Card & rhs)
{
	return lhs.mValue < rhs.mValue;
}

bool operator>(const Card & lhs, const Card & rhs)
{
	return lhs.mValue > rhs.mValue;
}
