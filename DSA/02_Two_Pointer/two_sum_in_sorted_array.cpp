#include <bits/stdc++.h>
using namespace std;

bool twoSum(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int sum = arr[lo] + arr[hi];
        if (sum == target) {
            cout << arr[lo] << " + " << arr[hi] << " = " << target;
            return true;
        } else if (sum < target) {
            lo++;   // sum too small, need bigger left number
        } else {
            hi--;   // sum too big, need smaller right number
        }
    }
    return false;
}