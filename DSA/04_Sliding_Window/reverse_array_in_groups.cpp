// gfg

#include <bits/stdc++.h>
using namespace std;

void reverseInGroups(int arr[], int n, int k) {
    for (int i = 0; i < n; i += k) {
        int lo = i;
        int hi = min(i + k - 1, n - 1);   // last group may be smaller
        while (lo < hi) {
            swap(arr[lo], arr[hi]);
            lo++; hi--;
        }
    }
}
// [1,2,3,4,5,6], k=2:
// i=0: reverse [0..1] → [2,1,...]
// i=2: reverse [2..3] → [...,4,3,...]
// i=4: reverse [4..5] → [...,6,5]
// Time O(n), Space O(1)
