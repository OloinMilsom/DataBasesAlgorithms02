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
	if (value == 1)
	{
		std::cout << "Ace" << suitStr;
	}
	else if (value == 11)
	{
		std::cout << "Jack" << suitStr;
	}
	else if(value == 12)
	{
		std::cout << "Queen" << suitStr;
	}
	else if(value == 13)
	{
		std::cout << "King" << suitStr;
	}
	else
	{
		std::cout << value << suitStr;
	}
}
