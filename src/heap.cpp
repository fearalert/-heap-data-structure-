#include "../include/heap.h"
#include <iostream>
#include <cmath>
#include <vector>

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

int MinHeap::getIndex(int item){
        int index=-1;
        for(int i=0;i<size;i++){
            if(array[i] == item){
                index = i;
                break;
            }
        }
        return index;
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
    display();
}

void MinHeap::heapifyUp(int index){
    int i=size-1;
    while (i != 0 && array[parent(i)] > array[i])
    {
       swap(array[i], array[parent(i)]);
       i = parent(i);
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
    if (key < array[index]) {
		array[index] = key;
		heapifyUp(index);
	}
}

bool MinHeap::search(int key){
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return true;
      }
    }
    return false;
}

void MinHeap::display(){
    std::cout << "The elements are: " << std::endl;
    for(int index = 0; index < size; index++){
        std::cout << array[index] << " \t";
    }
    std::cout << std::endl;
}