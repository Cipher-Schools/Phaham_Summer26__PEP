// lc - 278

#include <bits/stdc++.h>
using namespace std;

int firstBadVersion(int n) {
    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) {
            ans = mid;      // mid is bad — but maybe earlier one is too
            hi = mid - 1;  // go LEFT to find the FIRST bad
        } else {
            lo = mid + 1;  // mid is good — bad version is to the right
        }
    }
    return ans;
}
// This is IDENTICAL to finding the leftmost occurrence in binary search (Pattern 1).
// The "feasibility function" is isBadVersion().
// Monotone: false, false, ..., false, TRUE, TRUE, TRUE
// Answer: the index where it first becomes true.
// Time O(log n), Space O(1)