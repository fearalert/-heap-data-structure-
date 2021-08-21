#include "../include/priorityQueue.h"

class HeapPriorityQueue : public PriorityQueue{
private:
    MinHeap *Q;

public:
  HeapPriorityQueue(int size);
  ~HeapPriorityQueue() { delete Q; }
  bool isEmpty();
  bool isFull();
  void enqueue(int value);
  void dequeue();
  int getMinimum();
  void displayQueue();
};

HeapPriorityQueue::HeapPriorityQueue(int size){ 
    Q = new MinHeap(size); 
}

bool HeapPriorityQueue::isEmpty(){
    Q->isEmpty();
}

bool HeapPriorityQueue::isFull(){
    Q->isFull();
}

void HeapPriorityQueue::enqueue(int value){
    if(isFull())
    {
        std::cout << "Cannot Enqueue " << value <<" .Queue overflow." << std::endl;
    }
    else{
        Q->insert(value);
    }
}

void HeapPriorityQueue::dequeue(){
    if(isEmpty()){
        std::cout << "Cannot Dequeue. Queue Underflow." << std::endl;
    }
    std::cout << "Value Dequeued is: " << Q->extractMin() << std::endl;  
}

int HeapPriorityQueue::getMinimum(){
    if(!isEmpty()){
        std::cout << "Minimum element of priority queue is: " << std::endl;
        return Q->getMin();
    }
    else{
        std::cout << "Cannot get minimum. Queue is empty." << std::endl;
    }
};

void HeapPriorityQueue::displayQueue(){
    Q->display();
}