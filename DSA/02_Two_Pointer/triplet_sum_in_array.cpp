#include <bits/stdc++.h>
using namespace std;

bool tripletSum(int arr[], int n, int target) {
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int sum = arr[i] + arr[lo] + arr[hi];
            if (sum == target) return true;
            else if (sum < target) lo++;
            else hi--;
        }
    }
    return false;
}

// Time O(n²), Space O(1)
// Pattern: fix one, two-pointer the rest - works for 3sum, 4sum too