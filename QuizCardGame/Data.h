#pragma once
#include <vector>
#include "Players.h"
#include "Cards.h"

// Create players
Player player1(1, "John");
Player player2(2, "Jane");
Player player3(3, "Ali");

// Create cards
Card card1(1, "History", "What is the capital of France?", "Paris", 1, 10);
Card card2(2, "Science", "What is the largest planet in our solar system?", "Jupiter", 2, 20);
Card card3(3, "History", "Who was the first president of the United States?", "George Washington", 1, 10);
Card card4(1, "History", "What is the capital of France?", "Paris", 1, 10);
Card card5(1, "History", "What is the capital of France?", "Paris", 1, 50);
Card card6(1, "History", "What is the capital of France?", "Paris", 1, 20);
Card card7(1, "History", "What is the capital of France?", "Paris", 1, 60);
Card card8(1, "History", "What is the capital of France?", "Paris", 1, 80);
Card card9(1, "History", "What is the capital of France?", "Paris", 1, 30);

// Create vectors to store players and cards
std::vector<Player> players = { player1, player2, player3 };
std::vector<Card> cards = { card1, card2, card3,card4,card5,card6,card7,card8,card9 };