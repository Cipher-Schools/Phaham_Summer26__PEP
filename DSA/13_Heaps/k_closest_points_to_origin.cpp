// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
  priority_queue<pair<int, vector<int>>> max_heap; // {dist, coords}
  for (int i = 0; i < points.size(); i++)
  {
    int x = points[i][0];
    int y = points[i][1];
    int dist_sq = x * x + y * y;
    max_heap.push({dist_sq, {x, y}});
    if (max_heap.size() > k)
      max_heap.pop();
  }
  vector<vector<int>> result;
  while (!max_heap.empty())
  {
    result.push_back(max_heap.top().second);
    max_heap.pop();
  }
  return result;
}