#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


//Linked List class to manage the linked list
//Note: Very simple linked list class, does not have all the functions you would see in most linked list classes
class LinkedList {

private:
    Node* head;
public:

    LinkedList();
    ~LinkedList();
    void insert(int val);
    void printLinkedList();
    void insertion_sort();
};