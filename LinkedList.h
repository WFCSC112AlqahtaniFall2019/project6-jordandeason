//
// Created by Jordan Deason on 10/29/19.
//
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList{

public:

    //functions
    void printLinkedList();
    void append(int item);
    void InsertionSort();

    LinkedList &operator = (const LinkedList & rhs); //assignment Operator
    LinkedList(); // default constructor
    LinkedList(const LinkedList & list); //constructor
    ~LinkedList(); //destructor


private:

    Node* head = new Node;
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H