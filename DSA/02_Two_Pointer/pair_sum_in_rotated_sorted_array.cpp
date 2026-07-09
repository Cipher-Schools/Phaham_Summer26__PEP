#include <bits/stdc++.h>
using namespace std;

// gfg
bool pairInRotated(int arr[], int n, int target) {
    // Find index of maximum element (pivot)
    int pivot = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[pivot]) pivot = i;
    
    int lo = (pivot + 1) % n;   // smallest element
    int hi = pivot;              // largest element
    
    while (lo != hi) {
        int sum = arr[lo] + arr[hi];
        if (sum == target) return true;
        else if (sum < target) lo = (lo + 1) % n;  // wrap around!
        else hi = (hi - 1 + n) % n;
    }
    return false;
}
// Time O(n), Space O(1)