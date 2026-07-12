// lc - 344

#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
        swap(s[lo], s[hi]);
        lo++; hi--;
    }
}
// Time O(n), Space O(1) — same two-pointer pattern from arrays
// In C++, std::string also supports swap(s[lo], s[hi]) directly