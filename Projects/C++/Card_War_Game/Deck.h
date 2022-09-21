//
//  Deck.h
//  CardGameWar
//
//  Created by Prabhanjan Piwalatkar on 4/12/22.
//

#pragma once

#include <vector>
#include "Card.h"
#include <stack>

class Deck
{
public:
    Deck();
    ~Deck();
public:
    void dealDeck();
    void shuffle();
    int drawCard(int numCards);
    void playerWin(int cards);
    void aiWin(int cards);
    long playerdecksize();
    long aidecksize();
    void compare(int cards);
protected:
    std::vector<Card> deck;
    std::vector<Card> playerDeck;
    std::vector<Card> aiDeck;
};
