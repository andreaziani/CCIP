/* Write a function that checks if a string is a permutation of a palindrome string. 
 */
#include <stdlib.h>
#include <iostream>

using namespace std;

string clearWhiteSpaces(string s){
    string withoutSpaces = "";
    for(int i = 0; i < s.size(); i++) // remove white spaces
        if(s.at(i) != ' ') withoutSpaces += s.at(i);
    return withoutSpaces;
}

bool isPalPermutation(string s){
    int charset[128] = {0};
    string withoutSpaces = clearWhiteSpaces(s);
    
    for(int i = 0; i < withoutSpaces.size(); i++) // count occurrencies for each char
        charset[withoutSpaces.at(i)]++;

    if(withoutSpaces.size() % 2 == 0){ // if the string is even, chars must occur twice
        for(int i = 0; i < 128; i++){
            if(charset[i] % 2 != 0) return false;
        }
    } else{ // if the string is odd, only one char can occure once (the middle)
        bool middle = false;
        for(int i = 0; i < 128; i++){
            if(charset[i] % 2 != 0 && charset[i] == 1 && middle) return false; // more than one middle element
            else if(charset[i] % 2 != 0 && charset[i] == 1 && !middle) middle = true; // middle found
            else if(charset[i] % 2 != 0 && charset[i] != 1) return false; // odd number which is no one = not palindrome
        }
    }
    return true;
}

int main(){
    cout << isPalPermutation("TTco ac") << endl;
}