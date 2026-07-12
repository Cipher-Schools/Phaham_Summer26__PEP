// lc - 209

#include <bits/stdc++.h>
using namespace std;

int minSubarrayLen(int target, vector<int>& nums) {
    int lo=0, sum=0, minLen=INT_MAX;
    for (int hi=0; hi < nums.size(); hi++) {
        sum += nums[hi];
        while (sum >= target) {
            minLen = min(minLen, hi-lo+1);
            sum -= nums[lo++];
        }
    }
    return minLen==INT_MAX ? 0 : minLen;
}
// Time O(n) - lo and hi together travel 2n steps