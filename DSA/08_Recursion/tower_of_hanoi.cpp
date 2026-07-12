#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;                          // base: nothing to move
    hanoi(n-1, from, aux, to);                   // move n-1 to auxiliary peg
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n-1, aux, to, from);                   // move n-1 from aux to dest
}
// hanoi(3, 'A', 'C', 'B') makes 2^3 - 1 = 7 moves
// In general: 2^n - 1 moves. For n=64 (legend): 2^64 - 1 ≈ 18 quintillion moves!