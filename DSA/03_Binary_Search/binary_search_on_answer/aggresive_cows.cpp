// gfg

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls, int c, int minGap) {
    int cows = 1, lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minGap) {
            cows++;
            lastPos = stalls[i];
            if (cows == c) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int lo = 1;                                        // min possible gap
    int hi = stalls.back() - stalls.front();           // max possible gap
    int ans = -1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canPlace(stalls, c, mid)) {
            ans = mid;      // mid gap works — try LARGER
            lo = mid + 1;
        } else {
            hi = mid - 1;  // gap too large — reduce it
        }
    }
    return ans;
}
// Answer range: lo=1, hi=max_stall - min_stall
// Feasibility: can we place c cows with minimum gap >= mid?
// MAXIMIZING → go right on success (opposite of book allocation!)