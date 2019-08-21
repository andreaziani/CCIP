#include <stdlib.h>
#include <iostream>
#include <stack>
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

stack<int> reverse(Node* list){
    stack<int> st;
    Node* tmp = list;
    while(tmp != NULL){
        st.push(tmp->val);
        tmp = tmp->next;
    }
    return st;
}
bool isEqual(Node* l, stack<int> s){
    while(l != NULL){
        if(l->val != s.top()) return false;
        s.pop();
        l = l->next;
    }
    return true;
}
// Time complexity -> O(N) : Space complexity -> O(N)
bool isPalindrome(Node* list){
    stack<int> st = reverse(list);
    return isEqual(list, st);
}

int main(){
    Node list = Node(1);
    list.push_back(2);
    list.push_back(2);
    list.push_back(1);

    cout << isPalindrome(&list) << endl;
}