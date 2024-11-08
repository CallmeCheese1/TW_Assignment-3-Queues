#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include "linked_list.h"

using namespace std;


// Queue class definition
template<typename Item_Type>
class Queue {
    public:
        Queue(); //
        ~Queue(); //


        void push(const Item_Type item); //Pushes someone to the back of the line // 
        void pop(); //Pops the element from the front of the line //
        Item_Type front() const; //Returns whoever is in the front of the line //
        size_t size() const; //
        bool empty() const; //
        void move_to_rear(); //
        void display();

    private:
        LinkedList<typename Item_Type> queue; //We're building a queue fundamentally based on a linked list, so the heart of the data will be stored in a linked list class identical to the one created for our last project. For more info, view linked_list.h
        
};

//Constructor
template<typename Item_Type>
Queue<Item_Type>::Queue() {

    //Both the constructor and the destructor below will be left purposefully blank, because the linked list class already has a built in destructor that'll handle clearing out all the elements in the list. We'll leave this here for the sake of safety.

}

//Destructor
template<typename Item_Type>
Queue<Item_Type>::~Queue() {



}

//Check if the queue is empty
template<typename Item_Type>
bool Queue<Item_Type>::empty() const {

    return (size() == 0);

}

//Pushes an item to the "back" of the queue.
template<typename Item_Type>
void Queue<Item_Type>::push(const Item_Type item) {

    queue.push_back(item); 

}

//Pops the item from the "front" of the queue
template<typename Item_Type>
void Queue<Item_Type>::pop() {

    queue.pop_front();

}

//Returns the element in the front of the line
template<typename Item_Type>
Item_Type Queue<Item_Type>::front() const {

    return queue.front();

}

//Returns the size of the queue
template<typename Item_Type>
size_t Queue<Item_Type>::size() const {

    return queue.num_items;

}

//Moves whoever is at the front of the line to the back of the line, using push, front, and pop
template<typename Item_Type>
void Queue<Item_Type>::move_to_rear() {

    Item_Type item = front();
    push(item);
    pop();

}

//Displays all the items in the queue
template<typename Item_Type>
void Queue<Item_Type>::display() {

    queue.print();
    cout << endl;

}

#endif