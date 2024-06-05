#pragma once
#include "import.h"

int countLines(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int lines = 0;
    string line;
    while (getline(file, line)) {
        lines++;
    }
    file.close();
    return lines;
}

Card* readCardCSV(const std::string& filename) {
    int numCards = countLines(filename);
    Card* cards = new Card[numCards];

    std::ifstream file(filename);
    std::string line;
    int index = 0;

    try {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string idStr, category, question, answer, difficultyStr, pointsStr;

            std::getline(ss, idStr, ',');
            std::getline(ss, question, ',');
            std::getline(ss, answer, ',');
            std::getline(ss, category, ',');
            std::getline(ss, difficultyStr, ',');

            //int id = stoi(idStr);
            int difficulty = stoi(difficultyStr);
            int points = difficulty * 10;

            cards[index++] = Card(index+1, question, answer, category, difficulty, points);
        }

        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred while reading the file: " << e.what() << std::endl;
        std::cerr << "Line number: " << index + 1 << std::endl;
        delete[] cards;
        throw;
    }

    return cards;
}

Player* readPlayerCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int numPlayers = countLines(filename);
    Player* players = new Player[numPlayers];

    string line;
    int index = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name;

        getline(ss, idStr, ',');
        getline(ss, name, ',');

        players[index++] = Player(index+1000, name);
    }

    file.close();
    return players;
}

// tetsing
void parseDataset(const string& filename, Graph& graph) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string round, playerID, playerName, category, question, score;

        getline(ss, round, ',');
        getline(ss, playerID, ',');
        getline(ss, playerName, ',');
        getline(ss, category, ',');
        getline(ss, question, ',');
        getline(ss, score, ',');

        int id = stoi(playerID);

        if (graph.findStudent(id) == nullptr) {
            graph.addStudent(id, playerName);
        }
        if (graph.findCategory(category) == nullptr) {
            graph.addCategory(category);
        }
        graph.addScore(id, category);
    }

    file.close();
}