/*
The 4-step recipe - applies to every problem in this pattern
1 - Identify the answer range: what is the minimum possible answer? What is the maximum possible answer? This becomes your lo and hi.
2 - Write a feasibility function: given a candidate answer mid, can it work? This is the key creative step. The function should return true/false.
3 - Verify monotonicity: if mid works, does mid+1 also work (or mid-1)? This is what makes binary search valid - you need a clear direction.
4 - Binary search: when feasible, record answer and try smaller (if minimizing) or try larger (if maximizing). Standard lo/hi/mid loop.
*/

#include <bits/stdc++.h>
using namespace std;

/*
int lo = minPossibleAnswer, hi = maxPossibleAnswer;
int ans = -1;

while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    
    if (isFeasible(mid)) {
        ans = mid;          // mid works! record it.
        hi = mid - 1;       // try smaller (if MINIMIZING)
        // lo = mid + 1;    // try larger  (if MAXIMIZING)
    } else {
        lo = mid + 1;       // mid doesn't work, need bigger
        // hi = mid - 1;    // mid too big, need smaller
    }
}
return ans;
*/

// Every problem below is just plugging a different isFeasible() into this template.