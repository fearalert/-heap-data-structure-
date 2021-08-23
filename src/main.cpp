#include <iostream>
#include "../include/heap.h"
#include "priorityQueue.cpp"

int main(){
    MinHeap obj(7);
    std::cout << std::endl << "----------------------------------------" << std::endl;
    std::cout << "\t  Min Heap Created" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Is Empty? Yes(1)/ No(0): " << obj.isEmpty() << std::endl;
    obj.insert(10);
    obj.insert(5);
    obj.insert(15);
    obj.insert(8);
    obj.insert(7);
    obj.insert(4);
    obj.insert(20);
    obj.insert(44);
    std::cout << "Is Empty? Yes(1)/ No(0): " << obj.isEmpty() << std::endl;
    std::cout << "Is Full? Yes(1)/ No(0): " << obj.isFull() << std::endl;
    std::cout << "Minimum/root element of the given Heap is: " << obj.getMin() << std::endl;
    obj.display();
    obj.extractMin();
    std::cout << "After extracting minimum, ";
    obj.display();
    obj.decreaseKey(1,3);
    std::cout << "After decreasing value of index 1, ";
    obj.display();
    obj.removeKey(3);
    std::cout << "After removing element from index 3, ";    
    obj.display();


    HeapPriorityQueue Q(7);
    std::cout << std::endl << "------------------------------------------------------------------" << std::endl;
    std::cout << "\tAscending Priority Queue Implementation" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Is Empty? Yes(1)/ No(0): " << Q.isEmpty() << std::endl;
    Q.enqueue(10);
    Q.enqueue(5);
    Q.enqueue(15);
    Q.enqueue(8);
    Q.enqueue(7);
    Q.enqueue(4);
    Q.enqueue(20);
    Q.enqueue(44);
    Q.displayQueue();
    std::cout << "Is Empty? Yes(1)/ No(0): " << Q.isEmpty() << std::endl;
    std::cout << "Is Full? Yes(1)/ No(0): " << Q.isFull() << std::endl;
    std::cout << "Minimum element of priority queue is: ";
    std::cout <<  Q.getMinimum() << std::endl;
    Q.dequeue();
    Q.displayQueue();
    Q.enqueue(3);
    Q.displayQueue();

    return 0;
}