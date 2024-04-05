#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {} //Construcotr that initailizes head pointer to nullpointer


LinkedList::~LinkedList() { //Destrucotr: Deletes all nodes
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

//Function that inserts a new node at the beginning of the list
void LinkedList::insert(int val) { 
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;

}

//Function that each element in the linked list
//Will help show orginal and then sorted list
void LinkedList::printLinkedList() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


//Function that performs an insertion sort on the linked list

void LinkedList::insertion_sort() {

	//Checks if list is empty or has only one node, meaning list is sorted already
	if (head == nullptr || head->next == nullptr) {
		cout << "The linked list is either empty or only has one node" << endl;
		return;
	}

	Node* sorted = nullptr; //Intialize a pointer to the sorted list
	Node* current = head; //Starts with the first node

	//Will iterate through each node in the original list
	while (current != nullptr) { 

		Node* nextNode = current->next; //Store the next node in the orginal list to preserve it
		

		//If the sorted iist is empty or the current node data is less than or equal to the first node, then it will insert the current node to the beginning of the sorted list
		if (sorted == nullptr || (sorted->data >= current->data)) {
			current->next = sorted;
			sorted = current;
		}

		//Finds a approriate spot to insert the current node if the current node's data is greater than the first node in the sorted list
		else {
			Node* traverseList = sorted; //Used to traverse the sorted list

			//Will traverse the sorted list until it finds a apporiate spot to insert the current node
			while (traverseList->next != nullptr && (traverseList->next->data < current->data)) {
				traverseList = traverseList->next;
			}

			//Inserts the current node in the sorted list
			current->next = traverseList->next;
			traverseList->next = current;
		}
		//Moves to the next node in the original list
		current = nextNode;
	}
	//Updates the linked list head to point to the sorted list
	head = sorted;

}