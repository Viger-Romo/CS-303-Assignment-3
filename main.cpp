#include "Queue.h"
#include "functions.h"
#include "LinkedList.h"

int main() {

	Queue<int> myQueue; //Creates a Queue

	for (int i = 1; i <= 10; i++) { //Pushes 10 items into the Queue
		myQueue.push(i);
	}

	//Tests out the functions of the Queue class
	cout << "The current Queue size is " << myQueue.size() << endl;
	cout << "First item in Queue is " << myQueue.front() << endl;
	myQueue.pop();
	cout << "The first item in the Queue after using the pop function is " << myQueue.front() << endl;
	cout << "The current size is " << myQueue.size() << endl;;

	myQueue.move_to_rear();
	myQueue.move_to_rear();
	
	
	cout << "\nItems in the Queue" << endl;
	while (!myQueue.empty()) { //Outputs items in the Queue while also removing them at the end
		cout << myQueue.front() << " ";
		myQueue.pop();
	}
	cout << endl;
	cout << "The current size of Queue is " << myQueue.size() << endl; //Outputs the current size of the Queue 


	vector<int> arr = { 2, 5, 3, 7, 51, 3, 8, 33 }; //Creates vector
	
	
	int target = 3; //What will be looked for in the vector
	int last_occurence_index = linear_search(arr, target); //Stores the index if found
	
	
	if (last_occurence_index != -1) { //If found in the list, outputs the last occurence

		cout << "\nThe last occurence of " << target << " is at Index: " << last_occurence_index << endl;
	}

	else { //If not found in the list, outputs it was not found in the vector

		cout << "\nThe Target " << target << " is not found in the vector." << endl;
	}


	//Repeats of previous code to show functionality
	target = 1;
	last_occurence_index = linear_search(arr, target);
	if (last_occurence_index != -1) {
		cout << "\nThe last occurence of " << target << " is at Index: " << last_occurence_index << endl;
	}
	else {
		cout << "\nThe Target " << target << " is not found in the vecotr." << endl;
	}

	//Creates a linked list to be used
	LinkedList linkedList;

	//Adds integers in the linked list
	linkedList.insert(14);
	linkedList.insert(3);
	linkedList.insert(9);
	linkedList.insert(1);
	linkedList.insert(5);
	linkedList.insert(8);

	//Displays the original list
	cout << "\nOriginal Linked list: ";
	linkedList.printLinkedList();

	//Displays the sorted list
	cout << "Sorted Linked list: ";
	linkedList.insertion_sort(); //Performs insertion_sort
	linkedList.printLinkedList(); 

	//Inserts more integers to the list to be sorted later
	linkedList.insert(1);
	linkedList.insert(24); 
	linkedList.insert(4);
	linkedList.insert(50);

	//Sorts the list again and displays the new sorted list
	cout << "Sorted Linked list: ";
	linkedList.insertion_sort();
	linkedList.printLinkedList();



	return 0;
}