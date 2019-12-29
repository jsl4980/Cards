#pragma once
#include "Deck.h"
#include "Game.h"

class GameBuilder
{
public:
	GameBuilder();
	virtual ~GameBuilder();
	Game createGame(Deck d1, Deck d2);
	Game createGame(); 

	Deck p1Deck;
	Deck p2Deck;
};

