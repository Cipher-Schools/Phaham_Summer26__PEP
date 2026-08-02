// https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

stack<int>st;
stack<int>minSt;
MinStack() {
    
}

void push(int value) {
    st.push(value);
    minSt.push(minSt.empty()?value:min(value, minSt.top()));
}

void pop() {
    st.pop();
    minSt.pop();
}

int top() {
    return st.top();
}

int getMin() {
    return minSt.top();
}