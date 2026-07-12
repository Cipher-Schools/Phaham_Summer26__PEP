// gfg

#include <bits/stdc++.h>
using namespace std;

vector<int> boundaryTraversal(vector<vector<int>>& mat) {
  int m = mat.size();
  int n = mat[0].size();
  
  vector<int>ans;
  // Top Row
  for(int i=0;i<n;i++){
      ans.push_back(mat[0][i]);
  }
  // Right Column 
  for(int i=1;i<m;i++){
      ans.push_back(mat[i][n-1]);
  }
  // bottom row, check row>1
  if(m>1){
      for(int i=n-2;i>=0;i--){
          ans.push_back(mat[m-1][i]);
      }
  }
  // left column, check >1 column
  if(n>1){
      for(int i=m-2;i>=1;i--){
          ans.push_back(mat[i][0]);
      }
  }
  return ans;
}