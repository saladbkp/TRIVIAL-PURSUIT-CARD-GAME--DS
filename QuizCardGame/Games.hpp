#pragma once

#include "import.h"

using namespace std;

class Game {
public:
    int round;
    Player* players;
    Deck deck;
    GameRecord gamerecord;

    Game(int round, Player players[], Deck deck) : round(round), players(players), deck(deck), gamerecord(GetPlayerNum()* round) {}

    void initGame() {
        //////////////////// testing temp
        /*gamerecord.inserttempdata();
        gamerecord.generateLeaderboard();
        system("pause");*/

        cout << "This game has " << round << " round" << endl;
        cout << "\nPlayers: " << endl;
        for (int i = 0; i < playerNum;i++) {
            cout << "  - " << players[i].name << " with ID " << players[i].id << endl;
        }
        cout << "\nDeck: " << endl;
        deck.printDeck();
    }

    void playGame() {
        // only 1 round for now 
        int playerNum = GetPlayerNum();
        clearScreenAndWait();
       

        for (int ro = 0; ro < round; ro++) {
            cout << "\nRound : " << ro+1 << endl;
            for (int i = 0; i < playerNum; i++) {
                while (true) {
                    
                    
                    cout << "---------------------------------------------" << endl;
                    cout << "No Player : " << players[i].id << ", Name: " << players[i].name << "\n" << endl;
                    cout << "Do you want to draw a card? (y/n): ";
                    string choice;
                    cin >> choice;
                    if (choice.compare("y") == 0) {
                        deck.printCurCard();
                        deck.printDisCard();
                        deck.printAnsCard();

                        cout << "\nSelect the card that you want to answer!" << endl;
                        cout << "Enter the Question ID or 'n' to pass: ";
                        cin >> choice;
                        int cardSelected = deck.unansweredHead->card.id; // get cur card id
                         
                        if (choice.compare("n") != 0) {
                            int cardSelected = stoi(choice);                            
                            int cardSelectedFrom = deck.searchCardFrom(cardSelected);

                            if (cardSelectedFrom >0) {
                                string answer;
                                cout << "\nAns: ";
                                // solve for space cin
                                cin.ignore(256, '\n');
                                std::getline(std::cin, answer);
                                std::stringstream linestream(answer);
                                int score = deck.verifyAnsCard(cardSelected, answer, cardSelectedFrom);
                                gamerecord.addRecords(ro+1, players[i], deck.searchCard(cardSelected, cardSelectedFrom), score);
                                deck.drawCard(cardSelected, cardSelectedFrom); // 1 from unans 2 from discard
                                if (score != 0) {
                                    cout << "\nCongratulations, you've gained + " << score << endl;
                                }
                                else {
                                    cout << "\nWhoops! Try harder next time ~~" << endl;
                                }
                                break;
                            }
                            
                            else {
                                cout << "\nThe Question ID does not match ..." << endl;
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
                        cout << "\nInvalid choice..." << endl;
                    }
                    
                }
                clearScreenAndWait();
            }
        }
    }

    void showResult() {
        gamerecord.printRecords();
    }
    void leaderboard() {
        gamerecord.generateLeaderboard();
    }
    int GetPlayerNum() {
        return playerNum;
    }

    void clearScreenAndWait() {  
        // Wait for the user to press any key
        cout << "\nPress any key to continue...";
        _getch();
        // Clear the screen
        system("cls");
    }

};