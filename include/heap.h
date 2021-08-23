#pragma once
#include <iostream>
class MinHeap{
public:
    MinHeap();
    MinHeap(int capacity);
    bool isEmpty();
    bool isFull();
    int getMin();
    void insert(int key);
    int extractMin();
    void removeKey(int index);
    void decreaseKey(int index, int key);
    void display();
    // void swap(int &a, int &b);

private:
    int size;
    int capacity;
    int *array;
    int parent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);
    void heapifyDown(int index);
    void heapifyUp(int index);
};
