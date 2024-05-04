#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Cards.h"

using namespace std;

struct CardNode {
    Card card;
    CardNode* next;

    CardNode() : card(), next(nullptr) {} // Default constructor
};

class Deck {
public:
    CardNode* answeredHead = nullptr;
    CardNode* unansweredHead = nullptr;
    CardNode* discardedHead = nullptr;

    Deck(vector<Card> cards) {
        for (Card card : cards) {
            addCardToUnanswered(card);
        }
    }

    void drawCard(int id,int move) {

        Card card = searchCard(id);
        if (sizeof(card) != 0) {
            // move 1 = ans 
            // 0 = discard
            if (move == 1) {
                addCardToAnswered(card);
                removeCardFromUnanswered();
            }
            else if (move == 0) {
                addCardToDiscarded(card);
                removeCardFromUnanswered();
            }
            else {
                cout << "illegal movement" << endl;
            }
        }
        else {
            cout << "no card found ..." << endl;
        }

    }

    int verifyAnsCard(int id, string ans) {
        Card card = searchCard(id);
        int result = card.answer.compare(ans);
        int score = result==0?card.score:0;
        return score;
    }

    void printDeck() {
        CardNode* current = answeredHead;
        while (current != nullptr) {
            cout << "Answered Cards: " << current->card.question << " with answer " << current->card.answer << " and score " << current->card.score << endl;
            current = current->next;
        }

        current = unansweredHead;
        while (current != nullptr) {
            cout << "Unanswered Cards: " << current->card.question << " with answer " << current->card.answer << " and score " << current->card.score << endl;
            current = current->next;
        }

        current = discardedHead;
        while (current != nullptr) {
            cout << "Discarded Cards: " << current->card.question << " with answer " << current->card.answer << " and score " << current->card.score << endl;
            current = current->next;
        }
    }

    void printCurCard() {
        cout << "Unanswered Card :\n" << unansweredHead->card.id << " - " << unansweredHead->card.question << endl;
    }

    void printDisCard() {
        CardNode* current = discardedHead;
        int head = 0;
        while (current != nullptr) {
            if (head == 0) {
                cout << "Discarded Cards :" << endl;
                head++;
            }
            cout << current->card.id << " - " << current->card.question << endl;
            current = current->next;
        }
    }
    void printAnsCard() {
        CardNode* current = answeredHead;
        int head = 0;
        while (current != nullptr) {
            if (head == 0) {
                cout << "Answered Cards :" << endl;
                head++;
            }
            cout << " - " << current->card.question << endl;
            current = current->next;
        }
    }
    // fix later this fucntion too shit
    Card searchCard(int id) {
        CardNode* temp = unansweredHead;
        CardNode* tempDiscard = discardedHead;
        int i = 0;
        bool found = false;

        if (temp == NULL) {
            cout << "Empty List\n";
        }
        else {
            while (temp != NULL) {
                i++;
                if (temp->card.id == id) {
                    found = true;
                    return temp->card;
                }
                temp = temp->next;
            }
            if (!found) {
                i = 0;
                while (tempDiscard != NULL) {
                    i++;
                    if (tempDiscard->card.id == id) {
                        found = true;
                        return tempDiscard->card;
                    }
                    tempDiscard = tempDiscard->next;
                }
            }
            else {
                cout << "Card ID not found..." << endl;
            }
        }
    }

private:
    void addCardToUnanswered(Card card) {
        CardNode* newNode = new CardNode;
        newNode->card = card;
        newNode->next = unansweredHead;
        unansweredHead = newNode;
    }

    void addCardToAnswered(Card card) {
        CardNode* newNode = new CardNode;
        newNode->card = card;
        newNode->next = answeredHead;
        answeredHead = newNode;
    }

    void addCardToDiscarded(Card card) {
        CardNode* newNode = new CardNode;
        newNode->card = card;
        newNode->next = discardedHead;
        discardedHead = newNode;
    }

    void removeCardFromUnanswered() {
        if (unansweredHead == nullptr) {
            return;
        }

        CardNode* temp = unansweredHead;
        unansweredHead = unansweredHead->next;
        delete temp;
    }
    
};