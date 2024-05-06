// QuizCardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "import.h"


int main()
{
    // Init deck cards
    Deck deck(cards);

    // Init the game!
    Game game(3, players, deck);
    game.initGame();

    // Start game
    game.playGame();

    game.showResult();
    cout << "\nEnd game..." << endl;

    system("pause");
    return 1;
}
