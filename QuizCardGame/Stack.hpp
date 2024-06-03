//#pragma once
//#include "import.h"
//
//using namespace std;
//
//class PlayerNode {
//public:
//    Player data;
//    PlayerNode* next;
//
//    PlayerNode(Player player) : data(player), next(nullptr) {}
//};
//
//class Stack {
//private:
//    PlayerNode* top;
//
//public:
//    Stack() : top(nullptr) {}
//
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//
//    void push(Player player) {
//        PlayerNode* newNode = new PlayerNode(player);
//        newNode->next = top;
//        top = newNode;
//    }
//
//    void pop() {
//        if (isEmpty()) {
//            cout << "Stack is empty. Cannot pop." << endl;
//            return;
//        }
//        PlayerNode* temp = top;
//        top = top->next;
//        delete temp;
//    }
//
//    Player peek() const {
//        if (isEmpty()) {
//            throw runtime_error("Stack is empty. Cannot peek.");
//        }
//        return top->data;
//    }
//
//    bool isEmpty() const {
//        return top == nullptr;
//    }
//
//    void display() const {
//        PlayerNode* current = top;
//        while (current != nullptr) {
//            cout << "Player ID: " << current->data.id << ", Player Name: " << current->data.name << endl;
//            current = current->next;
//        }
//    }
//};