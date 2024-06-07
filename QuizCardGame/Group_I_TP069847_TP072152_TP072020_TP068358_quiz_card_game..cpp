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

void playgame() {
    Card* cards = readCardCSV("Questions.csv");
    cout << "\n[Array] Inserting Player to Array ... " << endl;
    std::cout << "3... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "2... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1... " << std::endl;
    auto start = chrono::high_resolution_clock::now(); // Start time
    Player* players = readPlayerCSV("Players.csv");
    auto end = chrono::high_resolution_clock::now(); // End time
    chrono::duration<double> elapsed = end - start;
    cout << "Inserting time: " << elapsed.count() << " seconds" << endl; // Display shuffle time

    //////////////////////////////// Shuffle cards
    int numCards = countLines("Questions.csv");
    ShuffleAlgo shuffleAlgo(cards, numCards);
    cards = shuffleAlgo.shuffle();


    //////////////////////////////// waiting area to filter players
    int numPlayers = countLines("Players.csv");
    PlayerStack waitingArea(numPlayers); // Stack with a max size of 50
    cout << "\n[Stack] Inserting Player to Stack ... " << endl;
    std::cout << "3... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "2... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1... " << std::endl;
    start = chrono::high_resolution_clock::now(); // Start time
    for (int i = 0; i < numPlayers; ++i) {
        waitingArea.push(players[i]);
    }
    end = chrono::high_resolution_clock::now(); // End time
    elapsed = end - start;
    cout << "Inserting time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
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

    pauseandClearScreen();
    ////////////////////////////////// stat
    game.leaderboard();

    delete[] cards;
}

void demogame() {
    GameRecord gamerecord(210);
    parseDataset("demo.csv",gamerecord);
    pauseandClearScreen();
    gamerecord.generateLeaderboard();
}

void insertionSort(Player* players,int count) {
    for (int i = 1; i < count; i++) {
        Player key = players[i];
        int j = i - 1;
        // compare names 
        while (j >= 0 && players[j].name > key.name) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j + 1] = key;
    }
}

void sortPlayer() {
    Player* players = readPlayerCSV("Players.csv");
    // Perform insertion sort
    auto start = chrono::high_resolution_clock::now(); // Start time
    insertionSort(players, 70 - 1); // minus one for the header line
    auto end = chrono::high_resolution_clock::now(); // End time
    chrono::duration<double> elapsed = end - start;
    cout << "\nSorting time: " << elapsed.count() << " seconds" << endl;
    // Print sorted players
    cout << "[Insertion Sort] Players List:" << endl;
    for (int i = 0; i < 70 - 1; i++) {
        cout << players[i].id << ", " << players[i].name << endl;
    }
    pauseandClearScreen();
    // Free allocated memory
    delete[] players;
}

void displayMenu() {
    system("cls");
    int choice = 0;
    cout << " ------ Trivial Pursuit Card Game  ------" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show Demo" << endl;
    cout << "3. Sort Player" << endl;
    cout << "0. Exit" << endl;
    cout << " ---------------------------------------- " << endl;
    cout << "Choose an option: ";
    cin >> choice;
    switch(choice){
    case 1:
        playgame();
        displayMenu();
        break;
    case 2:
        demogame();
        displayMenu();
        break;
    case 3:
        sortPlayer();
        displayMenu();
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

    cout << "\nEnd game..." << endl;

    system("pause");
    return 1;
}

