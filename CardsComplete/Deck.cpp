#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.cpp"
#include "Deck.h"
using namespace std;

/******************************************
//Base Constructor
//Includes pointer reference initialization
******************************************/
Deck::Deck()
{	
	headNodePtr = NULL;
}

/******************************************************************
//fillDeck
//takes totalCards as an argument
//uses the size of the deck to create card objects for the pointers
//DO NOT USE FOR DISCARD DECK OR ANY DECK THAT IS MEANT TO BE EMPTY
*******************************************************************/
void Deck::fillDeck()
{
	int suitCount = 1;
	int rankCount = 1;
	for(int i = 0; i < 52; i++)
	{
		if(suitCount >= 1 && suitCount <=4)
		{
			push(Card(suitCount, rankCount));
		}
		else
		{
			suitCount = 1;
			rankCount++;
			push(Card(suitCount, rankCount));
		}
		suitCount++;
	}
}

/*********************************************************************************
//Shuffle
//Can be used with a deck of any size
//Constructs two temporary decks
	//Takes turns popping from myDeck and pushing into the two temporary decks
//uses rand function and isEmpty function to pop cards from temps back into myDeck
	//Repeats ten times
**********************************************************************************/
void Deck::shuffle()
{
	Deck shuffle1;	//temporary decks
	Deck shuffle2;
	int count = 0;
	int cardCount;
	cardCount = getCount();
	
	for(int h = 0; h < 10; h++)
	{
		for(int i = 0; i < (cardCount / 2); i++)
		{
			shuffle1.push(pop());
		}
		
		for(int j = 0; j < (cardCount - (cardCount / 2)); j++)
		{
			shuffle2.push(pop());
		}
		
		for(int k = 0; k < cardCount; k++)
		{
			count = rand() % 2;
			
			if( (count == 0 && shuffle1.isEmpty() == false) || shuffle2.isEmpty() == true)
			{
				push(shuffle1.pop());
			}
			else
			{
				push(shuffle2.pop());
			}
		}
	}
}

/***************
//Deconstructor
***************/
Deck::~Deck()
{}
