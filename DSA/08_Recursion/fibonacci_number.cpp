// lc - 509

#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;           // base: fib(0)=0, fib(1)=1
    return fib(n-1) + fib(n-2);     // two recursive calls!
}
// fib(5) makes 15 calls. fib(40) makes ~330 million. EXPONENTIAL.
// Fix: memoize — cache results so fib(3) is computed ONCE, not multiple times.
int memo[100]; // fill with -1
int fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n-1) + fibMemo(n-2);
}
// With memoization: O(n) time, O(n) space — each value computed exactly once.