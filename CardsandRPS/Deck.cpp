#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.h"
#include "Card.cpp"
#include "Deck.h"
using namespace std;

/******************************************
//Base Constructor
//Includes pointer reference initialization
******************************************/
Deck::Deck()
{	
	Card **cardPlace;
	rankSum = 0;
}

/***************************************************
//Makes empty Deck of NULL pointers
//only meant for use in blackjack, with player hands
//DO NOT USE WITH FILLDECK() OR MAIN DECK OBJECTS
****************************************************/
void Deck::nullPointers()
{
	cardPlace = new Card*[52];
	for(int i = 0; i < 52; i++)
		cardPlace[i] = NULL;
}

/******************************************************************
//fillDeck
//takes totalCards as an argument
//uses the size of the deck to create card objects for the pointers
//DO NOT USE WITH NULLPOINTER() OR PLAYER HANDS
*******************************************************************/
void Deck::fillDeck()
{
	cardPlace = new Card*[52];
	for(int i = 0; i < 52; i++)
		cardPlace[i] = NULL;

	int suitCount = 1;
	int rankCount = 1;
	for(int i = 0; i < 52; i++)
	{
		if(suitCount >= 1 && suitCount <=4)
			cardPlace[i] = new Card(suitCount, rankCount);
		else
		{
			suitCount = 1;
			rankCount++;
			cardPlace[i] = new Card(suitCount, rankCount);
		}
		suitCount++;
	}
}

/********************************************************************************************
//drawCard
//takes totalCards as an argument
//uses rand function to pull an initial random card object from the deck
//if/else, do/while, and try functions go through deck to a pointer not null
//once the counter == totalCards, then the deck is declared empty, breaking the do/while loop
********************************************************************************************/
Card Deck::drawCard()
{
	Card temp;
	int l = rand() % 52;
	int nullCount = 0;		//nullcount moderates the while loop.

	try
	{
		if(cardPlace[l] == NULL)
		{
			do		//the do/while function goes through the pointer array,
			{		//checking for NULL pointers
					//the starting point is whatever pointer is returned by
					//the random number function above
				if(l < 52)
				{
					l = l++;
					nullCount = nullCount++;
				}
				else
				{
					l = 0;
					nullCount = nullCount++;
				}
			}while(cardPlace[l] == NULL && nullCount != 52);
		}
		if(nullCount == 52 && cardPlace[l] == NULL) throw temp;

		temp = *cardPlace[l];
		cardPlace[l] = NULL;
		return temp;
	}

	catch(Card temp)
	{
		Card blank;
		cout << "\nThe deck is empty~ ";
		return blank;
	}
}

/**********************************************************************************
//This function adds a card to (what is meant to be) a blank or partial deck object
//The Deck object this is meant for should be a player's hand
//This function also keeps a tally of the rank sum in the deck object
**********************************************************************************/
void Deck::addCard(Card draw)
{
	int n = 0;
	do
	{
		if(cardPlace[n] == NULL)
		{
			cardPlace[n] = new Card(draw);
			break;
		}
		else if(cardPlace[n] != NULL)
		{
			n++;
		}
	}while(cardPlace[10] == NULL);

	rankSum = rankSum + draw;
}

/***********************************************************
//getRankSum
//Returns a deck's ranksum
//Unless otherwise changed, rankSum should be zero
//BlackJack function will change the rankSum of player decks
***********************************************************/
int Deck::getRankSum()
{
	return rankSum;
}

/**************************************
//view hand function
//prints all pointers that aren't NULL
**************************************/
void Deck::viewHand()
{
	int n = 0;
	Card temp;
	while(cardPlace[n] != NULL)
	{
		temp = *cardPlace[n];
		cout << temp << endl;
		n++;
	}
	cout << "Hand Score: " << getRankSum() << endl;
}

/***************
//Deconstructor
***************/
Deck::~Deck()
{}
