// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int>result(n, -1); //store NGE
    stack<int>st; 
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=st.top()) st.pop();
        if(!st.empty()) result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}