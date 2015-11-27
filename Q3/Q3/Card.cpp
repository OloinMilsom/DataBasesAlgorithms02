#include "Card.h"

Card::Card(Suit s, int v) : suit(s), value(v){

}

int Card::getValue(){
	return value;
}
void Card::print(){
	std::string suitStr;
	if (suit == Suit::Clubs)
		suitStr = " of Clubs";
	if (suit == Suit::Diamonds)
		suitStr = " of Diamonds";
	if (suit == Suit::Hearts)
		suitStr = " of Hearts";
	if (suit == Suit::Spades)
		suitStr = " of Spades";
	std::cout << value << suitStr;
}
