#include <bits/stdc++.h>
using namespace std;

// gfg 

int maxSumSubarray(int arr[], int n, int k) {
    int windowSum = 0;
    for (int i=0; i<k; i++) windowSum += arr[i];  // first window
    int maxSum = windowSum;
    
    for (int i=k; i<n; i++) {
        windowSum += arr[i];       // add new right element
        windowSum -= arr[i-k];    // remove old left element
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
// [2,3,5,1,6,4], k=3
// window:  [2,3,5]=10 → [3,5,1]=9 → [5,1,6]=12 → [1,6,4]=11
// answer: 12
// Time O(n), Space O(1) - no nested loop needed!
