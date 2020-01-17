#ifndef DECK_H
#define DECK_H

class Deck
{	
friend class Card;
public:
	Card** cardPlace;
	Deck();
	void buildDynamic(int totalCards);
	void fillDeck(int totalCards);
	Card drawCard(int totalCards);
};
#endif
