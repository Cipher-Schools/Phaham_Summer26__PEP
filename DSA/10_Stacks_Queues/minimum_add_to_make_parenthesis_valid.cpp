// 921
#include <bits/stdc++.h>
using namespace std;

    int minAddToMakeValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c == '(') st.push(c);
            else{
                if(!st.empty() && st.top() == '(') st.pop(); //match found
                else st.push(c);
            }
        }
        return st.size();
    }



      int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for(char c:s){
            if(c == '(') open++;
            else{
                if(open>0) open--; //match found
                else close++;
            }
        }
        return open+close;
    }