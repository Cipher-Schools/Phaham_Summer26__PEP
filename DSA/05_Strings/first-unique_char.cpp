// lc - 387

#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;          // pass 1: build frequency map
    for (int i = 0; i < s.size(); i++)   // pass 2: find first count==1
        if (freq[s[i]] == 1) return i;
    return -1;
}
// Time O(n) - two passes, still linear
// Space O(1) - at most 26 lowercase letters
// Why two passes? You can't know if s[0] is unique without scanning the WHOLE string first.