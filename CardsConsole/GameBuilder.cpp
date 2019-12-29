#include "pch.h"
#include "GameBuilder.h"
#include "Game.h"
#include "VerboseGame.h"


GameBuilder::GameBuilder() :
	p1Deck(),
	p2Deck()
{

}

GameBuilder::~GameBuilder()
{
}

Game GameBuilder::createGame(Deck d1, Deck d2)
{
	return Game(d1, d2);
}

Game GameBuilder::createGame()
{
	Deck d; 
	d.build();
	d.shuffle();
	Deck d1;
	Deck d2;
	while (d.size() > 0)
	{
		d1.receive(d.deal());
		d2.receive(d.deal());
	}
	return Game(d1, d2);
}

