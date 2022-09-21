//
//  Card.h
//  CardGameWar
//
//  Created by Prabhanjan Piwalatkar on 4/12/22.
//

#pragma once

class Card
{
public:
    enum Suit{CLUB, DIAMOND, HEART, SPADE};
    enum Value{TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

public:
    Card(Suit suit, Value value);
    ~Card();

public:
    void print();
    bool sameSuit(Card compare);
    int compareValue(Card compare);

protected:
    Suit suit;
    Value value;
};

