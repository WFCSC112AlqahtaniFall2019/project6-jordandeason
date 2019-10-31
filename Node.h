#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {

public:

     Node(int v = 0, Node* n = nullptr)// Constructor for Node
    {
        value = v;
        next = n;
    }


    ~Node(){//Destructor for Node; is called as many times as there are nodes
        delete next;
       // cout << "Node Destructor Called." << endl;
    }

    //Creation of friend class
    friend class LinkedList;

private:
    int value;
    Node* next;
};

#endif //NODE_H