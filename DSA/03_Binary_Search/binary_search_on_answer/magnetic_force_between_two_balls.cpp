// lc - 1552
#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& weights, int D, int capacity) {
    int days = 1, load = 0;
    for (int w : weights) {
        if (w > capacity) return false;
        if (load + w > capacity) { days++; load = w; }
        else load += w;
    }
    return days <= D;
}

int shipWithinDays(vector<int>& weights, int D) {
    int lo = *max_element(weights.begin(), weights.end()); // must carry heaviest
    int hi = accumulate(weights.begin(), weights.end(), 0); // carry all in 1 day
    int ans = hi;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShip(weights, D, mid)) {
            ans = mid; hi = mid - 1; // works, try smaller capacity
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
// Notice how identical this is to Book Allocation. The TEMPLATE is the same.
// Only canShip() differs from canAllocate(). Pattern recognition saves hours.
