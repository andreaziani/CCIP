/* Delete a node in the middle of a linked list by having access from this element only */
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

    public: Node* findKth(int k){
        Node* tmp = this;
        Node* kth = this;
        int count = 1;
        while(tmp != NULL){
            if(count > k){ 
               kth = kth->next; // when arrive at least at kth element start sliding the second pointer
            }
            tmp = tmp->next;
            count++;
        }
        if(k > count) return NULL;
        return kth;
    }

    // Time complexity -> O(1) : Space complexity -> O(1)
    public: void deleteMiddleNode(Node* middle){
        if(middle != NULL && middle->next != NULL){
            middle->val = middle->next->val;
            middle->next = middle->next->next;
        }
    }
};

int main(){
    Node list = Node(5);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    
    list.printlist();
    list.deleteMiddleNode(list.findKth(3));
    list.printlist();
}