// QuizCardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "import.h"

void pauseandClearScreen() {
    ///////////////////////////////// Wait for the user to press any key
    cout << "\nPress any key to continue...";
    _getch();
    // Clear the screen
    system("cls");
}

void displayMenu() {
    int choice = 0;
    cout << " ------ Trivial Pursuit Card Game  ------" << endl;
    cout << "1. Play Game" << endl;
    cout << "0. Exit" << endl;
    cout << " ---------------------------------------- " << endl;
    cout << "Choose an option: ";
    cin >> choice;
    switch(choice){
    case 1:
        break;
    case 0:
        exit(0);
        break;
    default:
        cout << "Not a valid option ..." << endl;
        pauseandClearScreen();

        displayMenu();
    }
}



int main()
{
    displayMenu();


    Card* cards = readCardCSV("Questions.csv");
    Player* players = readPlayerCSV("Players.csv");

    //////////////////////////////// Shuffle cards
    int numCards = countLines("Questions.csv");
    ShuffleAlgo shuffleAlgo(cards, numCards);
    cards = shuffleAlgo.shuffle();


    //////////////////////////////// waiting area to filter players
    int numPlayers = countLines("Players.csv");
    PlayerStack waitingArea(numPlayers); // Stack with a max size of 50
    for (int i = 0; i < numPlayers; ++i) {
        waitingArea.push(players[i]);
    }
    waitingArea.filterPlayer(playerNum);

    cout << "\nCurrent waiting area players:" << endl;
    waitingArea.display();

    ///////////////////////////////// Wait for the user to press any key
    pauseandClearScreen();


    // Init deck cards
    Deck deck(cards);
    
    // Init the game!
    Game game(3, players, deck);
    game.initGame();

    // Start game
    game.playGame();

    ////////////////////////////////// end game
    game.showResult();


    ////////////////////////////////// stat


    delete[] cards;
    cout << "\nEnd game..." << endl;

    system("pause");
    return 1;
}

