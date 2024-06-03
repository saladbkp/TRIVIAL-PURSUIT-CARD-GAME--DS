#pragma once
#include "import.h"
#include "Players.hpp"

using namespace std;

class PlayerStack {
private:
    Player* pstack;
    int maxSize;
    int top;

public:
    PlayerStack(int maxSize) : maxSize(maxSize), top(-1) {
        pstack = new Player[maxSize];
    }

    void push(Player player) {
        if (top < maxSize - 1) {
            pstack[++top] = player;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop() {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else {
            cout << "Kicked player: " << pstack[top].name << endl;
            top--;
        }
    }

    void display() const {
        for (int i = top; i >= 0; --i) {
            cout << "Player ID: " << pstack[i].id << ", Name: " << pstack[i].name << endl;
        }
    }
    void filterPlayer(int maxPlayer) {
        int filternum = maxSize - maxPlayer;
        cout << "\nFiltering Player ... " << endl;
        std::cout << "3... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "2... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "1... " << std::endl;
        auto start = chrono::high_resolution_clock::now(); // Start time
        for (int i = 0; i < filternum; i++) {
            pop();
        }
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Filtering time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
    }

};