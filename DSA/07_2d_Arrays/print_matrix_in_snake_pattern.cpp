// gfg

#include <bits/stdc++.h>
using namespace std;

vector<int> snakePattern(vector<vector<int> > matrix) {
    // code here
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int>result;
    for(int row = 0;row<m;row++){
        if(row%2 == 0){
            for(int col=0;col<n;col++){
                result.push_back(matrix[row][col]);
            }
        }else{
            for(int col = n-1;col>=0;col--){
                result.push_back(matrix[row][col]);
            }
        }
    }
    return result;
}