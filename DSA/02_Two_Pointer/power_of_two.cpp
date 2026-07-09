#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
// n=8:  1000 & 0111 = 0000 ✓ power of two
// n=6:  0110 & 0101 = 0100 ≠ 0 ✗ not power of two
// n=1:  0001 & 0000 = 0000 ✓ 2^0 = 1

// Loop version:
bool isPowerOfTwo_v2(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    return n == 1;
}