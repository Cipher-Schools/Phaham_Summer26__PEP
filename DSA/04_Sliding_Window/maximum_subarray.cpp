// lc - 930 | Kadane's Algo

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int current = 0, maxSum = INT_MIN;
    for (int x : nums) {
        current += x;
        maxSum = max(maxSum, current);
        if (current < 0) current = 0;   // reset: negative sum helps nobody
    }
    return maxSum;
}
// [-2,1,-3,4,-1,2,1,-5,4]:
// curr: -2→reset, 1,-2→reset, 4,3,5,6,1,5
// max:   -2,      1,  1,      4,4,5,6,6,6  → answer: 6
// Time O(n), Space O(1)
// Why it works: if current sum is negative, no future element benefits from including it.