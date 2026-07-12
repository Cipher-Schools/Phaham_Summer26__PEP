// lc - 242

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++) {
        freq[s[i]-'a']++;     // count up for s
        freq[t[i]-'a']--;     // count down for t
    }
    for (int x : freq)
        if (x != 0) return false;   // mismatch — not an anagram
    return true;
}
// Time O(n), Space O(1) — fixed 26-size array
// Sort-based alternative: sort(s.begin(),s.end()); sort(t.begin(),t.end()); return s==t;
// O(n log n) — simpler to write but asymptotically worse