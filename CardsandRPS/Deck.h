#ifndef DECK_H
#define DECK_H

class Deck : public Card
{
//friend class Card;
public:
	int rankSum;
	Card** cardPlace;
	Deck();
	void nullPointers();
	void fillDeck();
	void addCard(Card draw);
	int getRankSum();
	void viewHand();
	Card drawCard();
	~Deck();
};
#endif
