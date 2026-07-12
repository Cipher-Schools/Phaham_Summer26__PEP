// lc - 1480

// A prefix sum array stores cumulative running totals. prefix[i] = sum of all elements from index 0 to i−1. 
// Once built in O(n), any subarray sum [l..r] = prefix[r+1] - prefix[l] in O(1) - no re-summing needed.

#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)
        nums[i] += nums[i-1];   // add previous running total
    return nums;
}
// [1,2,3,4] → [1, 1+2, 1+2+3, 1+2+3+4] = [1,3,6,10]
// Time O(n), Space O(1) — modifies in-place, no extra array