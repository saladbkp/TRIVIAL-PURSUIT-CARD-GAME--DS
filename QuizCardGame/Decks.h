#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Cards.h"

using namespace std;

class Deck {
public:
	vector<Card> answered;
	vector<Card> unanswered;
	vector<Card> discarded;
	Deck(vector<Card> cards) {
		for (Card card : cards) {
			unanswered.push_back(card);
		}
	}
	void drawCard(Card card,int move) {
		// move 1 = ans 
		// 0 = discard
		if (move == 1) {
			answered.push_back(card);
			unanswered.pop_back();
		}
		else if(move == 0) {
			discarded.push_back(card);
			unanswered.pop_back();
		}
		else {
			cout << "illegal movement" << endl;
		}
	}
};