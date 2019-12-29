#pragma once

#include "Deck.h"
#include "Card.h"

#include <memory>

class Player
{
public:
	Player();
	Player(string _name);
	virtual ~Player();

	string GetName(void); 

	int size(void); 

	// Players have 2 piles, their decks and their winnings. 
	// Players can receive cards
	void Receive(Deck &_deck);
	void Receive(shared_ptr<Card> _card);
	// Players can play cards 
	shared_ptr<Card> PlayCard(void); 

private:
	string name; 
	Deck deck; 
	Deck winnings; 

};

