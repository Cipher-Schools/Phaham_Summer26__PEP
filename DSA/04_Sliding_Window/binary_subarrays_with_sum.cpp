// lc - 930

#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int lo = 0, sum = 0, count = 0;
    for (int hi = 0; hi < nums.size(); hi++) {
        sum += nums[hi];
        while (sum > goal) sum -= nums[lo++];
        count += hi - lo + 1;   // all subarrays ending at hi with sum <= goal
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
// Subarrays with sum == goal
//   = subarrays with sum <= goal
//   - subarrays with sum <= goal-1
// This exact/at-most trick works for any "count subarrays with exactly X" problem!