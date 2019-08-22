/*Given two singly linkied lists, determine if the two lists intersect. An intersection is defined based on the reference 
not value. */
#include <stdlib.h>
#include <iostream>
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
// utility function to add empty nodes if one list is less longer than the other
Node* padList(Node* l1, int shift){ 
    Node* tmp = new Node();
    Node* start = tmp;
    shift--;
    while(shift > 0){
        tmp->next = new Node();
    }
    tmp->next = l1;
    return start;
}

// Time complexity -> O(N) where N is the max length : Space complexity -> O(1)
Node* intersection(Node* l1, Node* l2){
    if(l1->size() > l2->size()) l2 = padList(l2, l1->size() - l2->size()); // if sizes aren't the same padd the less longer list
    if(l2->size() > l1->size()) l1 = padList(l1, l2->size() - l1->size());
    while(l1 != l2 && l1 != NULL && l2 != NULL){
        l1 = l1->next;
        l2 = l2->next;
    } 
    return l1;
}

int main(){
    Node* n = new Node(1);
    
    Node list = Node(5);
    list.push_back(n);
    list.push_back(2);
    
    Node list2 = Node(4);
    list2.push_back(n);
    list.push_back(2);
    Node* inter = intersection(&list, &list2);
    if(inter == NULL) cout << -1;
    else cout << inter->val << endl;
}