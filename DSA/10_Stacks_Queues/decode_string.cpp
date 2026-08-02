// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int>num;
    stack<string>str;
    int currNum = 0;
    string currStr = "";
    for(char c: s){
        if(isdigit(c)){
            currNum = currNum*10 + (c - '0');
        }
        else if(c == '['){
            num.push(currNum);
            str.push(currStr);
            currNum = 0;
            currStr = "";
        }else if(c == ']'){
            int repeatCount = num.top();
            num.pop();
            string previousStr = str.top();
            str.pop();
            string repeatStr = "";
            for(int i=0;i<repeatCount;i++){
                repeatStr += currStr;
            }
            currStr = previousStr + repeatStr;
        }else{
            currStr += c;
        }
    }
    return currStr;
}