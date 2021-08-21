#pragma once
#include <iostream>
class MinHeap{
public:
    MinHeap(int capacity);
    bool isEmpty();
    bool isFull();
    int getMin();
    void insert(int key);
    void display();
    int extractMin();
    void removeKey(int index);
    int getIndex(int key);
    bool search(int key);
    void decreaseKey(int index, int key);
    bool change(int index, int newKey);

private:
    int size;
    int capacity;
    int *array;
    int parent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);
    void swap(int &a, int &b);
    void heapifyDown(int index);
    void heapifyUp(int index);

};
