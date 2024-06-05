#pragma once

struct GameRecordDetail {
	int round;
	int playerID;
	std::string playerName;
	std::string cardQuestion;
	int cardLevel;
	int score;
};


class HashTable {
private:
	int size;
	struct HashEntry {
		int key;
		GameRecordDetail  value;
		HashEntry* next;
	};
	HashEntry** table;
public:
	HashTable(int size) {
		this->size = size;
		table = new HashEntry * [size];
		for (int i = 0; i < size; i++) {
			table[i] = nullptr;
		}
	}

	void put(int key, GameRecordDetail  value) {
		int index = hash(key);
		HashEntry* entry = table[index];
		while (entry != nullptr) {
			if (entry->key == key) {
				entry->value = value;
				return;
			}
			entry = entry->next;
		}
		entry = new HashEntry;
		entry->key = key;
		entry->value = value;
		entry->next = table[index];
		table[index] = entry;
	}
	
	GameRecordDetail  get(int key) {
		int index = hash(key);
		HashEntry* entry = table[index];
		while (entry != nullptr) {
			if (entry->key == key) {
				return entry->value;
			}
			entry = entry->next;
		}
		return GameRecordDetail{}; // not found
	}

	// use the most simple hash encryption!!!!! (hopefully wont occur collision)
	int hash(int key) {
		return key % size;
	}

	// deconstructor
	~HashTable() {
		for (int i = 0; i < size; i++) {
			HashEntry* entry = table[i];
			while (entry != nullptr) {
				HashEntry* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] table;
	}
};