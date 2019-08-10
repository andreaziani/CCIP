/* Write a method to replace all spaces in string with "%20" 
*/
#include <stdlib.h>
#include <iostream>

using namespace std;

string replace(string s, int length){ // space compl -> O(1) : Time complexity -> O(length * complexity(replace));
    for(int i = 0; i < length; i++){
        if(s.at(i) == ' '){
            s.replace(i, 1, "%20"); // From c++ doc. generally up to linear in the new string length
            length += 2;
        }
    }
    return s.substr(0, length);
}

string replace_linear(string s, int length){ // space compl -> O(res.size()) : time compl -> O(length)
    string res = "";
    for(int i = 0; i < length; i++){
         if(s.at(i) == ' ') res += "%20";
         else res += s.at(i);
    }
    return res;
}
int main(){
    cout << replace_linear("Ciao come va  ", 12) + "ciao" << endl;
}