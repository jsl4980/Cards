#pragma once
#include <vector>
#include <memory>
#include "Card.h"

class Deck
{
public:
	Deck();
	virtual ~Deck();

	void build();
	int size();

private: 
	std::vector<std::shared_ptr<Card>> cards;
};

