#include <iostream>
#include <vector>

using namespace std; 


//Note: Was encoutering errors when trying to run the following code in a .cpp file, that why the recurisve function is here in the .h file instead of .cpp
//Seems to not recognize the template class Item_Type even when set up correct in the .cpp file


template<typename Item_Type> //Template class to use any data for the vector provided in the function and target

//Recursive function that will find the last occurence of the target provided in a vector
int linear_search(vector<Item_Type>& arr, Item_Type& target, size_t index) {
	
	if (arr[index] == target) { //If the current element matches that target, it will return the index at where it was found
		return index; //Returns the current index
	}

	if (index == 0) { //Base Case: If index reaches 0 and has not found an occurence, it will return -1
		return -1; //Return -1 indicates that the target was not found
	}

	return linear_search(arr, target, index - 1); //Recursive call with the index decreased by 1
}

template<typename Item_Type>

//Wrapper function to start the search at the end of the vector
int linear_search(vector<Item_Type>& arr, Item_Type& target) {
	//Starts from the end
	return linear_search(arr, target, arr.size() - 1);
}

//Function declartion for inertion sort algorithm for a linked list