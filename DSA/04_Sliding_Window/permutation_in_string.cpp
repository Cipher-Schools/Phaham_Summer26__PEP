// lc - 567

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    int k = s1.size();
    vector<int> need(26, 0), have(26, 0);
    for (char c : s1) need[c-'a']++;
    int matches = 0, total = 26;
    // count initial matches
    for (int i = 0; i < k; i++) have[s2[i]-'a']++;
    for (int i = 0; i < 26; i++) if (have[i]==need[i]) matches++;
    if (matches == 26) return true;
    for (int i = k; i < s2.size(); i++) {
        int in = s2[i]-'a', out = s2[i-k]-'a';
        // add incoming char
        if (have[in]==need[in]) matches--;
        have[in]++;
        if (have[in]==need[in]) matches++;
        // remove outgoing char
        if (have[out]==need[out]) matches--;
        have[out]--;
        if (have[out]==need[out]) matches++;
        if (matches == 26) return true;
    }
    return false;
}
// Time O(n), Space O(1) - the 26-char array is constant size