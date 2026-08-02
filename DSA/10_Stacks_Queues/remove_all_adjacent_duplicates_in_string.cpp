// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
  string res;
  int n = s.length();

  for (int i = 0; i < n; i++)
  {
    if (!res.empty() && res.back() == s[i])
    {
      res.pop_back();
    }
    else
    {
      res.push_back(s[i]);
    }
  }

  return res;
}