// lc - 344

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<char>& s, int lo, int hi) {
    if (lo >= hi) return;          // base case: pointers met or crossed
    swap(s[lo], s[hi]);
    reverse(s, lo+1, hi-1);        // recurse on the inner part
}
void reverseString(vector<char>& s) {
    reverse(s, 0, s.size()-1);
}
// "hello": swap h↔o → "oellh", then swap e↔l → "oleh", then lo>=hi stop
// Each call does O(1) work, n/2 calls total → O(n)