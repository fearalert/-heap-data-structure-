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
  void changePriority(int index, int newValue);
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
        std::cout << value << " enqueued in queue." << std::endl;
        Q->insert(value);
    }
}

void HeapPriorityQueue::dequeue(){
    if(isEmpty()){
        std::cout << "Cannot Dequeue. Queue Underflow." << std::endl;
    }
    std::cout << "Value Dequeued is: " << Q->getMin() << std::endl;
    Q->extractMin();
    Q->display();
}

int HeapPriorityQueue::getMinimum(){
    std::cout << "Minimum element of priority queue is: " << std::endl;
    return Q->getMin();
};
