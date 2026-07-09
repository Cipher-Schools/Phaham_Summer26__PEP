#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (x > rev) {           // stop when we've processed half
        rev = rev * 10 + x % 10; // build reverse digit by digit
        x /= 10;                 // shrink x from right
    }
    return x == rev || x == rev / 10;  // even length || odd length
}
// x=121: rev builds 1,12  x shrinks 12,1  → x==rev/10 → true
// x=1221: rev builds 1,12  x shrinks 122,12 → x==rev → true
// Time O(log n), Space O(1)