// https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;

// Without StringStream - Building string using loop
string simplifyPath(string path) {
    int n = path.size();
    vector<string>st;
    string result = "";
    int i = 0;
    while(i<n){
        while(i<n && path[i] == '/') i++;
        string temp = "";
        while(i<n && path[i]!='/'){
            temp += path[i];
            i++;
        }
        if(temp == ".."){
            if(!st.empty()) st.pop_back();
            continue;
        }
        if(temp == "." || temp == "") continue;
        else st.push_back(temp);
    }
    for(string s: st){
        result += "/" + s;
    }
    return result.empty() ?"/": result;
}

// With StringStream
string simplifyPath(string path) {
    int n = path.size();
    vector<string>st;
    string result = "";
    int i = 0;

    stringstream ss(path);
    string token = "";
    while(getline(ss, token, '/')){
        if(token == ".."){
            if(!st.empty()) st.pop_back();
            continue;
        }
        if(token == "." || token == ""){
            continue;
        }else{
            st.push_back(token);
        }
    }
    
    for(string s: st){
        result += "/" + s;
    }
    return result.empty() ?"/": result;
}