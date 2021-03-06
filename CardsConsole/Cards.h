#pragma once

#include <string>

enum suit {
	SPADES,
	CLUBS,
	HEARTS,
	DIAMONDS
};

static const suit SUITS[] = {
	SPADES, CLUBS, HEARTS, DIAMONDS
};

static const std::string SUIT_NAMES[] = {
	"SPADES", "CLUBS", "HEARTS", "DIAMONDS"
};

enum cardValue {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

static const cardValue VALUES[] = {
	TWO, THREE, FOUR, FIVE, SIX,
	SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING, ACE
};

static const std::string VALUE_NAMES[] = {
	"TWO", "THREE", "FOUR", "FIVE", "SIX",
	"SEVEN", "EIGHT", "NINE", "TEN",
	"JACK", "QUEEN", "KING", "ACE"
};

