#include <iostream>
#include "../include/heap.h"
#include "priorityQueue.cpp"

int main(){
    MinHeap obj(5);
    std::cout << std::endl << "Min Heap Created" << std::endl;
    std::cout << std::endl;
    obj.insert(10);
    obj.insert(5);
    obj.insert(30);
    obj.insert(33);
    obj.insert(22);
    obj.insert(14);
    obj.insert(2);

    std::cout << "Minimum/root element of the given Heap is: " << obj.getMin() << std::endl;
    obj.display();
    obj.extractMin();
    std::cout << "After extracting minimum, ";
    obj.display();
    obj.decreaseKey(1,3);
    obj.display();

    HeapPriorityQueue Q(6);
    std::cout << std::endl << "Ascending Priority Queue Implementation" << std::endl;
    std::cout << std::endl;

    Q.enqueue(10);
    Q.enqueue(1);
    Q.enqueue(11);
    Q.enqueue(22);
    Q.enqueue(2);
    Q.enqueue(25);
    Q.enqueue(4);
    std::cout << Q.getMinimum() << std::endl;
    Q.dequeue();
    std::cout << Q.getMinimum() << std::endl;
    Q.dequeue();
    std::cout << Q.getMinimum() << std::endl;
    Q.enqueue(14);

    return 0;
}