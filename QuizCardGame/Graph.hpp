#pragma once
#include "import.h"
#include "GraphNode.hpp"
class Graph {
private:
    StudentNode* studentHead;
    CategoryNode* categoryHead;

public:
    Graph() : studentHead(nullptr), categoryHead(nullptr) {}

    void addStudent(int playerID, string playerName) {
        StudentNode* newNode = new StudentNode(playerID, playerName);
        newNode->next = studentHead;
        studentHead = newNode;
    }

    void addCategory(string category) {
        CategoryNode* newNode = new CategoryNode(category);
        newNode->next = categoryHead;
        categoryHead = newNode;
    }

    StudentNode* findStudent(int playerID) {
        StudentNode* current = studentHead;
        while (current != nullptr) {
            if (current->playerID == playerID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    CategoryNode* findCategory(string category) {
        CategoryNode* current = categoryHead;
        while (current != nullptr) {
            if (current->category == category) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addScore(int playerID, string category,int score) {
        if (score > 0) {
            StudentNode* student = findStudent(playerID);
            if (student != nullptr) {
                student->addCategory(category);
                CategoryNode* categoryNode = findCategory(category);
                if (categoryNode != nullptr) {
                    categoryNode->addStudent(playerID);
                }
            }
        }
        
    }

    void displayGraph() {
        StudentNode* current = studentHead;
        cout << "Common Categories " << endl;
        cout << "--------------------------------" << endl;
        auto start = chrono::high_resolution_clock::now(); // Start time
        while (current != nullptr) {
            cout << "Player " << current->playerID << " (" << current->playerName << ") can score in categories: ";
            for (int i = 0; i < current->categoryCount; ++i) {
                cout << current->categories[i] << " ";
            }
            cout << endl;
            current = current->next;
        }
        auto end = chrono::high_resolution_clock::now(); // End time
        chrono::duration<double> elapsed = end - start;
        cout << "Sorting time: " << elapsed.count() << " seconds" << endl; // Display time
    }

    void bfsCommonCategories(int playerID) {
        StudentNode* student = findStudent(playerID);
        if (student == nullptr) {
            cout << "Student not found." << endl;
            return;
        }

        Queue q;
        q.enqueue(student,0);

        bool visited[100] = { false }; // Assuming max 100 students for simplicity
        visited[playerID-1000] = true;

        cout << "Students with common categories:" << endl;

        while (!q.isEmpty()) {
            QueueNode* currentNode = q.dequeue();
            StudentNode* current = currentNode->studentNode;
            int currentLevel = currentNode->level;
            delete currentNode;
            for (int i = 0; i < current->categoryCount; ++i) {
                string category = current->categories[i];
                CategoryNode* categoryNode = findCategory(category);

                //cout << "Player have: " << categoryNode->category << endl;
                if (categoryNode != nullptr) {
                    for (int j = 0; j < categoryNode->studentCount; ++j) {
                        int otherPlayerID = categoryNode->students[j];
                        if (!visited[otherPlayerID-1000]) {
                            visited[otherPlayerID-1000] = true;
                            StudentNode* otherStudent = findStudent(otherPlayerID);
                            if (otherStudent != nullptr) {
                                if (j == 0) {
                                    cout << "Common Category : " << categoryNode->category << " at Level : " << currentLevel + 1 << endl;
                                }

                                cout << "Player " << otherStudent->playerID << " (" << otherStudent->playerName << ")" << endl;                                
                                q.enqueue(otherStudent, currentLevel + 1);

                            }
                        }
                    }
                }
            }
        }
    }
};