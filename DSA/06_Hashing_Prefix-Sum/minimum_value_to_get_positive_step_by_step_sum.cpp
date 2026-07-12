// lc -1413

#include <bits/stdc++.h>
using namespace std;

int minStartValue(vector<int>& nums) {
    int prefix = 0, minPrefix = 0;
    for (int x : nums) {
        prefix += x;
        minPrefix = min(minPrefix, prefix);  // track the lowest point
    }
    return max(1, 1 - minPrefix);  // ensure startValue + minPrefix >= 1
}
// [-3,2,-3,4,2]: prefix = -3,-1,-4,0,2  minPrefix = -4
// Answer = max(1, 1-(-4)) = max(1,5) = 5
// Verify: 5-3=2, 2+2=4, 4-3=1, 1+4=5, 5+2=7  — always >= 1 ✓
// Time O(n), Space O(1)