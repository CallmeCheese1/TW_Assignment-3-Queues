#include<iostream>
#include "linked_list.h"
#include <vector>
#include "queue.h"

using namespace std;

// Function definition for question 2. This function determines the last appearance of an item in a vector, based on the recursive linear search function from the notes.
template <typename Item_Type>
int linear_search(vector<Item_Type>& items, const Item_Type& target, size_t pos_last = -1) {
	if (pos_last == -1) { //This defines the default case of the function. In case pos_first isn't given when we call it, just set it to the size of the items vector - 1.

		pos_last = items.size() - 1;
	}

	if (pos_last < 0)
		return -1;
	if (target == items[pos_last])
		return pos_last;
	else
		return linear_search(items, target, pos_last - 1);
}

int main() {

	cout << "Creating new queue, and pushing ten numbers..." << endl << endl;
	Queue<int> newQueue;
	for (int i = 1; i <= 10; i++) {
		newQueue.push(i);
	}

	cout << "Here's the queue!" << endl;
	newQueue.display();
	cout << endl;

	cout << "Now, to move the first element to the back." << endl;
	newQueue.move_to_rear();
	newQueue.display();
	cout << endl;

	cout << endl << "Part 2: The Recursive Linear Search Function" << endl;
	vector<int> ourVector = { 11, 23, 45, 89, 11, 29, 11, 27, 03, 58, 101, 56 };
	
	for (int i = 0; i < ourVector.size(); i++) {
		cout << ourVector[i] << " ";
	}
	cout << endl;

	cout << "The last occurrence of 11 is at index " << linear_search<int>(ourVector, 11) << endl << endl;

	cout << "Part 3 -- The New Insertion Sort Function, for Linked Lists" << endl;
	LinkedList<int> example_list;
	cout << endl << "We'll start by plugging the numbers from ourVector into a linked list." << endl;

	for (int i = 0; i < ourVector.size(); i++) {
		example_list.push_back(ourVector[i]);
	}

	example_list.print();
	cout << endl << "Time to sort!" << endl << endl;
	example_list.insertion_sort();
	cout << endl;

	return 0;
}