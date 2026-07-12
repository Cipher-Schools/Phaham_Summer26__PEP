//gfg

#include <bits/stdc++.h>
using namespace std;

char firstRepeatedChar(string s) {
    unordered_set<char> seen;
    for (char c : s) {
        if (seen.count(c)) return c;   // first character we've seen before
        seen.insert(c);
    }
    return '\0';   // no repeated character found
}
// Time O(n), Space O(min(n, alphabet))
// "geeksforgeeks": g(new) e(new) e(SEEN!) → return 'e' immediately