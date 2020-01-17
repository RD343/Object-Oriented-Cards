#ifndef CARDIMPLEMENTATION_CPP
#define CARDIMPLEMENTATION_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Card.h"
using namespace std;

/************************************
//Card constructor
//Suit and rank set to zero, or joker
************************************/
Card::Card()
{
	suit = 0;
	rank = 0;
}

/*************************************
//setSuit
//receives suit values for card object
*************************************/
void Card::setSuit(int aSuit)
{
	suit = aSuit;
}

/*************************************
//setRank
//receives rank values for card object
*************************************/
void Card::setRank(int aRank)
{
	rank = aRank;
}

/**************************************************************************
//toString
//Converts integer values of ranks and suits to string values for printing.
***************************************************************************/
string Card::toString() const
{
	string suitString;
	switch(suit)
	{
	case Joker:
		suitString = "Joker";
		break;
	case Hearts:
		suitString = "of Hearts";
		break;
	case Diamonds:
		suitString = "of Diamonds";
		break;
	case Clubs:
		suitString = "of Clubs";
		break;
	case Spades:
		suitString = "of Spades";
		break;
	}

	string rankString;		//Added all numbers for string conversion
	switch(rank)
	{
	case None:
		rankString = "";
		break;
	case Ace:
		rankString = "Ace ";
		break;
	case Two:
		rankString = "2 ";
		break;
	case Three:
		rankString = "3 ";
		break;
	case Four:
		rankString = "4 ";
		break;
	case Five:
		rankString = "5 ";
		break;
	case Six:
		rankString = "6 ";
		break;
	case Seven:
		rankString = "7 ";
		break;
	case Eight:
		rankString = "8 ";
		break;
	case Nine:
		rankString = "9 ";
		break;
	case Ten:
		rankString = "10 ";
		break;
	case Jack:
		rankString = "Jack ";
		break;
	case Queen:
		rankString = "Queen ";
		break;
	case King:
		rankString = "King ";
		break;
	}

	string cardString = rankString + suitString;
	return cardString;
}

/*********************************
//getSuit
//accepts arguments for suit value
*********************************/
int Card::getSuit() const
{
	return suit;
}

/*********************************
//getRank
//accepts arguments for suit value
*********************************/
int Card::getRank() const
{
	return rank;
}

/********************************************
//printCard
//takes toString argument and produces output
********************************************/
void Card::printCard() const //The if/else statement determines if rank will print as 1-10 or as a string
{
	if (suit < 0 || suit > 4 || rank < 0 || rank > 13)
		cout << "\nCard not built, Input error" << endl;
	else
		cout << "\n" << toString() << endl;
}
/*
//Overloaded the << operator
ostream& operator<< (ostream& os, const Card& randcard)
{
	os << randcard.toString();
	return os;
}*/
#endif
