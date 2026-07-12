// lc - 205

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char,char> mapST, mapTS;
    for (int i = 0; i < s.size(); i++) {
        char a = s[i], b = t[i];
        if (mapST.count(a) && mapST[a] != b) return false;   // a already maps elsewhere
        if (mapTS.count(b) && mapTS[b] != a) return false;   // b already mapped from elsewhere
        mapST[a] = b;
        mapTS[b] = a;
    }
    return true;
}
// Time O(n), Space O(1) - at most 256 ASCII entries per map
// "foo"→"bar": i=0: f→b ok. i=1: o→a ok. i=2: o→r, but mapST[o]=a already! → false