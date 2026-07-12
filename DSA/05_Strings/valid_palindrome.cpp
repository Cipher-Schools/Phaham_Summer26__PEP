// lc - 125

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
        if (!isalnum(s[lo])) { lo++; continue; }   // skip non-alnum
        if (!isalnum(s[hi])) { hi--; continue; }
        if (tolower(s[lo]) != tolower(s[hi])) return false;
        lo++; hi--;
    }
    return true;
}
// Time O(n), Space O(1)
// isalnum() = is alphanumeric (letter or digit)