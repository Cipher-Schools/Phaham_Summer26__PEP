#include <bits/stdc++.h>
using namespace std;

// gfg
int floor(int arr[], int n, int target) {
    int lo=0, hi=n-1, ans=-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) {
            ans = mid;        // arr[mid] <= target, candidate for floor
            lo = mid + 1;    // try to find larger valid candidate
        } else {
            hi = mid - 1;
        }
    }
    return ans;  // index of floor, or -1 if no element <= target
}