#pragma once
#include "import.h"

class ShuffleAlgo {
private:
    int numCards;
    Card* cards4save;
    Card* cards4shuffle;
public:
    ShuffleAlgo(Card* cards,int numCards) {
        this->numCards = numCards;
        this->cards4save = new Card[numCards];
        this->cards4shuffle = new Card[numCards];
        for (int i = 0; i < numCards; ++i) {
            cards4save[i] = cards[i];
        }
        srand(time(0)); // Seed for random number generation
    }

    Card* reset() {
        return cards4save; // Return the initial array
    }
    // O(N) 
    Card* shuffle() {
        cout << "\nShuffling Cards ... " << endl;
        std::cout << "3... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "2... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "1... " << std::endl;

        cards4shuffle = cards4save; // Copy the saved array for shuffling
        // Fisher-Yates shuffle algorithm
        auto start = chrono::high_resolution_clock::now(); // Start time
        for (int i = 0; i < numCards; ++i) {
            int random = rand() % (numCards - i) + i;
            swap(cards4shuffle[i], cards4shuffle[random]);
        }
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Shuffle time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
        return cards4shuffle; // Return the shuffled array
    }
};