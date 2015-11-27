// I declare that the work I am submitting for assessing by the Institute examiner(s) is entirely my own
// work, save for any portion(s) thereof where the author or source has been duly referenced and
// attributed.
// Signed: Niall Milsom (C00179300)

// Wiki Page for Beggar-My-Neighbour: https://en.wikipedia.org/wiki/Beggar-My-Neighbour

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Card.h"

using namespace std;

int main(){ // the console playes beggar-my-neighbour
	srand(time(0));
	vector<Card> deck;
	vector<Card> hand1;
	vector<Card> hand2;
	vector<Card> pile;

	// initialise the deck
	for (int i = 0; i < 52; i++)
	{
		deck.push_back(Card(static_cast<Suit>(i / 13), 1 + i % 13));
	}

	// shuffle
	random_shuffle(deck.begin(), deck.end());

	// deal
	for (vector<Card>::iterator curr = deck.begin(); curr < deck.end(); curr += 2)
	{
		hand1.push_back(*curr);
		hand2.push_back(*(curr + 1));
	}

	// play
	bool currHand = true; // true for 1, false for 2
	while (!(hand1.empty() || hand2.empty()))
	{
		// normal play
		if (pile.empty() || pile.back().getValue() < 11 && pile.back().getValue() != 1)
		{
			if (currHand){
				pile.push_back(hand1.back());
				cout << "p1: ";
				hand1.back().print();
				cout << endl;
				hand1.pop_back();
			}
			else {
				pile.push_back(hand2.back());
				cout << "p2: ";
				hand2.back().print();
				cout << endl;
				hand2.pop_back();
			}
		}
		// penalty cards
		else {
			// calculate cards to place
			int cardsToPlace;
			bool lostPlay = true;
			if (pile.back().getValue() == 1)
			{
				cardsToPlace = 4;
			}
			if (pile.back().getValue() == 13)
			{
				cardsToPlace = 3;
			}
			if (pile.back().getValue() == 12)
			{
				cardsToPlace = 2;
			}
			if (pile.back().getValue() == 11)
			{
				cardsToPlace = 1;
			}
			// place the cards
			for (int i = 0; i < cardsToPlace; i++)
			{
				if (currHand){
					pile.push_back(hand1.back());
					cout << "p1: ";
					hand1.back().print();
					cout << endl;
					hand1.pop_back();
					if (hand1.empty())
						break;
				}
				else {
					pile.push_back(hand2.back());
					cout << "p2: ";
					hand2.back().print();
					cout << endl;
					hand2.pop_back();
					if (hand2.empty())
						break;
				}
				// if a penalty card is placed, break
				if (pile.back().getValue() > 10 || pile.back().getValue() == 1)
				{
					lostPlay = false;
					break;
				}
			}
			if (lostPlay){
				// hand1 lost play
				if (currHand)
				{
					vector<Card> temp = hand2;
					hand2.clear();
					reverse(pile.begin(), pile.end());
					hand2.reserve(pile.size() + temp.size());
					hand2.insert(hand2.end(), pile.begin(), pile.end());
					hand2.insert(hand2.end(), temp.begin(), temp.end());
					cout << "Hand 2 won " << pile.size() << " cards" << endl;
					pile.clear();
				}
				// hand2 lost play
				else {
					vector<Card> temp = hand1;
					hand1.clear();
					reverse(pile.begin(), pile.end());
					hand1.reserve(pile.size() + temp.size());
					hand1.insert(hand1.end(), pile.begin(), pile.end());
					hand1.insert(hand1.end(), temp.begin(), temp.end());
					cout << "Hand 1 won " << pile.size() << " cards" << endl;
					pile.clear();
				}
			}
		}
		currHand = !currHand;
	}

	if (hand1.empty())
	{
		cout << "Hand 2 wins!" << endl;
	}
	else {
		cout << "Hand 1 wins!" << endl;
	}
	system("PAUSE");
}