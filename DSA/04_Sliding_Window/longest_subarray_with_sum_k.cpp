#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k) {
    int lo=0, sum=0, maxLen=0;
    for (int hi=0; hi<n; hi++) {
        sum += arr[hi];                   // expand window to the right
        while (sum > k && lo <= hi) {    // condition violated
            sum -= arr[lo++];             // shrink from left
        }
        maxLen = max(maxLen, hi - lo + 1);
    }
    return maxLen;
}
// [1,2,1,3,2,1], k=4
// hi=0: sum=1, window=[1], len=1
// hi=1: sum=3, window=[1,2], len=2
// hi=2: sum=4, window=[1,2,1], len=3
// hi=3: sum=7>4, shrink: remove 1→sum=6, remove 2→sum=4, window=[1,3], len=2
// hi=4: sum=6>4, shrink: remove 1→sum=5, remove 3→sum=2, window=[2], len=1... wait
// Final answer: 3
// Time O(n) - lo and hi each move at most n steps total
