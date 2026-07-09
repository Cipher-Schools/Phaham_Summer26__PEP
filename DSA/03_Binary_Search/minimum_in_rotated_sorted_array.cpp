#include <bits/stdc++.h>
using namespace std;

// lc - 153
int findMin(vector<int>& nums) {
    int lo=0, hi=nums.size()-1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;    // min is in right half
        else
            hi = mid;        // min is at mid or in left half
    }
    return nums[lo];         // lo == hi, pointing at minimum
}
// [3,4,5,1,2]: mid=5, 5>2 → lo=3. mid=1, 1<=2 → hi=3. lo=hi=3 → nums[3]=1 ✓
// Time O(log n), Space O(1)