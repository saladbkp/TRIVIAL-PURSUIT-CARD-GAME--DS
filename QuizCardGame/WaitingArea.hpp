#pragma once
#include "import.h"

using namespace std;

class WaitingArea {
	Player* players;
	WaitingArea(Player players[]) {
		this->players = players;
	}
	//void filterPeople() {
 //       Stack playerStack;

 //       // Adding players to the stack
 //       playerStack.push(Player(1, "Alice"));
 //       playerStack.push(Player(2, "Bob"));
 //       playerStack.push(Player(3, "Charlie"));

 //       // Displaying players in the stack
 //       playerStack.display();

 //       // Removing players from the stack
 //       cout << "Popping top player..." << endl;
 //       playerStack.pop();
 //       playerStack.display();

 //       // Peeking at the top player
 //       cout << "Peeking at top player..." << endl;
 //       Player topPlayer = playerStack.peek();
 //       cout << "Top Player ID: " << topPlayer.id << ", Top Player Name: " << topPlayer.name << endl;
	//}
};