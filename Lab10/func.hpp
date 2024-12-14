#pragma once

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int value);

bool contains246(int number);

bool contains69(int number);

int getFirstDigit(int number);

int getLastDigit(int number);

bool isSorted(Node* head);

void removeNumbers(Node*& head);

void duplicateNumbers(Node*& head);

void sortList(Node*& head);

void printList(Node* head);

void freeList(Node* head);
