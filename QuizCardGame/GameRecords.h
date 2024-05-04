#pragma once
#include "HashTable.h"
#include "Players.h"
#include "Cards.h"
#include <iostream>
class GameRecord {
private:
	HashTable records;
	int nextGameID;
public:
	GameRecord(int size): records (size), nextGameID(1) {};

	void addRecords(int round, Player player, Card card,int score) {
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
	void printRecords(){
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < nextGameID;i++) {
			GameRecordDetail record = records.get(i);
			cout << "Game ID: " << nextGameID << ", Game Round: " << record.round << endl;
			cout << "Player ID: " << record.playerID << ", Player Name: " << record.playerName << endl;
			cout << "Card Question: " << record.cardQuestion << ", Card Level: " << record.cardLevel << endl;
			cout << "Score: " << record.score << endl;
			cout << endl;
		}
	}
};