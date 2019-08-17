#include <iostream>
#include <stdlib.h>
using namespace std;

// assume that isSubstring is a method that tells you if s2 is substring of s1
bool isSubstring(string s1, string s2){
    return true;
}

bool isRotation(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    int rot = -1;
    for(int i = s2.size(); i >= 0; i--){ // find where rotation starts
        if(s2.at(i) == s1.at(0)){
            rot = i;
            break;
        }
    }

    if(rot == -1) return false; //if no rotation point found
    
    for(int i = rot + 1; i < s2.size(); i++){ // if all the chars after the rotation point are equals to the beginning
        if(s2.at(i) != s1.at(i - rot)) return false;
    }

    return isSubstring(s1, s2.substr(0, rot)); //if the part before rot point is a substring of s1, s2 is a rotation of s1
}

/*This is an elegant way. Concat s1 with s1, if s2 is a rotation it has to be a substring of the new s1+s1*/
bool isRotation_best(string s1, string s2){
    if(s1.size() == s2.size() && s1.size()>0){
        string s1s1 = s1 + s1;
        return isSubstring(s1s1, s2);
    }
    return false;
}

int main(){
    string s1, s2;
    cout << isRotation_best(s1, s2);
}