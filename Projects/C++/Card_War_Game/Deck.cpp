//
//  Deck.cpp
//  CardGameWar
//
//  Created by Prabhanjan Piwalatkar on 4/12/22.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>
#include "Deck.h"
#include "Card.h"

Deck::Deck(){
    int index = 0;
    
    for (int i = (int)Card::Suit::CLUB; i <= (int)Card::Suit::SPADE; i++) {
        for (int j = (int)Card::Value::TWO; j <= (int)Card::Value::ACE; j++) {
            Card c((Card::Suit)i,(Card::Value)j);
            deck.push_back(c);
            index++;
        }
    }
}

Deck::~Deck(){
    for (int x = 0; x < deck.size(); x++) {
            deck.erase(deck.begin()+(x-1));
        }
}


void Deck::dealDeck(){
    for(int i = 0; i < deck.size(); i++){
        Card c = deck[i];
        if(i % 2 == 0){
            playerDeck.push_back(c);
        }else{
            aiDeck.push_back(c);
        }
    }
}

// found this through stackoverflow.com
void Deck::shuffle(){
    unsigned seed = unsigned(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine e(seed);
    std::shuffle(deck.begin(), deck.end(), e);
}

int Deck::drawCard(int numCards){
    for (int i = 0; i < numCards; i++) {
        std::cout << "Player has drawn the card: " << std::endl;
        playerDeck.front().print();
        std::cout << "AI has drawn the card: " << std::endl;
        aiDeck.front().print();
    }
    Card c1 = playerDeck.front();
    Card c2 = aiDeck.front();
    int compare = c1.compareValue(c2);
    return compare;
}

void Deck::playerWin(int cards){
    for(int i = 0; i <= cards; i++){
        if(aidecksize() == 1){
            playerDeck.push_back(aiDeck.at(0));
            aiDeck.clear();
            break;
        }else{
            playerDeck.push_back(playerDeck.at(0));
            playerDeck.push_back(aiDeck.at(0));
            
            playerDeck.erase(playerDeck.begin());
            aiDeck.erase(aiDeck.begin());
        }
    
    }
}

void Deck::aiWin(int cards){
    for (int i = 0; i <= cards; i++) {
        if(playerdecksize() == 1){
            aiDeck.push_back(playerDeck.at(0));
            playerDeck.clear();
            break;
        }else{
            aiDeck.push_back(playerDeck.at(0));
            aiDeck.push_back(aiDeck.at(0));
            
            playerDeck.erase(playerDeck.begin());
            aiDeck.erase(aiDeck.begin());
        }
    }
}

long Deck::playerdecksize(){
    return playerDeck.size();
}
long Deck::aidecksize(){
    return aiDeck.size();
}

void Deck::compare(int cards){
    if(cards >= playerdecksize()){
        cards = (int)playerdecksize();
    }else if(cards >= aidecksize()){
        cards = (int)aidecksize();
    }
    Card c1 = playerDeck.at(0+cards);
    Card c2 = aiDeck.at(0+cards);
    int compare = c1.compareValue(c2);
    if(compare == 0){
        cards=cards+2;
        Deck::compare(cards);
    }else if(compare == 1){
        Deck::playerWin(cards);
    }else{
        Deck::aiWin(cards);
    }
}

