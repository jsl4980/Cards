#pragma once
#include <vector>
#include <memory>
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck();
	Deck(const Deck &d); // copy constructor
	virtual ~Deck();

	void build();
	void shuffle();
	shared_ptr<Card> deal();
	void receive(shared_ptr<Card> card);
	void receive(Deck &deck);
	int size();

private:
	std::vector<std::shared_ptr<Card>> cards;
};
