//
//  main.cpp
//  CardGameWar
//
//  Created by Prabhanjan Piwalatkar on 4/12/22.
//

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "War.h"

int main(int argc, char **argv)
{
    int x;
    int cards = 1;
    
    std::cout << "Welcome to a Card Game. Press 1 to begin or press any number to exit." << std::endl;
    std::cin >> x;
    Deck deck;
    
    if(x == 1){
        deck.shuffle();
        deck.dealDeck();
        
        std::cout << "Deck has been shuffled and dealt to both player and AI.\n" << std::endl;
        
        long p = deck.playerdecksize();
        long a = deck.aidecksize();
        
        while (p != 0 && a != 0 && x == 1) {
            int compare = deck.drawCard(cards);
            if(compare == 0){
                cards = 2;
                deck.compare(cards);
                
            }else if(compare == 1){
                cards = 0;
                deck.playerWin(cards);
                
            }else{
                cards = 0;
                deck.aiWin(cards);
                
            }
            std::cout << "\nIf you want to continue playing, enter 1, otherwise enter any number." << std::endl;
            std::cin >> x;
            p = deck.playerdecksize();
            a = deck.aidecksize();
        }
        
        
    }else{
        std::cout << "Game Over." << std::endl;
    }
    
    
    
    if(x != 1){
        std::cout << "\nPlayer has forfeited."<< std::endl;
        std::cout << "Player has " << deck.playerdecksize() << " cards." << std::endl;
        std::cout << "AI has " << deck.aidecksize() << " cards." << std::endl;
        std::cout << "Game Over." << std::endl;
    }else if(deck.playerdecksize() == 0){
        std::cout << "\nAI is the WINNER!!!!" << std::endl;
        std::cout << "Game Over" << std::endl;
    }else if(deck.aidecksize() == 0){
        std::cout << "\nPlayer is the WINNER!!!!" << std::endl;
        std::cout << "Game Over" << std::endl;
    }
    
    
    
    return 0;
}
