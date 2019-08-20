/* Find the kth element to the last using a singly linked list */
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Linked list implementation with class Node */
class Node {
    int val;
    Node* next;
    
    public: Node(int v){
        val = v;
        next = NULL;
    }

    public: void push_back(int v){
        Node* tmp = this;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new Node(v);
    }

    public: void printlist(){
        Node* tmp = this;
        while(tmp != NULL){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    // Time complexity -> O(N) : Space complexity -> O(1)
    public: int findKth(int k){
        Node* tmp = this;
        Node* kth = this;
        int count = 1;
        while(tmp != NULL){
            if(count > k){ 
               kth = kth->next;
            }
            tmp = tmp->next;
            count++;
        }
        if(k > count) return -1;
        return kth->val;
    }
};

int main(){
    Node list = Node(5);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    cout << list.findKth(2) << endl;
}