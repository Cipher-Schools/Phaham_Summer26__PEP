#include <bits/stdc++.h>
using namespace std;

// brute force - O(m*n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}

// better - O(m+n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    // staircase - O(m+n)
    int row = 0, col = n-1;
    while(row<m && col >= 0){
        if(matrix[row][col] == target) return true;
        else if(target < matrix[row][col]) col--;
        else row++;
    }
    return false;
}

// optimal - log(m*n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int row = mid/n;
        int col = mid%n;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col]>target) end = mid-1;
        else start = mid+1;
    }
    return false;
}