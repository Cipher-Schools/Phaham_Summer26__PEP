// https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

// With stack
string removeOuterParentheses(string s)
{
  stack<char>st;
  string result = "";
  for (char c : s)
  {
    if (c == '(')
    {
      if(!st.empty()) result+=c;
      st.push(c);
    }
    else
    {
      st.pop();
      if(!st.empty()) result+=c;
    }
  }
  return result;
}

// Without Stack
string removeOuterParentheses(string s)
{
  // stack<char>st;
  int depth = 0;
  string result = "";
  for (char c : s)
  {
    if (c == '(')
    {
      if (depth > 0)
        result += c;
      depth++;
    }
    else
    {
      depth--;
      if (depth > 0)
        result += c;
    }
  }
  return result;
}