// lc - 374

#include <bits/stdc++.h>
using namespace std;

int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int result = guess(mid);
        if (result == 0)  return mid;        // found it
        else if (result == 1) lo = mid + 1;  // too low
        else hi = mid - 1;                   // too high
    }
    return -1;
}
// Time O(log n) - at most log2(n) guesses needed
// This is the simplest template - the guess() API IS the feasibility check.
// For n=1000000, you find the number in at most 20 guesses. Not 1 million.