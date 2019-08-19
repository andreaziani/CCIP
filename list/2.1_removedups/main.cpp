/* Remove duplicates from unsorted linked list */
#include <iostream>
#include <stdlib.h>
#include <map>

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

    //Time complexity -> O(N) : space complexity -> O(hashtable.size())
    public: void removeDups_hashtable(){
        map<int, int> dups;
        Node* tmp = this;
        Node* back = NULL;
        while(tmp != NULL){
            if(dups[tmp->val] != 0){
                 back->next = tmp->next;
            } else{
                back = tmp;
            }
            dups[tmp->val] = 1;
            tmp = tmp->next;
        }
    }

    //Time complexity ->O(N^2) : space complexity -> O(1)
    public: void removeDups_runner(){
        Node* curr = this;
        while(curr != NULL){
            Node* run = curr->next;
            Node* back = curr;
            while(run != NULL){
                if(run->val == curr->val){
                    back->next = run->next;
                } else{
                    back = run;
                }
                run = run->next;
            }
            curr = curr->next;
        }
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

int main(){
    Node list = Node(5);
    list.push_back(6);
    list.push_back(6);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(6);
    list.push_back(9);
    list.printlist();
    list.removeDups_runner();
    list.printlist();
}