#include <bits/stdc++.h>
using namespace std;

// lc - 33
int search(vector<int>& nums, int target) {
    int lo=0, hi=nums.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (nums[mid] == target) return mid;
        
        // Check which half is sorted
        if (nums[lo] <= nums[mid]) {         // LEFT half is sorted
            if (nums[lo] <= target && target < nums[mid])
                hi = mid - 1;                // target in left half
            else
                lo = mid + 1;                // target in right half
        } else {                             // RIGHT half is sorted
            if (nums[mid] < target && target <= nums[hi])
                lo = mid + 1;                // target in right half
            else
                hi = mid - 1;               // target in left half
        }
    }
    return -1;
}
// Time O(log n), Space O(1)