#pragma once
#include "import.h"

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

    Deck(Card cards[]) {
        for (int i = 0; i < cardNum;i++) {
            addCardToUnanswered(cards[i]);
        }
    }

    void drawCard(int id,int move) {

        Card card = searchCard(id,move);
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
            else if (move == 2) {
                addCardToAnswered(card);
                removeCardFromDiscarded();
            }
            else {
                cout << "illegal movement" << endl;
            }
        }
        else {
            cout << "no card found ..." << endl;
        }

    }

    int verifyAnsCard(int id, string ans,int cardFrom) {
        Card card = searchCard(id, cardFrom);
        int result = card.answer.compare(ans);
        int score = result==0?card.score:0;
        score = cardFrom == 2 ? score * 0.8 : score;
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
            cout << "Unanswered Cards: " << current->card.question << " \n Answer: " << current->card.answer << " + score " << current->card.score << endl;
            current = current->next;
        }

        current = discardedHead;
        while (current != nullptr) {
            cout << "Discarded Cards: " << current->card.question << " with answer " << current->card.answer << " and score " << current->card.score << endl;
            current = current->next;
        }
    }

    void printCurCard() {
        cout << "\nUnanswered Card :\n" << unansweredHead->card.id << " - " << unansweredHead->card.question << endl;
    }

    void printDisCard() {
        CardNode* current = discardedHead;
        int head = 0;
        while (current != nullptr) {
            if (head == 0) {
                cout << "\nDiscarded Cards :" << endl;
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
                cout << "\nAnswered Cards :" << endl;
                head++;
            }
            cout << " - " << current->card.question << endl;
            current = current->next;
        }
    }
    // fix later this fucntion too shit
    Card searchCard(int id,int from) {
        CardNode* temp = unansweredHead;
        CardNode* tempDiscard = discardedHead;
        int i = 0;
        bool found = false;
        if (from == 1 || from == 0) {
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
            }
        }
        else if (from == 2) {
            if (tempDiscard == NULL) {
                cout << "Empty List\n";
            }
            else {
                while (tempDiscard != NULL) {
                    i++;
                    if (tempDiscard->card.id == id) {
                        found = true;
                        return tempDiscard->card;
                    }
                    tempDiscard = tempDiscard->next;
                }
            }
        }
            
    }

    int searchCardFrom(int id) {
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
                    return 1;
                }
                temp = temp->next;
            }
            if (!found) {
                i = 0;
                while (tempDiscard != NULL) {
                    i++;
                    if (tempDiscard->card.id == id) {
                        found = true;
                        return 2;
                    }
                    tempDiscard = tempDiscard->next;
                }
            }
            else {
                cout << "Card ID not found..." << endl;
                return 0;
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
    void removeCardFromDiscarded() {
        if (discardedHead == nullptr) {
            return;
        }

        CardNode* temp = discardedHead;
        discardedHead = discardedHead->next;
        delete temp;
    }
    
};