#include <cassert>
#include <iostream>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include <ctime>
#include <vector>

using namespace std;

int main() {
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    LinkedList obj;//object of LinkedList class
    int value;//place to store rand value
    for (int i = 0; i < length; i++) {//make linked list of random, unsorted values
        value = rand() % 100;
        obj.append(value);
    }
    vector<int> v;//generate vector of random integers of random, unsorted values
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        int val = v[i];
        obj.append(val);
    }

    cout << "Unsorted list:" << endl;
    obj.printLinkedList();//calls print

    cout << "\nSorted: " << endl;

    cout << "Linked list - " << endl;
    clock_t start_LinkedInsertionSort = clock();// starts clock timer
    obj.InsertionSort();//calls insertion sort linked list
    clock_t end_LinkedInsertionSort = clock();// ends clock
    obj.printLinkedList();//calls print

    cout << endl << "Vector - " << endl;
    clock_t start_insertionSortVector = clock();// starts clock timer
    insertionSort(v, v.size());//calls binary insertion sort vector
    clock_t end_insertionSortVector = clock();// ends clock
    obj.printLinkedList();//calls print

    //printing elapsed times
    double elapsed_insertionSortVector = double(end_insertionSortVector - start_insertionSortVector) / CLOCKS_PER_SEC;
    double elapsed_LinkedInsertionSort = double(end_LinkedInsertionSort - start_LinkedInsertionSort) / CLOCKS_PER_SEC;

    cout << "Elapsed Time for Vector: " << elapsed_insertionSortVector << endl;
    cout << "Elapsed Time for Linked List: " << elapsed_LinkedInsertionSort << endl << endl;
}