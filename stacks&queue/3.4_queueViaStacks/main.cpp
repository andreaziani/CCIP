/*
    Implement a queue using 2 stacks.
*/
#include <stdlib.h>
#include <iostream>
#include <vector>

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

/*
    We can use the second stack to reverse the order of the first. This is implemented using a lazy approach where we let
    elements sit in s2 util we absolutely must reverse the elements (when an add operation comes).
*/
class MyQueue {
    private: vector<Stack> stacks;

    public: MyQueue(){
        stacks.push_back(Stack());
        stacks.push_back(Stack());
    }

    public: void add(int d){
        while(stacks[1].size > 0){
            stacks[0].push(stacks[1].pop());
            //cout << " add " << endl;
        }
        stacks[0].push(d);
    }

    public: int pop(){
        //cout << "POP: " << endl;
        int size = stacks[0].size;
        for(int i = 0; i < size - 1; i++){
            int k = stacks[0].pop();
            stacks[1].push(k);
            //cout << "Moving " << k << " to s2" << endl;
        }
        
        int item = stacks[0].pop();
        if(stacks[1].size > 0) stacks[0].push(stacks[1].pop());
        return item;
    }

    
};

int main(){
    MyQueue q = MyQueue();

    for(int i = 0; i < 5; i++)
        q.add(i);
    
    for(int i = 0; i < 2; i++)
        cout << q.pop() << endl;
    for(int i = 7; i < 9; i++)
        q.add(i);
    for(int i = 0; i < 4; i++)
        cout << q.pop() << endl;
}