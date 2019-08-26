/* Trie implementation */
#include <stdlib.h>
#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
    public: TrieNode *nodes[ALPHABET_SIZE];
    public: bool isEndOfWord; // true if this node is the end of a word
    public: TrieNode(){
        isEndOfWord = false; 
        for (int i = 0; i < ALPHABET_SIZE; i++) 
            this->nodes[i] = NULL; 
    }
    public: TrieNode(bool isEnd){
        this->isEndOfWord = isEnd;
        for (int i = 0; i < ALPHABET_SIZE; i++) 
            this->nodes[i] = NULL; 
    }
};

class Trie{
    private: TrieNode* root;

    public: Trie(){
        root = new TrieNode();
    }

    public: void insert(string s){
        if(s.size() == 0) return; 
        TrieNode* tmp = root;
        for (int i = 0; i < s.length(); i++) { 
            int index = s[i] - 'a'; 
            if (!tmp->nodes[index]) 
                tmp->nodes[index] = new TrieNode(); 
    
            tmp = tmp->nodes[index]; 
        } 
        tmp->isEndOfWord = true; // mark the end as leaf
    }

    public: bool searchKey(string s){
        if(s.size() == 0) return false; 
        int counter = 0;
        char c = s.at(counter) - 'a';
        TrieNode* tmp = root;
        
        // check each char
        for (int i = 0; i < s.length(); i++) { 
            int index = s[i] - 'a'; 
            if (!tmp->nodes[index]) return false; // some char is missing
            tmp = tmp->nodes[index]; 
        } 
        return tmp != NULL && tmp->isEndOfWord;
    }
};

int main(){
    Trie t = Trie();
    t.insert("hi");
    t.insert("hello");
    t.insert("halo");
    t.insert("helon");

    cout << t.searchKey("hello") << endl; // true
    cout << t.searchKey("dsd") << endl; // false, no key
    cout << t.searchKey("hel") << endl; // false, no end
}