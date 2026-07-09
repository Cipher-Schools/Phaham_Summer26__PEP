#include <bits/stdc++.h>
using namespace std;

// lc - 704
int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size()-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target>nums[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

// Time:  O(log n) - halves the search space each step
// Space: O(1)     - just three int variables