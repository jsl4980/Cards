#include "stdafx.h"
#include "Deck.h"


Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::build()
{
	for (auto suit : SUITS) {
		for (auto val : VALUES) {
			auto c = std::make_shared<Card>(suit, val);
			cards.push_back(c);
		}
	}
}

int Deck::size()
{
	return cards.size();
}

