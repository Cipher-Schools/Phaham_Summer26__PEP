// lc - 259

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char,int> freq;
    int lo=0, maxLen=0;
    for (int hi=0; hi < s.size(); hi++) {
        freq[s[hi]]++;                           // add incoming char
        while (freq.size() > 2) {               // too many distinct chars
            freq[s[lo]]--;
            if (freq[s[lo]] == 0) freq.erase(s[lo]);
            lo++;
        }
        maxLen = max(maxLen, hi-lo+1);
    }
    return maxLen;
}
// freq.size() = number of distinct chars in window
// Time O(n), Space O(k) - only k entries in the map at most