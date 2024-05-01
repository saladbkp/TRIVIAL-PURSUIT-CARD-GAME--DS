#pragma once

#include <string>
#include <vector>
#include "Decks.h"
#include "Players.h"

using namespace std;

class Game {
public:
    int round;
    vector<Player> players;
    Deck deck;

    Game(int round, vector<Player> players, Deck deck) : round(round), players(players), deck(deck){}

    void initGame() {
        cout << "Round: " << round << endl;
        cout << "Players: " << endl;
        for (Player player : players) {
            cout << "  - " << player.name << " with ID " << player.id << endl;
        }
        cout << "Deck: " << endl;
        for (Card card : deck.unanswered) {
            cout << "  - " << card.question << " with answer " << card.answer << " and score " << card.score << endl;
        }
    }
};