// https://leetcode.com/problems/longest-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    stack<int>st;
    int maxLen = 0;
    st.push(-1);
    for(int i=0;i<s.length();i++){
        if(s[i] == '(') st.push(i);
        else{
            st.pop();
            if(st.empty()) st.push(i);
            else maxLen = max(maxLen, i - st.top());
        }
    }
    return maxLen;
}