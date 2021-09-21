#include "circular-queue.h"
#include <iostream>
using namespace std;
const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() //constructor without parameter
{
    capacity_ = 16;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) // constructor with parameter
{
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    items_ = new QueueItem[capacity];
}

CircularQueue::~CircularQueue() //deletes allocated memory
{
    delete items_;
    items_ = NULL;
}

bool CircularQueue::empty() const //empty check
{
    if(size_ == 0){
        return true;
    }
    return false;
}

bool CircularQueue::full() const //checks if full
{
    if(size_ == capacity_){
        return true;
    }
    return false;
}

int CircularQueue::size() const //returns size
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value) // adds item to back of queue
{
    if(full()){ //full check
        return false;
    }
    if(tail_ == capacity_ - 1){ //if tail is the last index in the array
        items_[tail_] = value;
        tail_ = 0;
        size_ += 1;
        return true;
    }
    items_[tail_] = value;
    tail_ += 1;
    size_ += 1;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() //returns and removes "first" element
{
    if(empty()){ // empty check
        return EMPTY_QUEUE;
    }
    if(head_ == capacity_ - 1){ //if head is the last index in the array
        head_ = 0;
        size_ -= 1;
        return items_[capacity_ - 1];
    }
    head_ += 1;
    size_ -= 1;
    return items_[head_ - 1];
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if(empty()){ //empty check
        return EMPTY_QUEUE;
    }
    return items_[head_]; //returns "first" item in queue
}

void CircularQueue::print() const
{
    for (int i = 0; i + head_ < size_; i++) {
        cout << items_[head_ + i] << " ";
    }
    if(head_ != 0){
        for(int i = 0; i < head_; i++){
            cout << items_[i] << " ";
        }
    }
}
