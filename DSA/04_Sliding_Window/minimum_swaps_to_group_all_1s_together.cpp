// lc - 1151
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int total_ones = count(nums.begin(), nums.end(), 1);
    if (total_ones == 0) return 0;
    
    int window_ones = 0;
    for (int i = 0; i < total_ones; i++)    // first window
        window_ones += nums[i];
    int max_ones = window_ones;
    
    for (int i = 1; i < n; i++) {           // slide the window
        window_ones += nums[(i + total_ones - 1) % n];  // enter from right (circular)
        window_ones -= nums[i - 1];                      // leave from left
        max_ones = max(max_ones, window_ones);
    }
    return total_ones - max_ones;  // zeros in the best window = swaps needed
}
// total_ones = window size (all 1s must fit in k slots)
// answer = k - max_ones_in_any_window_of_size_k
// The %n handles the circular wrap — key trick for all circular sliding window problems.