#include <bits/stdc++.h>
using namespace std;

// lc - 88
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;       // last real element of nums1
    int j = n - 1;       // last element of nums2
    int k = m + n - 1;   // last position in nums1 (the buffer)
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];  // place larger at end
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)          // remaining nums2 elements (if any)
        nums1[k--] = nums2[j--];
    // Note: if nums1 elements remain, they're already in place
}
// Time O(m+n), Space O(1) — in-place by filling from back