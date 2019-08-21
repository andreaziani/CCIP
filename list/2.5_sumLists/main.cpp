/*You have 2 numbers represented by a linked list, where each node contains a single digit, stored in reverse order. 
write a function that adds the two numbers and returns the sum as a linked list. */
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

class PartialSum{
    public: int carry;
    public: Node* node;
    public: PartialSum(){
        this->carry = 0;
        node = NULL;
    }
};

Node* padList(Node* l1, int shift){ // utility function to add zeros if one list is less longer than the other
    Node* tmp = new Node(0);
    Node* start = tmp;
    shift--;
    while(shift > 0){
        tmp->next = new Node(0);
    }
    tmp->next = l1;
    return start;
}

Node* insertBefore(Node* l1, int v){
    Node* node = new Node(v);
    if(l1 != NULL){
        node->next = l1;
    }
    return node;
}

PartialSum* addListHelper(Node* l1, Node* l2){
    if(l1 == NULL && l2 == NULL){
        return new PartialSum();
    } 
    PartialSum* sum = addListHelper(l1->next, l2->next);
    int val = sum->carry + l1->val + l2->val;
    Node* full_res = insertBefore(sum->node, val % 10);
    sum->node = full_res;
    sum->carry = val / 10;
    return sum;
}

// If the list is given in the correct order we need to check the size of both lists and recursively calculate the carry by the end to the front of the list
Node* sumLists_order(Node* l1, Node* l2){
    if(l1->size() > l2->size()) l2 = padList(l2, l1->size() - l2->size());
    if(l2->size() > l1->size()) l1 = padList(l1, l2->size() - l1->size());

    Node* res = new Node(0);
    PartialSum* sum = addListHelper(l1, l2);
    if(sum->carry == 0) return sum->node;
    else return res = insertBefore(sum->node, sum->carry);
}


// Time complexity -> O(N) where N is the size of the longest list : Space complexity -> O(N)
Node* sumLists(Node* l1, Node* l2, int carry){
    if(l1 == NULL && l2 == NULL && carry == 0) return NULL;

    Node* res = new Node();
    int val = carry;
    if(l1 != NULL) val += l1->val;
    if(l2 != NULL) val += l2->val;
    res->val = val % 10;
    
    if(l1 != NULL || l2 != NULL){ // recursion
        Node* more = sumLists(l1 != NULL? l1->next : NULL, l2 != NULL? l2->next : NULL, val >= 10 ? 1 : 0);
        res->push_back(more);
    }
    return res;
}

int main(){
    Node l1 = Node(9);
    l1.push_back(1);
    l1.push_back(1);
    Node l2 = Node(2);
    l2.push_back(1);

    sumLists(&l1, &l2, 0)->printlist();

}