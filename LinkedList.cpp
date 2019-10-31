//
// Created by Jordan Deason on 10/29/19.
//
#include "LinkedList.h"

LinkedList::~LinkedList() //destructor
{
    delete head;
}

LinkedList::LinkedList(){ //default constructor
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList & list)//copy constructor
{
    //creating new head
    head = new Node;
    while(head != nullptr)
    {
        append(head -> value);
        head = head -> next;
    }
}

LinkedList &LinkedList::operator = (const LinkedList &rhs)//copy assignment operator
{
    LinkedList temp(rhs);
    swap(head, temp.head);
    return *this;
}

void LinkedList::append(int item)//appends item to linked list
{
    if(head == nullptr)
    {
        head = new Node(item);
    }
    else
    {
        Node* current = head;
        while(current -> next != nullptr)
        {
            current = current -> next;
        }
        current -> next = new Node(item);
    }
}

void LinkedList::printLinkedList() { //print linked list
    Node * cursor = head;
    if(!cursor)
        cout << "List is empty." << endl;
    else{
        while (cursor){
            cout << cursor -> value << endl;
            cursor = cursor -> next;
        }
    }
}

void LinkedList::InsertionSort()//insertion sort function
{
    Node* tempHead = new Node();// temp head to store head
    tempHead -> next = head;
    Node* valInFront = head -> next; //looks at next node
    Node* valBehind = head; //follows valInFront
    Node* location;//saves loc where valInFront points to if wrong order
    while(valInFront != nullptr){ //if the node exists
        location = tempHead;
        while((location -> next -> value) < (valInFront -> value))//while loop runs until a number is bigger than the number in front
            location = location -> next;
        if(valBehind -> value <= valInFront -> value){//if front num and back num are in correct order, next both
            valBehind = valInFront;
            valInFront = valInFront -> next;
        }
        else{//occurs if in wrong order
            // insert lead in the spot determined by location
            valBehind -> next = valInFront -> next;
            valInFront -> next = location -> next;
            location -> next = valInFront;
            valInFront = valBehind -> next;
        }
    }
    head = tempHead -> next;//temp head becomes first value in list; delete temp head
    tempHead -> next = nullptr;
}