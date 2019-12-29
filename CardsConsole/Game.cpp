#include "pch.h"
#include "Game.h"


Game::Game() :
	turns(0)
{
}

Game::Game(Deck d1, Deck d2) :
	player1(),
	player2(),
	turns(0)
{
	player1.Receive(d1);
	player2.Receive(d2);
}


Game::~Game()
{
}

void Game::start()
{
	deck.build();
	deck.shuffle();
	while (deck.size() > 0)
	{
		player1.Receive(deck.deal());
		player2.Receive(deck.deal());
	}
}

void Game::turn()
{
	Deck inPlay;
	result res; 
	do {
		// Both players flip cards
		shared_ptr<Card> p1card = player1.PlayCard();
		shared_ptr<Card> p2card = player2.PlayCard();
		inPlay.receive(p1card);
		inPlay.receive(p2card);
		// Judge winner
		res = judge(*p1card, *p2card);
		if (res == TIE) {
			handleTie(inPlay);
		}
	} while (res == TIE && !complete());

	// Award winner
	award(res, inPlay);
	// Increment turns
	turns++;
}

void Game::flip(Deck & inPlay)
{
}

result Game::judge(Card c1, Card c2)
{
	if (c1 > c2) {
		return PLAYER1_WIN;
	}
	else if (c1 < c2) {
		return PLAYER2_WIN;
	}
	else {
		return TIE;
	}
}

void Game::handleTie(Deck &inPlay)
{
	// Each player passes in cards
	for (int i = 0; i < 3; i++) {
		if (player1.size() > 2 && player2.size() > 2) {
			inPlay.receive(player1.PlayCard());
			inPlay.receive(player2.PlayCard());
		}
	}
}

void Game::award(result res, Deck cards)
{
	if (res == PLAYER1_WIN) {
		player1.Receive(cards);
		//player1Pile.receive(cards);
	}
	else if (res == PLAYER2_WIN) {
		player2.Receive(cards);
		//player2Pile.receive(cards);
	}
}

int Game::getScore1()
{
	// Move to player class 
	return player1.size();
}

int Game::getScore2()
{
	return player2.size();
}

bool Game::complete()
{
	return player1.size() == 0 || player2.size() == 0;
}

int Game::getTurns()
{
	return turns;
}



