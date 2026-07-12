// lc - 1572

#include <bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size(), sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];           // main diagonal: row == col
        sum += mat[i][n-1-i];      // anti diagonal: row + col == n-1
    }
    if (n % 2 == 1)
        sum -= mat[n/2][n/2];      // center counted twice — subtract once
    return sum;
}
// For n=3: center is mat[1][1]. It's mat[1][1] (main) and mat[1][1] (anti). Subtract once.
// Time O(n), Space O(1)