// lc - 1343

#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int minSum = k * threshold, sum = 0, count = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    if (sum >= minSum) count++;
    for (int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i-k];
        if (sum >= minSum) count++;
    }
    return count;
}
// Time O(n), Space O(1)
// Key: avoid float by converting "avg >= threshold" to "sum >= k*threshold"