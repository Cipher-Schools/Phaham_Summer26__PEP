// lc - 238

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    
    // Left pass: ans[i] = product of nums[0..i-1]
    int left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;
        left *= nums[i];   // build running left product
    }
    // Right pass: multiply in product of nums[i+1..n-1]
    int right = 1;
    for (int i = n-1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];  // build running right product
    }
    return ans;
}
// After left pass:  [1, 1, 2, 6]     (left products)
// right = 1: ans[3] *= 1 → 6, right = 4
// right = 4: ans[2] *= 4 → 8, right = 12
// right = 12: ans[1] *= 12 → 12, right = 24
// right = 24: ans[0] *= 24 → 24, right = 24
// Final: [24, 12, 8, 6] ✓
// Time O(n), Space O(1) extra (output array doesn't count)