// QuizCardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Players.h"
#include "Cards.h"
#include "Decks.h"
#include "Games.h"


int main()
{
    // Create a player
    Player player1(1, "John");
    Player player2(2, "Jane");
    Player player3(3, "ALii");

    // Create cards
    Card card1(1, "History", "What is the capital of France?", "Paris", 1, 10);
    Card card2(2, "Science", "What is the largest planet in our solar system?", "Jupiter", 2, 20);
    Card card3(3, "History", "Who was the first president of the United States?", "George Washington", 1, 10);

    // Create vectors to store players and cards
    vector<Player> players;
    vector<Card> cards;

    // Add players to the players vector
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);

    // Add cards to the cards vector
    cards.push_back(card1);
    cards.push_back(card2);
    cards.push_back(card3);

    // Init deck cards
    Deck deck(cards);

    // start play game!
    Game game(1, players, deck);
    game.initGame();

    system("pause");
    return 1;
}
