#include<bits/stdc++.h>
using namespace std;

int maximumWealth( vector<vector<int>>accounts){
  int m = accounts.size();
  int n = accounts[0].size();
  int sum = 0, maxSum = 0;
  for(int i=0;i<m;i++){
    for(int i=0;i<n;i++){
      sum += accounts[i][j];
    }
    maxSum = max(maxSum, sum);
    sum = 0;
  }
}

int main(){
  vector<vector<int>>accounts;
  return maximumWealth(accounts);
}