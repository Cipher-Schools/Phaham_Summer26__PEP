// GFG

#include <bits/stdc++.h>
using namespace std;

int atMostK(string s, int k) {
    unordered_map<char,int> freq;
    int lo=0, maxLen=0;
    for (int hi=0; hi < s.size(); hi++) {
        freq[s[hi]]++;
        while ((int)freq.size() > k) {
            freq[s[lo]]--;
            if (!freq[s[lo]]) freq.erase(s[lo]);
            lo++;
        }
        maxLen = max(maxLen, hi-lo+1);
    }
    return maxLen;
}

int longestKUniques(string s, int k) {
    return atMostK(s, k) - atMostK(s, k-1);
    // exactly k = at most k − at most (k-1)
}