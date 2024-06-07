#pragma once
#include "import.h"

#include <iostream>
#include <string>

using namespace std;

class StudentNode {
public:
    int playerID;
    string playerName;
    string* categories;
    int categoryCount;
    StudentNode* next;

    StudentNode(int id, string name) : playerID(id), playerName(name), categories(nullptr), categoryCount(0), next(nullptr) {}

    void addCategory(string category) {
        string* newCategories = new string[categoryCount + 1];
        for (int i = 0; i < categoryCount; ++i) {
            newCategories[i] = categories[i];
        }
        newCategories[categoryCount] = category;
        delete[] categories;
        categories = newCategories;
        categoryCount++;
    }
};

class QueueNode {
public:
    StudentNode* studentNode;
    int level;
    QueueNode* next;

    QueueNode(StudentNode* node,int level) : studentNode(node), level(level), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(StudentNode* studentNode,int level) {
        QueueNode* newNode = new QueueNode(studentNode,level);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    QueueNode* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        //QueueNode* dequeuedNode = temp;
        //delete temp;
        return temp;
    }
};

class CategoryNode {
public:
    string category;
    int* students;
    int studentCount;
    CategoryNode* next;

    CategoryNode(string cat) : category(cat), students(nullptr), studentCount(0), next(nullptr) {}

    void addStudent(int studentID) {
        int* newStudents = new int[studentCount + 1];
        for (int i = 0; i < studentCount; ++i) {
            newStudents[i] = students[i];
        }
        newStudents[studentCount] = studentID;
        delete[] students;
        students = newStudents;
        studentCount++;
    }
};