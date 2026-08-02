// https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
  unordered_map<char, int> mp;
  for (char c : s)
  {
    mp[c]++;
  }
  priority_queue<pair<int, char>> max_heap;
  for (auto it : mp)
  {
    max_heap.push({it.second, it.first});
  }
  string result = "";
  while (max_heap.size() >= 2)
  {
    auto [cnt1, c1] = max_heap.top();
    max_heap.pop();
    auto [cnt2, c2] = max_heap.top();
    max_heap.pop();
    result += c1;
    result += c2;
    if (cnt1 - 1 > 0)
      max_heap.push({cnt1 - 1, c1});
    if (cnt2 - 1 > 0)
      max_heap.push({cnt2 - 1, c2});
  }
  while (!max_heap.empty())
  {
    auto [cnt, c] = max_heap.top();
    max_heap.pop();
    if (cnt > 1)
      return "";
    else
      result += c;
  }
  return result;
}