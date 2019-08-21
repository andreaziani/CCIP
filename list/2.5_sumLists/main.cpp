/*You have 2 numbers represented by a linked list, where each node contains a single digit, stored in reverse order. 
write a function that adds the two numbers and returns the sum as a linked list. */
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node {
    public: int val; // this is not a good OOP practise but for this ex doesn't matter
    public: Node* next;
    
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
};

// Time complexity -> O(N) where N is the size of the longest list : Space complexity -> O(1)
Node* sumLists(Node* l1, Node* l2){
    Node* res = NULL;
    Node* tmp = res;
    int r = 0;
    int q = 0;
    while(l1 != NULL){ // suppose that l1 is the longest list otherwise we should check the size of both lists
        if(l2 != NULL){
            q = (l1->val + l2->val + r) % 10;
            r = (l1->val + l2->val + r) / 10;
            l2 = l2->next;
        } else{
            q = (l1->val + r) % 10;
            r = (l1->val + r) / 10;
        }
        if(tmp == NULL) res = tmp = new Node(q);
        else {
            tmp->next = new Node(q);
            tmp = tmp->next;
        }
        l1 = l1->next;
    }
    return res;
}

Node* sumLists_order(Node* l1, Node* l2){

}

int main(){
    Node l1 = Node(9);
    l1.push_back(1);
    l1.push_back(1);
    Node l2 = Node(2);
    l2.push_back(1);

    sumLists(&l1, &l2)->printlist();

}