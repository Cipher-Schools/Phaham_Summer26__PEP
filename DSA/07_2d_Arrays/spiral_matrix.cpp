// lc - 54

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int top=0, bottom=matrix.size()-1, left=0, right=matrix[0].size()-1;
    while (top <= bottom && left <= right) {
        for (int c=left; c<=right; c++) result.push_back(matrix[top][c]); top++;
        for (int r=top; r<=bottom; r++) result.push_back(matrix[r][right]); right--;
        if (top <= bottom)
            for (int c=right; c>=left; c--) result.push_back(matrix[bottom][c]); bottom--;
        if (left <= right)
            for (int r=bottom; r>=top; r--) result.push_back(matrix[r][left]); left++;
    }
    return result;
}
// Four moves: right along top row, down along right col,
//             left along bottom row, up along left col.
// After each move, shrink the corresponding boundary.
// Time O(m*n), Space O(1) extra