#ifndef CARD_H
#define CARD_H

#include "Suit.h"
#include <iostream>
#include <string>

class Card {
private:
	Suit suit;
	int value;
public:
	Card(Suit s = Suit::Spades, int v = 1);
	int getValue();
	void print();
};

#endif