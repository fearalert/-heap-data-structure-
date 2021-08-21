#include <iostream>
#include "../include/heap.h"
#include "priorityQueue.cpp"

int main(){
    MinHeap obj(10);
    std::cout << std::endl << "----------------------------------------" << std::endl;
    std::cout << "\t  Min Heap Created" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Is Empty? Yes(1)/ No(0): " << obj.isEmpty() << std::endl;
    obj.insert(10);
    obj.insert(5);
    obj.insert(30);
    obj.insert(33);
    obj.insert(22);
    obj.insert(14);
    obj.insert(2);
    std::cout << "Is Empty? Yes(1)/ No(0): " << obj.isEmpty() << std::endl;
    std::cout << "Is Full? Yes(1)/ No(0): " << obj.isFull() << std::endl;
    std::cout << "Minimum/root element of the given Heap is: " << obj.getMin() << std::endl;
    obj.display();
    obj.extractMin();
    std::cout << "After extracting minimum, ";
    obj.display();
    obj.decreaseKey(1,3);
    obj.display();
    obj.removeKey(3);
    std::cout << "After removing element from index 3, ";
    obj.display();
    obj.insert(44);
    obj.insert(11);
    obj.insert(12);
    obj.display();


    HeapPriorityQueue Q(8);
    std::cout << std::endl << "------------------------------------------------------------------" << std::endl;
    std::cout << "\tAscending Priority Queue Implementation" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Is Empty? Yes(1)/ No(0): " << Q.isEmpty() << std::endl;
    Q.enqueue(10);
    Q.enqueue(1);
    Q.enqueue(11);
    Q.enqueue(22);
    Q.enqueue(2);
    Q.enqueue(5);
    Q.enqueue(24);
    Q.enqueue(4);
    Q.enqueue(14);
    Q.displayQueue();
    std::cout << "Is Empty? Yes(1)/ No(0): " << Q.isEmpty() << std::endl;
    std::cout << "Is Full? Yes(1)/ No(0): " << Q.isFull() << std::endl;
    std::cout << Q.getMinimum() << std::endl;
    Q.dequeue();
    std::cout << Q.getMinimum() << std::endl;
    Q.dequeue();
    Q.displayQueue();
    Q.enqueue(3);
    Q.displayQueue();
    std::cout << Q.getMinimum() << std::endl;

    return 0;
}