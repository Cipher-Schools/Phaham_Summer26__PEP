// gfg

#include <bits/stdc++.h>
using namespace std;

int digitSum(int n) {
    if (n == 0) return 0;              // base case
    return n % 10 + digitSum(n / 10); // last digit + sum of rest
}
// digitSum(1234) = 4 + digitSum(123)
//                    = 3 + digitSum(12)
//                       = 2 + digitSum(1)
//                          = 1 + digitSum(0)
//                               = 0  ← base case
// Unwinds: 0→1→3→6→10