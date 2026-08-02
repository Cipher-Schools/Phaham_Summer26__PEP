// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
  priority_queue<pair<int, int>> max_heap; // {freq, value}
  unordered_map<int, int> mp;              // {value, freq}
  for (int num : nums)
    mp[num]++;
  for (auto it : mp)
  {
    max_heap.push({it.second, it.first});
  }
  vector<int> result;
  while (k--)
  {
    if (!max_heap.empty())
    {
      result.push_back(max_heap.top().second);
      max_heap.pop();
    }
  }
  return result;
}