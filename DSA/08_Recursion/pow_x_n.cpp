// lc - 50

double myPow(double x, long n) {
    if (n == 0) return 1.0;           // base case: x^0 = 1
    if (n < 0) return myPow(1/x, -n); // handle negative exponent
    if (n % 2 == 0)
        return myPow(x*x, n/2);       // x^n = (x²)^(n/2) — even
    else
        return x * myPow(x*x, n/2);   // x^n = x * (x²)^(n/2) — odd
}
// myPow(2, 8): 2^8 = (2²)^4 = (4)^4 = (16)^2 = 256 — 3 calls, not 8!
// Time O(log n), Space O(log n) call stack depth