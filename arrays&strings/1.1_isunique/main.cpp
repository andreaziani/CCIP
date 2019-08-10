/*
Implements an algorithm to check if a string has all unique chars. 
What if you cannot use additional data structures? 
*/
#include <stdlib.h>
#include <iostream>
using namespace std;

bool isUnique_bruteforce(string s){ // without additional datastructures. Time compl -> O(n^2) : Space -> O(1)
    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            if(s.at(i) == s.at(j)) return false;
        }
    }
    return true;
}

bool isUnique_sort(string s){ // without additional datastructures, if it's allowed to sort the string. Time compl -> O(nlogn) : Space -> O(1)
    sort(s.begin(), s.end());
    for(int i = 0; i < s.size() - 1; i++)
        if(s.at(i) == s.at(i+1)) return false;
    return true;
}

bool isUnique_charset(string s){ // Using an array of bool to sign the checked. Time Compl-> O(n) : Space -> O(1)
    if(s.size() > 128) return false;
    bool chars[128];
    for(int i = 0; i < s.size(); i++){
        if(chars[s.at(i)] != 0) return false;
        chars[s.at(i)] = 1;
    }
    return true;
}

bool isUnique_bitshifting(string s){ // using a single int with his bits. Time Compl-> O(n) : Space -> O(1)
    int checker = 0; 
    for(int i = 0; i < s.size(); i++){ // assume that all chars are lower case. if not, we can't use a single int.
        int val = s.at(i) - 'a';
        if((checker & (1 << val)) > 0) return false;
        checker |= (1 << val);
    }
    return true;
}


int main(){
    string s;
    cin >> s;
    cout << isUnique_sort(s) << endl;
}