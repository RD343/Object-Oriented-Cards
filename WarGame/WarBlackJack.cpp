#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Card.h"
#include "Card.cpp"
#include "Deck.h"
#include "Deck.cpp"
using namespace std;

int main()
{
	system("clear");
	srand(time(NULL));

	Deck myDeck;		//Calls Deck constructor, makes object myDeck
	myDeck.buildDynamic();

	menu(myDeck);		//menu() is located in Deck.cpp
				//and initialised in Deck.h, outside of the deck class
	return 0;
}
