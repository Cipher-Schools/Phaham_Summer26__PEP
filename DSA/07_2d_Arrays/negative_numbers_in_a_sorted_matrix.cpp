#include<bits/stdc++.h>
using namespace std;

// lc - 1351

int negativeNumbers( vector<vector<int>>grid){
  int m = grid.size();
  int n = grid[0].size();
  int count = 0;
  int row = 0, col = n-1;
  while(row<m && col>=0){
    if(grid[row][col]<0){
      count += m-row;
      col--;
    }else{
      row++;
    }
  }
  return count;
}

int main(){
  vector<vector<int>>grid;
  return negativeNumbers(grid);
}