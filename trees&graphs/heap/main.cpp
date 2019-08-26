/*
    Min heap implementation
*/
#include <stdlib.h>
#include <iostream>
using namespace std;

class Heap{
    private: int* nodes;
    private: int heap_size;
    private: int capacity;

    public: Heap(int cap){
        capacity = cap;
        nodes = new int[capacity];
        heap_size = 0;
    }
    
    public: int getMin(){
        if(heap_size <= 0) throw new exception();
        return nodes[0];
    }

    public: void insert(int d){
        if(heap_size == capacity) throw new exception();
        heap_size++;
        int i = heap_size - 1;
        nodes[i] = d; // insert at the bottom rightmost
        while(i != 0 && nodes[i] < nodes[parent(i)]){ // if the parent is greater than the child bubble up the element
            swapNodes(&nodes[i], &nodes[parent(i)]);
        }
    }

    public: int extractMin(){
        if(heap_size <= 0) throw new exception();
        
        int min = nodes[0];
        nodes[0] = nodes[heap_size - 1]; // swap with last element
        heap_size--;
        heapify(0); // heapify
        
        return min;
    }

    public: void decreaseKey(int index, int val){
        if(val > nodes[index] || index > heap_size) throw new exception();
        nodes[index] = val;
        while(index != 0 && nodes[parent(index)] > nodes[index]){ // restore heap properties
            swapNodes(&nodes[index], &nodes[parent(index)]);
            index = parent(index);
        }
    }

    public: void deleteKey(int index){
        if(index > heap_size) throw new exception();
        decreaseKey(index, INT_MIN); // by replacing the current key with the minimum, it will become the root
        extractMin(); // then we extract the root and restore heap props with heapify().
    }

    private: void heapify(int i){ // if the current is higher than his childs swap the current element with the smallest of his childs. Repeat until we have the min element at the root again
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && nodes[l] < nodes[i])
            smallest = l;
        if(r < heap_size && nodes[r] < nodes[smallest])
            smallest = r;
        if(smallest != i){
            swapNodes(&nodes[i], &nodes[smallest]);
            heapify(smallest);
        }
    }

    private: void swapNodes(int* x, int* y){
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }

    private: int parent(int i){
        return (i - 1) / 2;
    }

    private: int right(int i){
        return (i * 2) + 2;
    }

    private: int left(int i){
        return (i * 2) + 1;
    }
};
int main(){
    Heap h = Heap(11); 
    h.insert(3); 
    h.insert(2); 
    h.deleteKey(1); //del 3
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45); 
    cout << h.extractMin() << endl; // remove 2
    cout << h.getMin() << endl; // should be 4
    h.decreaseKey(2, 1); 
    cout << h.getMin() << endl; 
    return 0; 
}