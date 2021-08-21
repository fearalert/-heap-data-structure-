#include "../include/heap.h"
#include <iostream>
#include <cmath>

MinHeap::MinHeap(int capacity){
    this->size = 0;
    this->capacity = capacity;
    array = new int[capacity];
}

void MinHeap::swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

bool MinHeap::isEmpty(){
    return size == 0;
}

bool MinHeap::isFull(){
    return size == capacity;
}

int MinHeap::parent(int index){
    int p = (index-1)/2;
    return p;
}

int MinHeap::getLeftChild(int index){
    int l = (2*index)+1;
    return l;
}

int MinHeap::getRightChild(int index){
    int r = (2*index)+2;
    return r;
}

int MinHeap::getMin(){
    if(size == 0) return -1;

    return this->array[0];
}

void MinHeap::insert(int key){
    if(size==capacity) {
        std::cout << "Cannot insert. Size Full" << std::endl;
        return;
    }

    size++;
    int index = size-1;
    array[size-1]=key;
    heapifyUp(index);
    std::cout << "Inserted Key: " << key << std::endl;
}

void MinHeap::heapifyUp(int index){
    while (index != 0 && array[parent(index)] > array[index])
    {
       swap(array[index], array[parent(index)]);
       index = parent(index);
    }
}

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

void MinHeap::decreaseKey(int index, int key){
		array[index] = key;
		heapifyUp(index);
}

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
    // if(searchIndex(index)){
    //     decreaseKey(index, INT8_MIN);
    //     extractMin();
    // }
    // else{
    //     std::cout << "Cannot remove." << std::endl;
    // }
}
 
bool MinHeap::searchIndex(int index){
    for (int i = 0; i < size; i++) {
        if (i == index) {
            std::cout << index << " index found. " << std::endl;
            return true;
      }
    }
    std::cout << index << " index not found. ";
    return false;
}

void MinHeap::display(){
    std::cout << "The elements are: " << std::endl;
    for(int index = 0; index < size; index++){
        std::cout << array[index] << " \t";
    }
    std::cout << std::endl;
}