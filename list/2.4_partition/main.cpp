/* Partition a linked list around a value x, such that all nodes less than x comes before all nodes greater or equal to x */
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Linked list implementation with class Node */
class Node {
    public: int val; // this is not a good practise but for this ex doesn't matter
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

    // Time complexity -> O(N) : Space complexity -> O(1)
    public: Node* partition(int val){
        Node* start1 = NULL; // begin of less
        Node* start2 = NULL; // begin of grater
        Node* less = NULL; // nodes less than val
        Node* greater = NULL; // nodes greater or equal than val
        Node* tmp = this; // current list
        while(tmp != NULL){
            if(tmp->val < val) {
                if(less == NULL){
                    less = tmp;
                    start1 = less;
                } else {
                    less->next = tmp;
                    less = less->next;
                }
            } else {
                if(greater == NULL){
                    greater = tmp;
                    start2 = greater;
                } else {
                    greater->next = tmp;
                    greater = greater->next;
                }
            }
            tmp = tmp->next;
        }
        less->next = start2;

        return start1;
    }

};
int main(){
    Node list = Node(5);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(10);
    list.push_back(8);

    list.printlist(); 

    Node* tmp = list.partition(4);
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}