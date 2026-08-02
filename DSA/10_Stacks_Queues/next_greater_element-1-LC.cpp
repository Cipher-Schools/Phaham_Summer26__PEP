// https://leetcode.com/problems/next-greater-element-i/
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2  = nums2.size();
    unordered_map<int, int>mp;

    // stack<int>st;
    // vector<int>result;
    // for(int num: nums2){
    //     while(!st.empty() && num>st.top()){
    //         mp[st.top()] = num;
    //         st.pop();
    //     }
    //     st.push(num);
    // }
    // while(!st.empty()){
    //     mp[st.top()] = -1;
    //     st.pop();
    // }

    // backward traversal
    vector<int>result; // store NGE
    stack<int>st; 
    for(int i=n2-1;i>=0;i--){
        while(!st.empty() && nums2[i]>=st.top()) st.pop();
        st.empty()? mp[nums2[i]]=-1: mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    for(int i=0;i<n1;i++){
        result.push_back(mp[nums1[i]]);
    }
    return result;
}