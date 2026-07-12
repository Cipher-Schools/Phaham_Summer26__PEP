#include <bits/stdc++.h>
using namespace std;

// lc - 875

bool canFinish(vector<int>& piles, int k, int h) {
    long hours = 0;
    for (int pile : piles)
        hours += (pile + k - 1) / k;  // ceil(pile/k)
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1;
    int hi = *max_element(piles.begin(), piles.end());
    int ans = hi;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canFinish(piles, mid, h)) {
            ans = mid;      // mid works — try SLOWER (smaller)
            hi = mid - 1;
        } else {
            lo = mid + 1;  // mid too slow — go FASTER
        }
    }
    return ans;
}
// Answer range: lo=1, hi=max(piles)
// Feasibility: sum(ceil(pile/k)) <= h
// Minimizing → record mid and go left on success