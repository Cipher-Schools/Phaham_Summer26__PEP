#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    // code here
    if(n == 0) return 0; // base case
    return n%10 + sumOfDigits(n/10); // recursive step
}


