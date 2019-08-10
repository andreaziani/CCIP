/**
 * Simple implemenatation of an hash table. 
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
/* sdbm hash function */
int hash_function(string s){ 
    int hashAddress = 0;
    for (int counter = 0; counter < s.size(); counter++)
        hashAddress = s.at(counter) + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
    return hashAddress;
}
/*  Node of the linked list */
struct Node{
    string s;
    Node* next;
    Node(string st) {
        s = st;
    }
};

/* Utility for printing */
void printHash(vector<Node*> hashtable, int size){
    for(int i = 0; i < size; i++){
        Node* tmp = hashtable[i];
        cout << "Hash Index " << i << " values:" << endl;
        while(tmp != NULL){
            cout << tmp->s << endl;
            tmp = tmp -> next; 
        }
    }
}

int main(){
    int size;
    cout << "Insert hash size: ";
    cin >> size;
    vector<Node*> hashtable(size);

    bool stop = false;
    while (!stop)
    {
        string s;
        cout << endl << "Insert a string: ";
        cin >> s;
        int index = hash_function(s) % size;
        if(hashtable[index] == NULL){
            hashtable[index] = new Node(s);
        } else{
            Node* tmp = hashtable[index];
            while(tmp->next != NULL){
                tmp = hashtable[index]->next;
            }
            tmp->next = new Node(s);
        }
        printHash(hashtable, size);

        cout << "0 to stop, 1 to continue: ";
        int n;
        cin >> n;
        if(n == 0) stop = true;
        else stop = false;
    }
}
