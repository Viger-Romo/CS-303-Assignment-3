#pragma once
#include <iostream>

using namespace std;


template<typename Item_Type> //Template class that will allow Queue to use any data structure for the Queue 
class Queue {

private:

	struct Node { //Node struct used for Queue
		Item_Type data; //Data for the node
		Node* next; //Will be used to point to next node
		Node(Item_Type item) : data(item), next(nullptr) {} //Constructer to initialize data and next   
	};
	
	Node* head; //Pointer to front of the Queue
	Node* tail; //Pointer to rear of the Queue
	size_t num_items; //Will be used to keep track of the number of items in Queue

public:
	
	//Note: Was encoutering errors when trying to run the following code in a .cpp file, that why these functions are here in the .h file instead of .cpp
	//Seems to not recognize the template class Item_Type when set up correct in the .cpp file

	Queue() : head(nullptr), tail(nullptr), num_items(0){} //Constructor initializes an empty queue  
	
	~Queue() {     //Destructor to deallocate memory for all nodes in the Queue 
	
		while (!empty()) { //Removes all elements until the Queue is empty
			pop();
		}
	}

	//Will push an item to the rear or back of the Queue
	void push(Item_Type item) {

		Node* newNode = new Node(item); //Creates a new node with the given item
		
		if (empty()) {
			//If Queue is empty, will set both head tail to the new node
			head = tail = newNode; 
		}
		else {
			//If Queue is not empty, it will link the new node to tail and update the tail
			tail->next = newNode;
			tail = newNode;
		}
		num_items++; //Increments the number of items in the Queue
	}
	
	//Function that will remove the item in the front of the Queue
	void pop() {

		if (!empty()) {
			
			Node* temp = head;  //Save teh current head node
			head = head->next;  //Head Pointer points to next node
			delete temp;   //Deletes the saved node to deallocate memory
			num_items--;  //Decrements the number of items in Queue

			if (head == nullptr) {
				tail = nullptr; //If the Queue becomes empty it will set tail to nullptr
			}
		}
	}

	//Function that will return the data at the front of Queue
	Item_Type front() {

		if (!empty()) {
			return head->data; //If the Queue is not empty will return data of the head node
		}
		cout << "The queue is empty" << endl; //Lets the user know the Queue is empty
	}

	//Will return the size of the Queue
	int size() {
		return num_items; 
	}

	//Checks if the Queue is empty and returns true or false
	bool empty() {
		return num_items == 0; 
	}

	//Function that will move item at the front of the Queue to the rear
	void move_to_rear() {

		if (size() >= 2) { //Checks that there is at least two items in the Queue
			Item_Type frontItem = front(); //Gets and stores the item at the front of the Queue
			pop(); //Removes item at the front of the Queue
			push(frontItem); //Adds the frontItem of the Queue to the rear.
		}
	}


};