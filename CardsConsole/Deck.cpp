#include "pch.h"
#include "Deck.h"
#include <algorithm>
#include <random>
#include <assert.h>
#include <chrono>


Deck::Deck()
{
}

Deck::Deck(const Deck & d)
{
	// Copy all of the cards into a new deck. 
	for (auto card : d.cards) {
		receive(make_shared<Card>(card->getSuit(), card->getValue()));
	}
}

Deck::~Deck()
{
}

void Deck::build()
{
	for (auto suit : SUITS) {
		for (auto val : VALUES) {
			receive(make_shared<Card>(suit, val));
		}
	}
}

void Deck::shuffle()
{
	// obtain a time-based seed:
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine e(seed);
	std::shuffle(cards.begin(), cards.end(), e);
}

shared_ptr<Card> Deck::deal()
{
	assert(!cards.empty());
	shared_ptr<Card> ret = cards.front();
	cards.erase(cards.begin());
	return ret;
}

void Deck::receive(shared_ptr<Card> card)
{
	cards.push_back(card);
}

void Deck::receive(Deck &deck)
{
	while (deck.size() > 0) {
		receive(deck.deal());
	}
}

int Deck::size()
{
	return cards.size();
}

