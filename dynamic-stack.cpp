#include "dynamic-stack.h"
#include <iostream>

using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() //constructor
{
    capacity_ = 16;
    init_capacity_ = 16;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity) //constructor with given capacity
{
    capacity_ = capacity;
    init_capacity_ = capacity_;
    size_ = 0;
    items_ = new StackItem[capacity];
}

DynamicStack::~DynamicStack() //deletes allocated memory
{
    delete [] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const //checks if empty
{
    if(size_ == 0){
        return true;
    }
    return false;
}

int DynamicStack::size() const //returns size
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if(size_ == capacity_) {                                   //size check
        capacity_ *= 2;
        StackItem *tmp = new StackItem[capacity_];             //new array with doubled capacity
        for (int i = 0; i < size_; i++) {                      //copies index values from items to new array
            tmp[i] = items_[i];
        }
        tmp[size_] = value;                                     //value gets pushed
        items_ = tmp;
    }
    else{
        items_[size_] = value;                                  //if not full, push item
    }
    size_ += 1;                                                 //increment size

}

DynamicStack::StackItem DynamicStack::pop()
{
    if(size_ == 0){ //empty stack check
        return EMPTY_STACK;
    }
    if(size_ - 1 <= capacity_ / 4 && capacity_ / 2 >= init_capacity_){ //checks whether or not to half the capacity
        capacity_ /= 2;
    }
    size_ -= 1;
    return items_[size_]; //reduces size and returns top item
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if(size_ == 0){ //empty stack check
        return EMPTY_STACK;
    }
    return items_[size_ - 1]; //returns top item
}

void DynamicStack::print() const
{
    for(int i = 0; i < size_; i++){ //prints from bottom to top of stack
        cout << items_[i] << " " << endl;
    }
    cout << "CAP =" << capacity_ << " " << "SIZ =" << size_ << " " << "iCAP =" << init_capacity_ << endl;
}
