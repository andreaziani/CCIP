/*
There are 3 types of edits that can be perfomed on strings: insert, delete, replace.
Write a function to check if they are one edit or zero away
 */
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
We don't need to check the strings for insertion, removal or replace. We just focus on the length of strings
If the two strings have the same length the only edit can be a replace. 
If the two strings have different length the different should be max 1 char (one add or one replace).
*/
bool oneAway(string s1, string s2) // Time compl -> O(min size) : space compl -> O(1)
{
    int edits = 0;
    int diff = s1.size() - s2.size();
    if (abs(diff) > 1) return false;
    if (s1.size() < s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1.at(i) != s2.at(i + edits) && edits != 0) return false;
            else if (s1.at(i) != s2.at(i + edits) && edits == 0) edits++;
        }
    } else if(s1.size() > s2.size()){
        for (int i = 0; i < s2.size(); i++)
        {
            if (s1.at(i + edits) != s2.at(i) && edits != 0) return false;
            else if (s1.at(i + edits) != s2.at(i) && edits == 0) edits++;
        }
    } else{
        for (int i = 0; i < s2.size(); i++)
        {
            if (s1.at(i) != s2.at(i) && edits != 0) return false;
            else if (s1.at(i) != s2.at(i) && edits == 0) edits++;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << oneAway(s1, s2) << endl;
}