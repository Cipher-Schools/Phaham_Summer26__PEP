// https://leetcode.com/problems/online-stock-span/
#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>>st;
StockSpanner() {
}

int next(int price) {
    int span = 1;
    while(!st.empty() && price >= st.top().first){
        span += st.top().second;
        st.pop();
    }
    st.push({price, span});
    return span;
}