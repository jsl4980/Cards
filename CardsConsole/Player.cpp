#include "pch.h"
#include "Player.h"

#include <iostream>


Player::Player() :
	name("Player")
{
}

Player::Player(string _name) :
	name(_name)
{
}


Player::~Player()
{
}

string Player::GetName(void)
{
	return name;
}

int Player::size(void)
{
	return winnings.size() + deck.size();
}

void Player::Receive(Deck & _deck)
{
	winnings.receive(_deck);
}

void Player::Receive(shared_ptr<Card> _card)
{
	winnings.receive(_card);
}

shared_ptr<Card> Player::PlayCard(void)
{
	if (deck.size() == 0 && winnings.size() > 0)
	{
		deck.receive(winnings);
		deck.shuffle();
	}
	return deck.deal();
}
