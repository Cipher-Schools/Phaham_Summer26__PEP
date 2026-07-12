// lc - 918

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, maxSum = nums[0], minSum = nums[0];
    int curMax = 0, curMin = 0;
    
    for (int x : nums) {
        curMax = max(curMax + x, x);    // Kadane's for max
        maxSum = max(maxSum, curMax);
        
        curMin = min(curMin + x, x);    // Kadane's for min (find the "worst" chunk)
        minSum = min(minSum, curMin);
        
        total += x;
    }
    // If all negative: maxSum is the answer (circular would give 0 which is wrong)
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}
// Case A (non-circular): maxSum from Kadane's
// Case B (circular): total - minSum (remove the worst middle chunk)
// Answer: max(case A, case B)