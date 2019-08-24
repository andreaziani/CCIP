/*
    Imagine a stack of plates, if the stack gets too high, it might topple. 
    Therefore we would likely start a new stack when previous stack exceeds some threshold.
    Implement a data structure that mimics this.
    SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity, 
    .push() and .pop() should behave identically to a single stack. Futhermore, implement a function popAt(index) 
    which performs a pop operation  on a specific sub-stack.
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

class SetOfStacks{
    private: vector<Stack> stacks;
    private: int stack_size;
    private: int curr_stack;

    public: SetOfStacks(int stackSize){
        stack_size = stackSize;
        curr_stack = 0;
        stacks.push_back(Stack());
    }

    public: void push(int d){
        if(stacks[curr_stack].size == stack_size) curr_stack++;
        stacks.push_back(Stack());
        stacks[curr_stack].push(d);
    }

    public: int pop(){
        int item = stacks[curr_stack].pop();
        if(stacks[curr_stack].size == 0){
            stacks.pop_back();
            curr_stack--;
        }
        return item;
    }

    public: int popAt(int index){
        if(index > curr_stack) return -1; //exceeds the current dim

        int item = stacks[index].pop();
        if(stacks[index].size == 0){
            for(int i = index; i < curr_stack; i++){ // if a stack in the middle become empty, remove this and shift the other
                stacks[i] = stacks[i + 1];
            }
            stacks.pop_back();
            curr_stack--;
        }
        return item;
    }

    public: void printInfoOfStacks(){
        for(int i = 0; i <= curr_stack; i++){
            cout << "Size of stack " << i << " : " << stacks[i].size << " - ";
        }
        cout << endl;
    }
};

int main(){
    SetOfStacks set = SetOfStacks(3);
    for(int i = 0; i < 9; i++)
        set.push(i);
    set.printInfoOfStacks();
    set.pop();
    set.pop();
    set.printInfoOfStacks();
    set.popAt(1);
    set.popAt(1);
    set.popAt(1);
    set.printInfoOfStacks();
}