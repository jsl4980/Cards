#pragma once
#include "Game.h"

using namespace std;

class VerboseGame :
	public Game
{
public:
	VerboseGame();
	VerboseGame(int level);
	virtual ~VerboseGame();

	virtual void turn();
	virtual result judge(Card c1, Card c2);

	void printScore();
private:
	int level;	// zero is a little, 1 is a lot
};

