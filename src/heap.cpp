#include "../include/heap.h"
#include <iostream>
#include <cmath>

//constructor
MinHeap::MinHeap(int capacity){
    this->size = 0; // initially size is set as 0
    this->capacity = capacity;
    array = new int[capacity]; // array of max capacity
}

// function to swap
void MinHeap::swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

//checks if the heap is empty or not.
bool MinHeap::isEmpty(){
    return size == 0;
}

//checks if the heap is full or not.
bool MinHeap::isFull(){
    return size == capacity;
}

// returns the index of the parent node of a child node
int MinHeap::parent(int index){
    int p = (index-1)/2;
    return p;
}

// returns the index of the left child node of a parent node
int MinHeap::getLeftChild(int index){
    int l = (2*index)+1;
    return l;
}

// returns the index of the right child node of a parent node
int MinHeap::getRightChild(int index){
    int r = (2*index)+2;
    return r;
}

// returns the smallest(root) element of the heap
int MinHeap::getMin(){
    if(size == 0) return -1;

    return this->array[0];
}

//function to insert key to the Heap.
void MinHeap::insert(int key){
    // if the heap is full. we cannot insert.
    if(size==capacity) {
        std::cout << "Cannot insert. Size Full" << std::endl;
        return;
    }

    size++;
    int index = size-1;
    array[size-1]=key;
    
    // move Up to maintain heap property   
    heapifyUp(index);
    std::cout << "Inserted Key: " << key << std::endl;
}

// This function will keep moving the node up the tree until the heap property is restored.
void MinHeap::heapifyUp(int index){
    while (index != 0 && array[parent(index)] > array[index])
    {
       swap(array[index], array[parent(index)]);
       index = parent(index);
    }
}

// This function will keep moving the node down the tree until the heap property is restored.
void MinHeap::heapifyDown(int index){
    if(size == 1){
        std::cout << "Single element in the MinHeap" << std::endl;
    }
    else{
        int left = getLeftChild(index);
        int right = getRightChild(index);
        int minimum = index;
        
        if(left < size && array[left] < array[minimum]){
            minimum = left;
        }
        if(right < size && array[right] < array[minimum]){
            minimum = right;
        }
        
        if(minimum != index){
            swap(array[minimum],array[index]);
            heapifyDown(minimum);
        }
    }
}

// This function removes and returns the element which is the smallest among all.
int MinHeap::extractMin(){
    if(!isEmpty()){
        int index = 0;
        int minimum = array[index];
        swap(array[index], array[size-1]);
        size--;
        heapifyDown(index);
        return minimum;
    }
    else{
        std::cout << "Heap is Empty." << std::endl;    
    }
}

// function that decreases the value of element;s key to new value at a node
void MinHeap::decreaseKey(int index, int key){
		array[index] = key;

        // move Up to maintain heap property 
		heapifyUp(index);
}

// function to remove key from the selected index
void MinHeap::removeKey(int index){
    if(size==0){
        std::cout << "Cannot remove.Empty Heap." << std::endl;
    }
    if(index == -1){
        std::cout << "Cannot remove." << std::endl;
    }
    array[index] = array[size-1];
    size--;
    heapifyDown(index);
}
 
// function that displays every element of Heap
void MinHeap::display(){
    std::cout << "The elements are: " << std::endl;
    for(int index = 0; index < size; index++){
        std::cout << array[index] << " \t";
    }
    std::cout << std::endl;
}