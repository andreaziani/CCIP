/*
Describe how you can usa a single array to implement three stacks. 
A) Divide the array in three equal parts and allow the individual stacks to grow in that limited space. 
B) Allow the stack blocks to be flexible in size. When one stack exceeds its initial capacity
   we grow the allowable capacity and shift elements as necessary
*/
// As A is simple enough, let's implement B 
#include <stdlib.h>
#include <iostream>
using namespace std;

class MultiStack{
    private: class StackInfo{
        public: int start, size, capacity;
        public: StackInfo(int start, int cap){
            this->start = start;
            this->capacity = cap;
        }

        public: bool isWithinCapacity(int index){
            if (index < 0 || index >= val_size) return false;
            
            /*If index wraps around adjust it*/
            int contiguousIndex = index < start ? index + val_size : index;
            int end = start + capacity;
            return start <= contiguousIndex && contiguousIndex < end;
        }

        public: int lastCapacity(){
            return adjustIndex(start + capacity - 1);
        }

        public: int lastElementIndex(){
            return adjustIndex(start + size - 1);
        }

        public: bool isFull(){ return size == capacity; }
        public: bool isEmpty(){ return size == 0; }
    };

    private: StackInfo info[];
    private: int values[];
    static int val_size;
    static int info_size;
    public: MultiStack(int numberOfStacks, int defSize){
        info[numberOfStacks];
        for(int i = 0; i < numberOfStacks; i++)
            info[i] = StackInfo(defSize * i, defSize);
        
        info_size = numberOfStacks;
        values[numberOfStacks * defSize];
    }

    public: void push(int stackNum, int val){
        if(allStacksAreFull()) throw new exception();
        
        StackInfo inf = info[stackNum];
        if(inf.isFull()) expand(stackNum);
        
        // find the index of the top element in the array + 1 and increment the pointer
        inf.size++;
        values[inf.lastElementIndex()] = val;
    }

    public: int pop(int stackNum) {
        StackInfo inf = info[stackNum];
        if(inf.isEmpty()) throw new exception();

        // remove last element
        int val = values[inf.lastElementIndex()];
        values[inf.lastElementIndex()] = 0;
        inf.size--;
        return val;
    }

    public: int peek(int stackNum){
        StackInfo i = info[stackNum];
        return values[i.lastElementIndex()];
    }

    /*
    Shift items in stack over by one element. If we have available capacity, then shrink the stack by one element.
    If you don't have available capacity, then need to shift the next stack over too. 
    */
    private: void shift(int stackNum){
        cout << "Shifting " + stackNum << endl;
        StackInfo stack = info[stackNum];
        
        // if stack is at full cap, then move the next stack over by one element. Now stack can claim the freed index
        if(stack.size >= stack.capacity) {
            int nextStack = (stackNum + 1) % info_size;
            shift(nextStack); // recursion
            stack.capacity++; // claim index
        }

        int index = stack.lastCapacity();
        while(stack.isWithinCapacity(index)){
            values[index] = values[previousIndex(index)];
            index = previousIndex(index);
        }

        /* Adjust stack data */
        values[stack.start] = 0; //clear item
        stack.start = nextIndex(stack.start);
        stack.capacity--;
    }

    private: void expand(int stackNum){
        shift((stackNum + 1) % info_size);
        info[stackNum].capacity++;
    }

    public: int numberOfElements(){
        int size = 0;
        for(StackInfo sd : info){
            size += sd.size;
        }
        return size;
    }

    public: bool allStacksAreFull(){
        return numberOfElements() == val_size;
    }

    //Adjust the index to be within the range of 0 -> length - 1
    static int adjustIndex(int index){
        int max = val_size;
        return ((index % max) + max) % max; 
    }

    private: int nextIndex(int index){
        return adjustIndex(index + 1);
    }

    private: int previousIndex(int index){
        return adjustIndex(index - 1);
    }
};


int main(){

}