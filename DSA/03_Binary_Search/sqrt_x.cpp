#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;
    long lo = 1, hi = x, ans = 1;   // long to avoid overflow (mid*mid)
    
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (mid * mid <= x) {
            ans = mid;      // mid is valid floor sqrt — try LARGER
            lo = mid + 1;
        } else {
            hi = mid - 1;  // mid² too big
        }
    }
    return (int)ans;
}
// x=8: lo=1,hi=8 → mid=4,4²=16>8,hi=3 → mid=2,2²=4≤8,ans=2,lo=3
//      → mid=3,3²=9>8,hi=2 → lo>hi, return 2 ✓
// Time O(log x), Space O(1)
// Answer range: lo=1, hi=x
// Feasibility: mid*mid <= x