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
        void pop(const Item_Type item); //Pops an element from the front of the line //
        Item_Type front() const; //Returns whoever is in the front of the line //
        size_t size() const; //
        bool empty() const; //
        void move_to_rear(); //
        void display();

    private:
        LinkedList<typename Item_Type> queue;
        
};

//Constructor
template<typename Item_Type>
Queue<Item_Type>::Queue() {



}

//Destructor
template<typename Item_Type>
Queue<Item_Type>::~Queue() {



}

//Check if the queue is empty
template<typename Item_Type>
bool Queue<Item_Type>::empty() const {



}

//Pushes an item to the "back" of the queue.
template<typename Item_Type>
void Queue<Item_Type>::push(const Item_Type item) {



}

//Pops an item from the "front" of the queue
template<typename Item_Type>
void Queue<Item_Type>::pop(const Item_Type item) {



}

//Returns the element in the front of the line
template<typename Item_Type>
Item_Type Queue<Item_Type>::front() const {



}

//Returns the size of the queue
template<typename Item_Type>
size_t Queue<Item_Type>::size() const {



}

//Moves whoever is at the front of the line to the back of the line, using push, front, and pop
template<typename Item_Type>
void Queue<Item_Type>::move_to_rear() {



}

//Displays all the items in the queue
template<typename Item_Type>
void Queue<Item_Type>::display() {



}

#endif