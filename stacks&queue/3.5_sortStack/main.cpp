/*
    Write a program to sort a stack such that the smallest items are on the top. 

    First idea -> sort s1 by inserting each element from s1 in order into s2. To do that pop from s1 and hold 
    in a temp variable. Then if top in s2 is > than tmp, push the top in s1 and then push tmp into s2.

    Second idea -> If we are allowed to use an unlimited stack we can implement a modified quicksort or mergesort. 
    With the merge solution we would create two extra astacks and divide the stack into 2 parts. then recursively sort each stack 
    and then merge them back together. This would require 2 stacks per level of recursion. 

*/
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


    // Time compl -> O(N^2) : Space Compl -> O(N)
    public: void sort(){
        Stack tmp = Stack();
        if(this->size != 0)
            tmp.push(this->pop());
        while(this->size != 0){
            if(tmp.top() > this->top()){
                int item = this->pop();
                while(tmp.top() > item){
                    this->push(tmp.pop());
                }
                tmp.push(item);
            } else {
                tmp.push(this->pop());
            }
        }
        while(tmp.size != 0) this->push(tmp.pop());
    }
};

int main(){
    Stack s = Stack();
    s.push(3);
    s.push(2);
    s.push(7);
    s.push(3);
    s.push(1);

    s.sort();

    while(s.size != 0) cout << s.pop() << " ";
}