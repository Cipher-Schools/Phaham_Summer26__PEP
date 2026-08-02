// https://leetcode.com/problems/relative-ranks/description/

#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
  priority_queue<pair<int, int>> max_heap;
  int n = score.size();
  for (int i = 0; i < n; i++)
  {
    max - heap.push({score[i], i});
  }
  int rank = 1;
  vector<string> result(n);
  while (!max_heap.empty())
  {
    auto top = max_heap.top();
    max_heap.pop();
    int score = top.first;
    int scoreIdx = top.second;
    if (rank == 1)
      result[scoreIdx] = "Gold Medal";
    else if (rank == 2)
      result[scoreIdx] = "Silver Medal";
    else if (rank == 3)
      result[scoreIdx] = "Bronze Medal";
    else
      result[scoreIdx] = to_string(rank);
    rank++;
  }
  return result;
}
