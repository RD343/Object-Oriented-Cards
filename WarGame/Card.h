#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

enum Suit {Joker = 0, Clubs, Diamonds, Hearts, Spades};
enum Rank {None = 0, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};	//Added all numbers for string conversion

class Card
{
	friend class Deck;

private:
	int suit;
	int rank;
	void setSuit(int aSuit);
	void setRank(int aRank);
public:
	Card();
	Card(int aSuit, int aRank);
	string toString() const;		//This would not work without std:: in front of string
	int getSuit() const;
	int getRank() const;
	friend bool operator< (Card& tempCard_A, Card& tempCard_B);
	friend bool operator> (Card& tempCard_A, Card& tempCard_B);
	friend ostream& operator<< (ostream& os, const Card& argCard);
};

int operator+ (Card, int);
int operator+ (int, Card);
#endif
