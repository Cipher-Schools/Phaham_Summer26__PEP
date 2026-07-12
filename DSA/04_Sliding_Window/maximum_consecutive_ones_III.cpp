// lc - 1004

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int lo=0, zeros=0, maxLen=0;
    for (int hi=0; hi < nums.size(); hi++) {
        if (nums[hi]==0) zeros++;
        while (zeros > k) {
            if (nums[lo]==0) zeros--;
            lo++;
        }
        maxLen = max(maxLen, hi-lo+1);
    }
    return maxLen;
}
// Time O(n), Space O(1)
// Same pattern as "longest substring with at most k distinct chars"
// "Condition" = zeros <= k. Swap condition → solve any "at most k [something]" problem.