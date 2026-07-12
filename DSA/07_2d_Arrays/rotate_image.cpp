// lc - 48

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Step 1: Transpose (swap matrix[r][c] with matrix[c][r])
    for (int r=0; r<n; r++)
        for (int c=r+1; c<n; c++)
            swap(matrix[r][c], matrix[c][r]);
    // Step 2: Reverse each row
    for (auto& row : matrix)
        reverse(row.begin(), row.end());
}
// Why it works: rotating 90° CW = transpose + reverse rows
// Rotating 90° CCW = transpose + reverse columns (or reverse rows + transpose)
// Time O(n²), Space O(1) - truly in-place