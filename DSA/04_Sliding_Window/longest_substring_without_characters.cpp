// lc - 3

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int lo=0, maxLen=0;
    for (int hi=0; hi < s.size(); hi++) {
        while (window.count(s[hi]))      // duplicate found
            window.erase(s[lo++]);       // shrink left until gone
        window.insert(s[hi]);            // add new character
        maxLen = max(maxLen, hi-lo+1);
    }
    return maxLen;
}
// Time O(n), Space O(min(n, alphabet_size))
// Variation: use unordered_map<char,int> storing LAST SEEN INDEX
// → jump lo directly to lastSeen[s[hi]]+1, skipping multiple shrink steps
