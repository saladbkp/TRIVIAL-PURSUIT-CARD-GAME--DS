#pragma once

#include <string>
#include <vector>
#include "Decks.h"
#include "Players.h"
#include "GameRecords.h"

using namespace std;

class Game {
public:
    int round;
    vector<Player> players;
    Deck deck;
    GameRecord gamerecord;

    Game(int round, vector<Player> players, Deck deck) : round(round), players(players), deck(deck), gamerecord(GetPlayerNum()*round){}

    void initGame() {
        cout << "This game has " << round << " round" << endl;
        cout << "Players: " << endl;
        for (Player player : players) {
            cout << "  - " << player.name << " with ID " << player.id << endl;
        }
        cout << "Deck: " << endl;
        deck.printDeck();
    }

    void playGame() {
        // only 1 round for now 
        int playerNum = GetPlayerNum();
        for (int ro = 0; ro < round; ro++) {
            cout << "\nRound : " << ro << endl;
            for (int i = 0; i < playerNum; i++) {
                while (true) {
                    
                    
                    cout << "---------------------------------------------" << endl;
                    cout << "No Player : " << i << endl;
                    cout << "Do u want to draw a card? (Y/N): ";
                    string choice;
                    cin >> choice;
                    if (choice.compare("y") == 0) {
                        deck.printCurCard();
                        deck.printDisCard();
                        deck.printAnsCard();

                        cout << "Select the card u want to answer (ID/n for pass) : ";
                        cin >> choice;
                        int cardSelected = deck.unansweredHead->card.id; // get cur card id
                        if (choice.compare("n") != 0) {
                            if (cardSelected == stoi(choice)) {
                                cout << "Ans: ";
                                cin >> choice;
                                int score = deck.verifyAnsCard(cardSelected, choice);
                                gamerecord.addRecords(ro, players[i], deck.searchCard(cardSelected), score);
                                deck.drawCard(cardSelected, 1);
                                if (score != 0) {
                                    cout << "Congratulations + " << score << endl;
                                }
                                else {
                                    cout << "Opps ..." << endl;
                                }
                                break;
                            }
                            else {
                                cout << "The id not match ..." << endl;
                            }
                        }
                        else {
                            deck.drawCard(cardSelected, 0);
                            break;
                        }
                    }
                    else if (choice.compare("n") == 0) {
                        break;
                    }
                    else {
                        cout << "Invalid choice..." << endl;
                    }
                }
            }
        }
    }

    void showResult() {
        gamerecord.printRecords();
    }

    int GetPlayerNum() {
        return players.size();
    }
};