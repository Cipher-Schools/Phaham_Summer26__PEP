// lc - 1695

#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> window;
    int lo=0, sum=0, maxSum=0;
    for (int hi=0; hi < nums.size(); hi++) {
        while (window.count(nums[hi])) {    // duplicate entering
            sum -= nums[lo];
            window.erase(nums[lo++]);       // remove from left
        }
        window.insert(nums[hi]);
        sum += nums[hi];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
// Two things tracked simultaneously: uniqueness (set) and sum (integer)
// This is the power of combining data structures with the sliding window frame.