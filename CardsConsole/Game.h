#pragma once
#include <stack>
#include <memory>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

enum result {
	PLAYER1_WIN,
	PLAYER2_WIN,
	TIE
};

class Game
{
public:
	Game();
	Game(Deck d1, Deck d2);
	virtual ~Game();

	void start();
	virtual void turn();
	virtual void flip(Deck &inPlay);
	virtual result judge(Card c1, Card c2);
	virtual void handleTie(Deck &inPlay);
	shared_ptr<Card> Player1Deal();
	shared_ptr<Card> Player2Deal();
	void award(result res, Deck cards);
	int getScore1();
	int getScore2();
	bool complete();
	int getTurns();

private:
	Deck deck;
	Player player1;
	Player player2; 
	Deck player1Pile;
	Deck player1Winnings;
	Deck player2Pile;
	Deck player2Winnings; 
	int turns;
};

