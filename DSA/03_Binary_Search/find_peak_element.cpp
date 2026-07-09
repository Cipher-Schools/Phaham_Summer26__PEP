#include <bits/stdc++.h>
using namespace std;

// lc - 162
int findPeakElement(vector<int>& nums) {
    int lo=0, hi=nums.size()-1;
    while (lo < hi) {         // strict < because we compare mid with mid+1
        int mid = lo + (hi-lo)/2;
        if (nums[mid] < nums[mid+1])
            lo = mid + 1;     // ascending slope → peak is to the right
        else
            hi = mid;         // descending slope → peak is at mid or left
    }
    return lo;                // lo == hi, this is the peak
}
// The key insight: you don't need to find THE peak — find A peak.
// The slope direction tells you which side must contain one.