// lc - 643

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];   // first window
    int maxSum = sum;
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - nums[i - k];              // slide: add right, drop left
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum / k;
}
// Time O(n), Space O(1)