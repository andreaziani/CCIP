#include <stdlib.h>
#include <iostream>

using namespace std;

class StackNode{
    public: int data;
    public: StackNode* next;

    public: StackNode(int data){
        this->data = data;
    }
};

class Stack{
    public: StackNode* top;

    public: int pop(){
        if(top == NULL) throw new exception();
        int item = top->data;
        top = top->next;
        return item;
    }

    public: void push(int d){
        StackNode* tmp = new StackNode(d);
        tmp->next = top;
        top = tmp;
    }

    public: int top(){
        if(top == NULL) throw new exception();
        return top->data;
    }

    public: bool isEmpty(){
        return top == NULL;
    }
};

int main(){
    
}