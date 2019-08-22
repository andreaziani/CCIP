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

//Time complexity -> O(LOOPSIZE - k + K) : Space complexity -> O(1)
Node* loopDetection_fastNSlowRunner(Node* l){
    Node* slow = l; // it moves 1 step
    Node* fast = l; // it moves 2 steps
    
    /*If a loop is present, the two pointers will collide after LOOP_SIZE - k turns */
    while(fast != NULL && fast->next != NULL){ 
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    /*if there isn't a loop*/
    if(fast == NULL || fast->next == NULL) return NULL;
    
    /*Move slow to head. Each are k steps from the loop start. if they move at the same space, they must meet at loop start*/
    slow = l;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;

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