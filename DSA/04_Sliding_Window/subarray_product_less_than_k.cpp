// lc - 713

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int lo=0, prod=1, count=0;
    for (int hi=0; hi < nums.size(); hi++) {
        prod *= nums[hi];
        while (prod >= k) prod /= nums[lo++];   // shrink until valid
        count += hi - lo + 1;   // all subarrays [lo..hi],[lo+1..hi],...,[hi..hi]
    }
    return count;
}
// Why count += hi-lo+1 works:
// Window [lo..hi] is valid. Subarrays ending at hi: [lo..hi],[lo+1..hi],...,[hi..hi]
// That's exactly hi-lo+1 subarrays. Each is a subwindow with product <= full window.
// Time O(n), Space O(1)
