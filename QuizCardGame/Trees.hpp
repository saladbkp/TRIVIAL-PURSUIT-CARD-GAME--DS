#pragma once
#include "import.h"

class TreeNode {
public:
	int playerID;
	string playerName;
	string questions[3];
	int scores[3];
	int totalScore;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int playerID, string playerName)
		: playerID(playerID), playerName(playerName), left(nullptr), right(nullptr) {
		
	}
};

class ListNode {
public:
    TreeNode* treeNode;
    ListNode* next;

    ListNode(TreeNode* treeNode) : treeNode(treeNode), next(nullptr) {}
};

class PlayerTree {
private:
	TreeNode* root;
    TreeNode* insert(TreeNode* node, int round ,int playerID, std::string playerName, std::string questions, int scores) {
        if (node == nullptr) {
            node = new TreeNode(playerID, playerName);
            node->questions[round-1] = questions;
            node->scores[round-1] = scores;
            node->totalScore += scores;
            return node;
        }

        if (playerID < node->playerID) {
            node->left = insert(node->left, round, playerID, playerName, questions, scores);
        }
        else if (playerID > node->playerID) {
            node->right = insert(node->right, round, playerID, playerName, questions, scores);
        }
        else {
            // If the playerID already exists, we assume the data should be updated.
            node->questions[round-1] = questions;
            node->scores[round-1] = scores;
            node->totalScore += scores;
        }

        return node;
    }
    void inOrder(TreeNode* node, ListNode*& head) {
        if (node != nullptr) {
            inOrder(node->left, head);
            appendNode(head, node);
            inOrder(node->right, head);
        }
    }
    void appendNode(ListNode*& head, TreeNode* treeNode) {
        ListNode* newNode = new ListNode(treeNode);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode* current = head;
            ListNode* previous = nullptr;

            // Insert in sorted order by totalScore (descending)
            while (current != nullptr && current->treeNode->totalScore > treeNode->totalScore) {
                previous = current;
                current = current->next;
            }

            if (previous == nullptr) {
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = current;
                previous->next = newNode;
            }
        }
    }
    // binary search 
    TreeNode* searchByID(TreeNode* node, int playerID) {
        if (node == nullptr || node->playerID == playerID) {
            return node;
        }

        if (playerID < node->playerID) {
            return searchByID(node->left, playerID);
        }
        else {
            return searchByID(node->right, playerID);
        }
    }

    void displayList(ListNode* head) {
        ListNode* current = head;
        int rank = 1;
        while (current != nullptr) {
            TreeNode* node = current->treeNode;
            cout <<"Rank " << rank << " >>> Player ID: " << node->playerID << ", Name: " << node->playerName << " , Total Score: " << node->totalScore << endl;
            for (int i = 0; i < 3; ++i) {
                cout << "  Round " << i + 1 << ": " << node->questions[i] << ", Score: " << node->scores[i] << endl;
            }
            current = current->next;
            rank++;
        }
    }
    int searchPlayerRank(ListNode* head, int playerID) {
        int rank = 1;
        ListNode* current = head;

        while (current != nullptr) {
            if (current->treeNode->playerID == playerID) {
                return rank;
            }
            current = current->next;
            rank++;
        }

        return -1; // Player not found
    }

    void drawList(ListNode* head, int level = 0) {
        if (head == nullptr) return;

        ListNode* current = head;
        int count = 0;
        int pre = 0;
        int addon = 0;
        string players[16];
            while (current != nullptr) {
                if (count > 15) {
                    break;
                }
                players[count] += std::to_string(current->treeNode->playerID);
                
                // 1 2 4 8 
                cout << "Winner " << count << ": " << current->treeNode->playerID << " - " << current->treeNode->playerName << " (Score: " << current->treeNode->totalScore << ")" << endl;

                current = current->next;

                count++;
            }
            
            string bracket[] = {
                    "                        " + players[0],
                    "                        |",
                    "          --------------------------",
                    "          |                        |",
                    "          " + players[1] + "                     " + players[2],
                    "          |                        |",
                    "     -----------------------------------------",
                    "     |             |             |            |",
                    "     " + players[3] + "          " + players[4] + "          " + players[5] + "         " + players[6],
                    "     |             |             |            |",
                    "  --------------------------------------------------",
                    "  |      |      |      |      |      |      |      |",
                    "  " + players[7] + "   " + players[8] + "   " + players[9] + "   " + players[10] + "   " + players[11] + "   " + players[12] + "   " + players[13] + "   " + players[14],
            };

            for (int i = 0; i < 13; i++) {
                std::cout << bracket[i] << std::endl;
            }
            cout << endl;
    }

public:
    PlayerTree() : root(nullptr) {}

    void insert(int round, int playerID,  std::string playerName,  std::string questions,  int scores) {
        root = insert(root, round, playerID, playerName, questions, scores);
    }

    void display() {
        ListNode* head = nullptr;
        inOrder(root, head);

        cout << "Score-based leaderboard " << endl;
        cout << "--------------------------------" << endl;
        auto start = chrono::high_resolution_clock::now(); // Start time
        displayList(head);
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Sorting time: " << elapsed.count() << " seconds" << endl; // Display time
        
        // Cleanup the linked list
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
    }

    void drawtreedisplay() {
        ListNode* head = nullptr;
        inOrder(root, head);

        cout << "\nWinners' Chart" << endl;
        cout << "--------------------------------" << endl;
        auto start = chrono::high_resolution_clock::now(); // Start time
        drawList(head);
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Sorting time: " << elapsed.count() << " seconds" << endl; // Display shuffle time
    }

    // search on rank 
    void searchPlayerIDRank(int playerid) {
        ListNode* head = nullptr;
        inOrder(root, head);
        
        auto start = chrono::high_resolution_clock::now(); // Start time
        int rank = searchPlayerRank(head, playerid);
        if (rank > 0) {
            cout << "\nPlayerId: " << playerid << endl;
            cout << "Rank: " << rank << endl;
        }
        else {
            cout << "\nInvalid Player ID" << endl;
        }
        
        cout << "--------------------------------" << endl;
        
        
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Loop Searching time: " << elapsed.count() << " seconds" << endl; // Display time
    }

    // search on id
    void searchPlayerID(int playerid) {
        auto start = chrono::high_resolution_clock::now(); // Start time
        TreeNode* player = searchByID(root, playerid);
        if (player != nullptr) {
            cout << "Player ID: " << player->playerID << ", Name: " << player->playerName << ", Total Score: " << player->totalScore << endl;
            for (int i = 0; i < 3; ++i) {
                cout << "  Round " << i + 1 << ": " << player->questions[i] << ", Score: " << player->scores[i] << endl;
            }
        }
        else {
            cout << "Player not found." << endl;
        }
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Bianry Searching time: " << elapsed.count() << " seconds" << endl; // Display time
    }

};