#include "pch.h"
#include "VerboseGame.h"
#include <iostream>


VerboseGame::VerboseGame() :
	level(0)
{
}

VerboseGame::VerboseGame(int level) :
	level(level)
{
}


VerboseGame::~VerboseGame()
{
}

void VerboseGame::turn()
{
	Game::turn();
	printScore();
}

result VerboseGame::judge(Card c1, Card c2)
{
	result res = Game::judge(c1, c2);
	if (level > 0)
	{
		cout << "Player 1: " << c1.toString() << " | Player 2: " << c2.toString() << endl;
		if (res == PLAYER1_WIN) {
			cout << "Player 1 wins" << endl;
		}
		else if (res == PLAYER2_WIN) {
			cout << "Player 2 wins" << endl;
		}
		else {
			cout << "TIED!!" << endl;
		}
	}
	return res;
}

void VerboseGame::printScore()
{
	cout << "Turn:  " << getTurns();
	cout << " | Player 1 score: " << getScore1();
	cout << " | Player 2 score: " << getScore2() << endl;
}
