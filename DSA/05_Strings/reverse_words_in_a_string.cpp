// lc - 151

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word, result = "";
    vector<string> words;
    while (ss >> word) words.push_back(word);  // auto-skips extra whitespace
    
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }
    return result;
}
// Time O(n), Space O(n)
// stringstream's >> operator automatically skips leading/multiple spaces - very convenient

// O(1) extra space alternative (excluding output string):
// 1. Reverse the entire string: "blue is sky the  " (roughly)
// 2. Reverse each individual word back to normal
// 3. Clean up extra spaces while reversing
// This is the in-place trick used when space is constrained.