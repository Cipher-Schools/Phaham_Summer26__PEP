// lc - 560

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;    // empty prefix (sum=0) exists once
    int sum=0, count=0;
    for (int x : nums) {
        sum += x;
        // if (sum - k) appeared before, those subarrays end here with sum = k
        count += prefixCount[sum - k];
        prefixCount[sum]++;
    }
    return count;
}
// Key: if prefix[j] - prefix[i] = k, then subarray [i..j-1] has sum k
// → if (current_prefix - k) exists in map, there are subarrays ending here with sum k
// prefixCount[0]=1 handles subarrays starting from index 0