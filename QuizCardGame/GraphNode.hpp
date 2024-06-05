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
    QueueNode* next;

    QueueNode(StudentNode* node) : studentNode(node), next(nullptr) {}
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

    void enqueue(StudentNode* studentNode) {
        QueueNode* newNode = new QueueNode(studentNode);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    StudentNode* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        StudentNode* studentNode = temp->studentNode;
        delete temp;
        return studentNode;
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