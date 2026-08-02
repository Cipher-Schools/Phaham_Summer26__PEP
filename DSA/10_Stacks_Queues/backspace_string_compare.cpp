// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>
using namespace std;

string processString(string str)
{
  string result = "";
  for (char c : str)
  {
    if (c == '#')
    {
      // if(result.empty()) continue;
      if (!result.empty())
        result.pop_back();
    }
    else
    {
      result.push_back(c);
    }
  }
  return result;
}

bool backspaceCompare(string s, string t)
{
  return processString(s) == processString(t);
}