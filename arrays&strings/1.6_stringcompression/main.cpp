#include <stdlib.h>
#include <iostream>

using namespace std;

class StringBuilder {
    private:
        int length;
        int curr;
        char* s;

    public: 
        StringBuilder(int finalLength){
            length = finalLength;
            s = new char[finalLength];
            curr = 0;
        }

        void addChar(char c){
            s[curr] = c;
            curr++;
            if(curr == length) {
                char* tmp = new char[length];
                for(int i = 0; i < length; i++){
                    tmp[i] = s[i];
                }
                length *=2;
                for(int i = 0; i < length/2; i++){
                    s[i] = tmp[i];
                }
            }
        }

        string toString(){
            return s;
        }
};

/* Simple solution: count chars ad add to a new string */
// ! To improve our solution we can use the StringBuilder class that helps us to build our string without using string concatenation !
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