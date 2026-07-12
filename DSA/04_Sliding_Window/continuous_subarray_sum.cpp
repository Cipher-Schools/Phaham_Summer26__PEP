// lc - 523

#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> remIndex;
    remIndex[0] = -1;    // remainder 0 at index "before the array"
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int rem = sum % k;
        if (remIndex.count(rem)) {
            if (i - remIndex[rem] >= 2) return true;  // length >= 2
        } else {
            remIndex[rem] = i;    // store FIRST occurrence only
        }
    }
    return false;
}
// Store FIRST occurrence of each remainder (not update it)
// This maximizes the gap i - remIndex[rem], so we find length >= 2 easier.