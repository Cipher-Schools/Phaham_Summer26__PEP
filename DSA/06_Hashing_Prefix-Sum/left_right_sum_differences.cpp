// lc - 2574

#include <bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 0), right(n, 0);
    for (int i = 1; i < n; i++) left[i] = left[i-1] + nums[i-1];  // prefix sums
    for (int i = n-2; i >= 0; i--) right[i] = right[i+1] + nums[i+1]; // suffix sums
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = abs(left[i] - right[i]);
    return ans;
}
// Can also do in O(1) space using the same total-sum trick from Problem 2:
// rightSum = total - leftSum - nums[i], just like pivot index.
// Time O(n), Space O(n) or O(1) with the two-pass trick