#include <stdlib.h>
#include <iostream>

using namespace std;

class QueueNode{
    public: int data;
    public: QueueNode* next;

    public: QueueNode(int data){
        this->data = data;
    }
};

class Queue{
    public: QueueNode* first;
    public: QueueNode* last;

    public: int pop(){
        if(first == NULL) throw new exception();
        int item = first->data;
        first = first->next;
        if(first == NULL) last = NULL;
        return item;
    }

    public: void add(int d){
        QueueNode* tmp = new QueueNode(d);
        last->next = tmp;
        last = tmp;
        if(first == NULL) first = last;
    }

    public: int peek(){
        if(first == NULL) throw new exception();
        return first->data;
    }

    public: bool isEmpty(){
        return first == NULL;
    }
};

int main(){
    
}