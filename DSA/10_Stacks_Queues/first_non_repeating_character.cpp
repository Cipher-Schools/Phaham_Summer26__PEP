// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string &s) {
    queue<char>q;
    vector<int>freq(26, 0);
    string result = "";
    for(char c: s){
        freq[c-'a']++;
        q.push(c);
        while(!q.empty() && freq[q.front()-'a']>1) q.pop();
        if(!q.empty()) result += q.front();
        else result += '#';
    }
    return result;
}