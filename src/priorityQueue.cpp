#include "../include/priorityQueue.h"

class HeapPriorityQueue : public PriorityQueue{
private:
    MinHeap *Q;

public:
  HeapPriorityQueue(int size);
  ~HeapPriorityQueue() { delete Q; }// destructor
  bool isEmpty();
  bool isFull();
  void enqueue(int value);
  void dequeue();
  int getMinimum();
  void displayQueue();
};

// constructor for allocation of size
HeapPriorityQueue::HeapPriorityQueue(int size){ 
    Q = new MinHeap(size); 
}

// checks if priority queue is empty
bool HeapPriorityQueue::isEmpty(){
    Q->isEmpty();
}

//checks if priority queue is full.
bool HeapPriorityQueue::isFull(){
    Q->isFull();
}

// enqueue elements to priority queue
void HeapPriorityQueue::enqueue(int value){
    if(isFull())
    {
        std::cout << "Cannot Enqueue " << value <<" .Queue overflow." << std::endl;
    }
    else{
        Q->insert(value);
    }
}

// dequeue the smallest element(i.e. element with  higher priority)
void HeapPriorityQueue::dequeue(){
    if(isEmpty()){
        std::cout << "Cannot Dequeue. Queue Underflow." << std::endl;
    }
    std::cout << "Value Dequeued is: " << Q->extractMin() << std::endl;  
}

// returns the smallest element in the priority queue
int HeapPriorityQueue::getMinimum(){
    if(!isEmpty()){
        return Q->getMin();
    }
    else{
        std::cout << "Cannot get minimum. Queue is empty." << std::endl;
    }
};

// function that displays the ascending priority queue
void HeapPriorityQueue::displayQueue(){
    Q->display();
}