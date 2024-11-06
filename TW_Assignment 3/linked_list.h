#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
using namespace std;

// Node struct definition
template<typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    // Constructor for Node
    Node(const Item_Type& data_item, Node* next_ptr = nullptr)
        : data(data_item), next(next_ptr) {}
};

// LinkedList class definition
template<typename Item_Type>
class LinkedList {
public:
    LinkedList();                         // Constructor
    ~LinkedList();                        // Destructor

    // Member functions for LinkedList operations
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    void print();

private:
    Node<Item_Type>* head;    // Pointer to the head of the list
    Node<Item_Type>* tail;    // Pointer to the tail of the list
    int num_items;            // Number of items in the list
};

// Constructor
template<typename Item_Type>
LinkedList<Item_Type>::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template<typename Item_Type>
LinkedList<Item_Type>::~LinkedList() {
    while (!empty()) {
        pop_front();  // Remove elements one by one to free memory
    }
}

// Check if the list is empty
template<typename Item_Type>
bool LinkedList<Item_Type>::empty() const {
    return head == nullptr && tail == nullptr && num_items == 0;
}

// Push a node to the front of the list
template<typename Item_Type>
void LinkedList<Item_Type>::push_front(const Item_Type& item) {

    Node<Item_Type>* newNode = new Node<Item_Type>(item);

    //First, we gotta check in case the list is empty. If so, both the head and the tail should be the same node.
    if (empty()) {
        head = newNode;
        tail = newNode;
    }
    else { //else, set this new node's next spot to the head, and then set head to this new node
        newNode->next = head;
        head = newNode;
    }

    ++num_items; //increase num items, fully integrating this node into the family.
}

// Push a node to the back of the list using tail pointer
template<typename Item_Type>
void LinkedList<Item_Type>::push_back(const Item_Type& item) {

    Node<Item_Type>* newNode = new Node<Item_Type>(item);

    //Again, we gotta check for in case the list is completely empty.
    if (empty()) {
        head = newNode;
        tail = newNode;
    }
    else { //else, set the tail's next spot this new node, and then set tail to be this new node
        tail->next = newNode;
        tail = newNode;
    }

    ++num_items; //increase num items, fully integrating this node into the family.
}

// Remove the first node in the list
template<typename Item_Type>
void LinkedList<Item_Type>::pop_front() {
    //First, check for if our list is totally empty. If so, print out a messgae and return.
    if (empty())
    {
        throw out_of_range("(LinkedList) pop_front() was called, but the list is already empty.");
        return;
    }
    //Otherwise, mark the first node with a temp node variable.
    Node<Item_Type>* temp = head;
    //Set head to the first node's next pointer
    head = head->next;
    //Delete the temp node
    delete temp;
    //Decrement numitems
    --num_items;

    //Check for if head's next is actually null. This means our list is empty, so tail needs to be null, too.
    if (head == nullptr) { tail = nullptr; }
}

template <typename Item_Type>
void LinkedList<Item_Type>::pop_back() {
    // FIrst, we gotta check if the list is empty
    if (empty()) {
        std::cout << "The list is empty, cannot pop back." << std::endl;
        return;
    }

    // If there's only one node in the list
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        num_items--;
        return;
    }

    // If there's more than one node, find the second-to-last node
    Node<Item_Type>* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    // Now that current is the second to last node, we've gotta delete the actual last node.
    delete tail;
    tail = current;  // Set the new last node to be the actual last node, and set its next to nullptr
    tail->next = nullptr;
    num_items--;  // Decrease the number of items in the list
}

// Return the data of the first node in the list
template<typename Item_Type>
Item_Type LinkedList<Item_Type>::front() const {
    //Should be simple. Return the data of the head node, if the list isn't totally empty.

    if (empty()) {
        throw out_of_range("The list is empty.");
    }

    return head->data;
}

// Return the data of the last node in the list
template<typename Item_Type>
Item_Type LinkedList<Item_Type>::back() const {
    //Should be equally simple. Return the data of the tail node.

    if (empty()) {
        throw out_of_range("The list is empty.");
    }

    return tail->data;
}

//nsert item at position index (starting at 0).Insert at the end if index is beyond the end of the lis
// Insert a new item at the given index. If the given index is beyond the end of the list, it should just insert it at the end with push_back, instead.
template<typename Item_Type>
void LinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    //First, check if the linked list is empty.
    if (empty()) {
        throw out_of_range("The list is empty.");
    }
    //If not, then check that our index is less than num items, and greater than 0.
    if (index < 0) {
        cout << "(insert) The index is negative." << endl;
    }

    if (index >= num_items) {
        push_back(item);
    }

    Node<Item_Type>* current = head;

    //If both of those checks have been passed, iterate through the list index -1 number of times.
    for (int i = 0; i < index - 1; i++)
    {
        //cout << "Iterating through linked list for insert function -- currently on " << current->data << ", at index " << i << endl;
        current = current->next;
    }

    //cout << "Reached element " << current->data << ", right before our index " << index << endl;

    //When we're one element before where we want to insert our new node, create a new node with the given info and set its next to my next.
    Node<Item_Type>* newNode = new Node<Item_Type>(item, current->next);

    //Then, set my next to this new node.
    current->next = newNode;

    //Lastly, increment num items.
    num_items++;
}

// Remove a node at the given index
template<typename Item_Type>
bool LinkedList<Item_Type>::remove(size_t index) {
    // Perform the same checks as the last function. Check if the linked list is empty. 
    //Check if our index is less than num items.

    //First, check if the linked list is empty.
    if (empty()) {
        throw out_of_range("The list is empty.");
    }
    //If not, then check that our index is less than num items, and greater than 0.
    if (index >= num_items || index < 0) {
        cout << "(remove) The index is out of range, or negative." << endl;
        return false;
    }

    Node<Item_Type>* current = head;
    Node<Item_Type>* temp = nullptr;

    //If both of those checks have been passed, iterate through the list index-1 number of times. 
    //Mark my next with a temp variable.

    for (int i = 0; i < index - 1; i++)
    {
        //cout << "Iterating through linked list for remove function -- currently on " << current->data << ", at index " << index << endl;
        current = current->next;
    }

    //cout << "Reached element " << current->data << ", right before our index " << index << endl;

    //Set my next to my next's next -- the temp variable's next.
    temp = current->next;
    current->next = temp->next;

    //Set the temp variable's next to be null.
    temp->next = nullptr;
    //Delete the temp variable.
    delete temp;

    //Decrement num items.
    --num_items;
    return true;
}

// Find the index of a specific item
template<typename Item_Type>
size_t LinkedList<Item_Type>::find(const Item_Type& item) const {
    //First, check if the linked list is empty.
    if (empty()) {
        throw out_of_range("The list is empty.");
    }

    Node<Item_Type>* current = head;

    //If it's not empty, iterate through the list as many times as num items.
    for (int i = 0; i < num_items; i++)
    {
        //cout << "Iterating through linked list for finding function -- currently on " << current->data << ", at index " << i << endl;
        if (current->data == item) {
            return i;
        }

        current = current->next;
    }

    //Check if this node matches our data. If not, set the current node to my next. If it does, return the value of our index.

    return num_items;
}

template<typename Item_Type>
void LinkedList<Item_Type>::print() {
    Node<Item_Type>* current = head;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

#endif // LINKED_LIST_H
