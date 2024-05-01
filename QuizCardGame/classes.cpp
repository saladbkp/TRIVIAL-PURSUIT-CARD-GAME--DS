#include <iostream>
#include <string>

using namespace std;

class Player {
public:
	int id;
	string name;
	Player(int id, string name) : id(id),name(name){}
};

class Card {
public:
    int id;
    string category;
    string question;
    string answer;
    int level;
    int score;

    Card(int id, string category, string question, string answer, int level, int score)
        : id(id), category(category), question(question), answer(answer), level(level), score(score) {}
};

