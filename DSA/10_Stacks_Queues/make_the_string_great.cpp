// https://leetcode.com/problems/make-the-string-great/

#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{
  string result; // treat as a stack
  for (char c : s)
  {
    if (!result.empty() && abs(c - result.back()) == 32)
    {
      result.pop_back();
    }
    else
    {
      result.push_back(c);
    }
  }
  return result;
}