#include <stdlib.h>
#include <iostream>

using namespace std;

/* Simple solution: count chars ad add to a new string */
string stringCompression(string s){ // Time compl -> O(n^2) : space Compl -> O(n)
    if(s.size == 0) return s;
    string res = "";
    char last = s.at(0);
    int count = 1;
    for(int i = 1; i < s.size(); i++){
        if(s.at(i) == last) count++;
        else { 
            res += last;
            res += to_string(count); // string concatenation takes O(n)
            count = 1;
            last = s.at(i);
        }
    }
    res += last;
    res += to_string(count);
    if(res.size() > s.size()) return s;
    else return res;
}

int main(){
    string s;
    cin >> s;
    cout << stringCompression(s) << endl;
}