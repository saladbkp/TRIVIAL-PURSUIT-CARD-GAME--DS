#pragma once
#include "import.h"
#include "Trees.hpp"
#include "Graph.hpp"
#include "ReadCSV.hpp"

class GameRecord {
private:
	HashTable records;
	int nextGameID;
	PlayerTree tree;
public:
	GameRecord(int size) : records(size), nextGameID(1) {};

	void addRecords(int round, Player player, Card card, int score) {
		GameRecordDetail gameDetail;
		gameDetail.round = round;
		gameDetail.playerID = player.id;
		gameDetail.playerName = player.name;
		gameDetail.cardQuestion = card.question;
		gameDetail.cardLevel = card.level;
		gameDetail.score = score;
		records.put(nextGameID, gameDetail);
		nextGameID++;
	}
	void printRecords() {
		cout << "---------------------------------------------" << endl;
		cout << "Game Record:\n" << endl;
		auto start = chrono::high_resolution_clock::now(); // Start time
		for (int i = 0; i < nextGameID; i++) {
			GameRecordDetail record = records.get(i);
			cout << "Game ID: " << i << ", Game Round: " << record.round << endl;
			cout << "Player ID: " << record.playerID << ", Player Name: " << record.playerName << endl;
			cout << "Card Question: " << record.cardQuestion << ", Card Level: " << record.cardLevel << endl;
			cout << "Score: " << record.score << endl;
			cout << endl;
		}
		auto end = chrono::high_resolution_clock::now(); // End time
		chrono::duration<double> elapsed = end - start;
		cout << "Collecting time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
	}
	void searchRecords(int gameid) {
		cout << "---------------------------------------------" << endl;
		cout << "Game Record:\n" << endl;
		auto start = chrono::high_resolution_clock::now(); // Start time
		GameRecordDetail record = records.get(gameid);
		if (sizeof(record)>0) {
			cout << "Game ID: " << gameid << ", Game Round: " << record.round << endl;
			cout << "Player ID: " << record.playerID << ", Player Name: " << record.playerName << endl;
			cout << "Card Question: " << record.cardQuestion << ", Card Level: " << record.cardLevel << endl;
			cout << "Score: " << record.score << endl;
		}		
		else {
			cout << "Invalid Game ID" << endl;
		}
		auto end = chrono::high_resolution_clock::now(); // End time
		chrono::duration<double> elapsed = end - start;
		cout << "Searching time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
	}
	void inserttempdata() {
		tree.insert(1, 1, "Player1", "q1", 10);
		tree.insert(1, 2, "Player2", "q1", 20);
		tree.insert(1, 3, "Player3", "q1", 10);
		tree.insert(1, 4, "Player4", "q1", 10);
		tree.insert(2, 1, "Player1", "q1", 15);
		tree.insert(2, 2, "Player2", "q1", 10);
		tree.insert(2, 3, "Player3", "q1", 5);
		tree.insert(1, 4, "Player4", "q1", 10);
		tree.insert(3, 1, "Player1", "q1", 10);
		tree.insert(3, 2, "Player2", "q1", 7);
		tree.insert(3, 3, "Player3", "q1", 10);
		tree.insert(3, 4, "Player4", "q1", 3);
	}
	
	void generateLeaderboard() {
		/////////////////////////////// display
		system("cls");
		int choice;
		int playerID = -1;
		cout << "--------------------------------" << endl;
		cout << "1. [Tree] Score-based leaderboard" << endl;
		cout << "2. [LinkedList] Winners' Chart" << endl;
		cout << "3. [HashMap] Game records" << endl;
		cout << "4. [Graph & Queue] Common categories among students" << endl;
		cout << "0. Exit" << endl;
		cout << "--------------------------------" << endl;
		cout << "Choose an option: ";
		cin >> choice;
		if (choice == 1) {
			system("cls");
			while (true) {
				tree.display();
				cout << "--------------------------------" << endl;
				cout << "Search ID (0 to exit): ";
				cin >> playerID;
				if (playerID == 0) break;
				tree.searchPlayerID(playerID);
				pauseandClearScreen();
			}
			generateLeaderboard();
		}
		else if (choice == 2) {
			system("cls");
			while (true) {
				tree.drawdisplay();
				cout << "--------------------------------" << endl;
				cout << "Search ID (0 to exit): ";
				cin >> playerID;
				if (playerID == 0) break;
				tree.searchPlayerIDRank(playerID);
				pauseandClearScreen();
			}
			generateLeaderboard();
		}
		else if (choice == 3) {
			system("cls");
			while (true) {
				printRecords();
				cout << "--------------------------------" << endl;
				cout << "Search ID (0 to exit): ";
				cin >> playerID;
				if (playerID == 0) break;
				tree.searchPlayerIDRank(playerID);
				pauseandClearScreen();
			}
			generateLeaderboard();
		}
		else if (choice == 4) {
			system("cls");
			while (true) {
				Graph graph;
				parseDataset("Q3.csv", graph);
				graph.displayGraph();
				cout << "--------------------------------" << endl;
				cout << "Search ID (0 to exit): ";
				cin >> playerID;
				if (playerID == 0) break;
				graph.bfsCommonCategories(playerID);
				pauseandClearScreen();
			}
			generateLeaderboard();
			
		}
		else if (choice == 0) {
			// pass
			return;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}



	}
	
	
	void pauseandClearScreen() {
		///////////////////////////////// Wait for the user to press any key
		cout << "\nPress any key to continue...";
		_getch();
		// Clear the screen
		system("cls");
	}
};