/*
Given 2 strings write a method to decide if one is a permutation of the other. 
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

bool isPermutation_sorting(string s1, string s2){ // space compl -> O(1) : Time compl -> O(nlogn)
    if(s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i = 0; i < s1.size(); i++)
        if(s1.at(i) != s2.at(i)) return false;

    return true;
}

bool isPermutation(string s1, string s2){ // Space compl -> O(1) : Time compl -> O(s1.size())
    if(s1.size() != s2.size()) return false;
    int charset[128] = {0};
    for(int i = 0; i < s1.size(); i++){
        charset[s1.at(i)]++;
        //cout << charset[s1.at(i)] << " ";
    }
    for(int i = 0; i < s2.size(); i++)
        charset[s2.at(i)]--;

    for(int i = 0; i < 128; i++)
        if(charset[i] != 0) return false;
    return true;
}

int main(){
    cout << isPermutation("ciao", "oaic") << endl;
    cout << isPermutation("ciao", "bomba") << endl;
    cout << isPermutation("hello", "ciaoo") << endl;
}