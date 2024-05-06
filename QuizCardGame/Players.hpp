#pragma once

#include <string>

using namespace std;

class Player {
public:
	int id;
	string name;
	Player(int id, string name) : id(id), name(name) {}
};