#include <bits/stdc++.h>
using namespace std;

// lc - 26
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int j = 0;                           // last unique element position
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[j]) {        // found a new unique value
            nums[++j] = nums[i];         // write it next to last unique
        }
    }
    return j + 1;                        // count of unique elements
}
// [1,1,2,2,3]: j=0(1), skip 1, write 2→j=1, skip 2, write 3→j=2
// return 3. Array is now [1,2,3,2,3] — only first 3 elements matter
// Time O(n), Space O(1)