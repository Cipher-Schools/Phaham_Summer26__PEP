// lc - 724

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int total = 0;
    for (int x : nums) total += x;         // total sum in one pass
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = total - leftSum - nums[i];
        if (leftSum == rightSum) return i;  // pivot found!
        leftSum += nums[i];
    }
    return -1;
}
// At each i: leftSum is sum[0..i-1], rightSum = total - leftSum - nums[i]
// No need to build a prefix array — two-pass with O(1) extra space