#include "heap.h"
#pragma once

class PriorityQueue
{
public:
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void enqueue(int value) = 0;
    virtual void dequeue() = 0;
    virtual int getMinimum() = 0;
};
