#include <bits/stdc++.h>
using namespace std;

// lc - 35
int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;   // lo is the insertion point when not found
}
// This is exactly what std::lower_bound does in STL
// lower_bound returns iterator to first element >= target