/*
Design a stack which in addition to push and pop has a function which returns the minimum element. 
Push and pop should operate in O(1)!
*/
#include <stdlib.h>
#include <iostream>

using namespace std;

// Idea -> keep track of the minimum of a current state, so if a node is popped the next top has its own min
// Another solution might be using another stack to keep track of the localMins and pop an element only if is equal to the element popped in the first stack
class StackNode{
    public: int data;
    public: StackNode* next;
    public: int localMin; // minimum node at the moment when this node has been added
    public: StackNode(int data){
        this->data = data;
    }
};

class Stack{
    public: StackNode* t;
    public: int pop(){
        if(t == NULL) throw new exception();
        int item = t->data;
        t = t->next;
        return item;
    }

    public: void push(int d){
        StackNode* tmp = new StackNode(d);
        if(t == NULL){
            t = tmp;
            t->localMin = t->data;
        } 
        else{ 
            if(t->localMin > d) tmp->localMin = d;
            else tmp->localMin = t->localMin;
            tmp->next = t;
            t = tmp;
        }
    }

    public: int top(){
        if(t == NULL) throw new exception();
        return t->data;
    }

    public: bool isEmpty(){
        return t == NULL;
    }

    public: int getMin(){
        if(t == NULL) throw new exception();
        return t->localMin;
    }
};

int main(){
    Stack s = Stack();
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl; //expected 1
    s.pop();
    cout << s.getMin() << endl; // expected 2
}