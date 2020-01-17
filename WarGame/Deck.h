#ifndef DECK_H
#define DECK_H

class Deck
{	
friend class Card;
public:
	int rankSum;
	Card** cardPlace;
	Deck();
	void buildDynamic();
	void fillDeck();
	void addCard(Card draw);
	int getRankSum();
	void viewHand();
	void blackjack(Deck playerHand, Deck houseHand);
	Card drawCard();
	void gameOfWar();
	~Deck();
};
void menu(Deck myDeck);
#endif
