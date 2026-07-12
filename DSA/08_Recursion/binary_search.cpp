// lc - 704

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target, int lo, int hi) {
    if (lo > hi) return -1;                          // base: not found
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) return binarySearch(nums, target, mid+1, hi);
    else                         return binarySearch(nums, target, lo, mid-1);
}
// Same logic as iterative, but each call shrinks the range by half.
// Stack depth = O(log n) — much less than array sum which is O(n).