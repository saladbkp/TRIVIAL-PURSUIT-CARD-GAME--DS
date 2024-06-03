#pragma once
#include <string>
using namespace std;
class Card {
public:
    int id;
    string question;
    string answer;
    int level;
    int score;

    Card(){} // default use
    Card(int id, string question, string answer, int level, int score)
        : id(id), question(question), answer(answer), level(level), score(score) {}
};