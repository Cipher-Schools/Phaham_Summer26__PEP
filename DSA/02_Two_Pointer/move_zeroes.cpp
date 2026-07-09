#include <bits/stdc++.h>
using namespace std;

// lc 283
void moveZeroes(vector<int>& nums) {
    int j = 0;                      // write pointer
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];    // write non-zero at j, advance j
        }
    }
    while (j < nums.size())
        nums[j++] = 0;              // fill rest with zeros
}
// Time O(n), Space O(1) — in-place, two passes