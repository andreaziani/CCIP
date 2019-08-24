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
    public: StackNode* t;
    public: int size;
    
    public: Stack(){
        size = 0;
    }

    public: int pop(){
        if(t == NULL) throw new exception();
        int item = t->data;
        t = t->next;
        size--;
        return item;
    }

    public: void push(int d){
        StackNode* tmp = new StackNode(d);
        tmp->next = t;
        t = tmp;
        size++;
    }

    public: int top(){
        if(t == NULL) throw new exception();
        return t->data;
    }

    public: bool isEmpty(){
        return t == NULL;
    }
};

int main(){
    
}