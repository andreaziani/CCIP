/* Given a circular linked list, return the node at the beginning of the loop */
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

class Node {
    public: int val; // this is not a good OOP practise but for this ex doesn't matter
    public: Node* next;
    private: Node* tail;
    public: Node(){
        val = 0;
        next = NULL;
        tail = this;
    }

    public: Node(int v){
        val = v;
        next = NULL;
        tail = this;
    }

    public: void push_back(int v){
        tail->next = new Node(v);
        tail = tail->next;
    }

    public: void push_back(Node* n){
        if(n != NULL){
            tail->next = n;
            tail = tail->next;
        }
    }
    
    public: int size(){
        Node* tmp = this;
        int size = 0;
        while(tmp != NULL){
            tmp = tmp->next;
            size++;
        }
        return size;
    }
    
    public: void printlist(){
        Node* tmp = this;
        while(tmp != NULL){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

Node* loopDetection_fastNSlowRunner(Node* l){
    
}
//Time complexity -> O(N) : Space complexity -> O(N)
Node* loopDetection(Node* l){
    map<Node*, bool> nodes;
    while(!nodes[l]){
        nodes[l] = true;
        if(l->next == NULL) return NULL;
        l = l->next;
    }
    return l;
}

int main(){
    Node list = Node(5);
    Node* n = new Node(1);
    list.push_back(3);
    n->next = list.next;
    list.push_back(2);
    list.push_back(n);
    Node* res = loopDetection(&list);
    if(res == NULL) cout << "The given list is not circular" << endl;
    else cout << loopDetection(&list)->val << endl;
}